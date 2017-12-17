#ifndef _listlib_H_
#define _listlib_H_
#include <stdio.h>
#include <stdlib.h>


typedef int T;
class List

{
    public:
    struct Node
    {
        T data;
        Node* next = NULL;
        Node* prev = NULL;
    };
    Node*   head = NULL;
    Node*   tail = NULL;
    void    NodeDelete        (Node* nd);
    void    ListDump          ();
    Node*   NodeInsert        (T value);
    Node*   NodeInsertAfter   (Node * nd_last, T value);
    Node*   NodeInsertBefore  (Node* nd_next, T value);
    T       NodeGetData       (Node * nd);
    Node*   NodeGetNext       (Node * nd);
    int     DotDump          ();

};

//#include "dot.h"
#include "list.cpp"
#endif
