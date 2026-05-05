// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;

    explicit Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
  };

  Node* head;

 public:
  TPQueue() : head(nullptr) {}

  ~TPQueue() {
    while (head) {
      Node* tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  TPQueue(const TPQueue&) = delete;
  TPQueue& operator=(const TPQueue&) = delete;

  void push(const T& value) {
    Node* newNode = new Node(value);

    if (head == nullptr || value.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
      return;
    }

    Node* current = head;
    while (current->next != nullptr &&
           current->next->data.prior >= value.prior) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }

  T pop() {
    if (head == nullptr) {
      throw std::runtime_error("TPQueue::pop() on empty queue");
    }
    Node* tmp = head;
    T result = head->data;
    head = head->next;
    delete tmp;
    return result;
  }

  bool empty() const {
    return head == nullptr;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
