// Copyright 2022 NNTU-CS
#include "tpqueue.h"

struct SYM {
    char ch;
    int prior;
    SYM(char c, int p) : ch(c), prior(p) {}
};

int main() {
    TPQueue<SYM> pqueue;
    pqueue.push(SYM('a', 4));
    pqueue.push(SYM('b', 7));
    SYM c1 = pqueue.pop();
    SYM c2 = pqueue.pop();
    return 0;
}
