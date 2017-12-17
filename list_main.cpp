#include "listlib.h"
int main()
{
    List lst;
    lst.NodeInsert (5);
    lst.NodeInsertAfter (lst.head, 6);
    lst.NodeInsert  (89);
    List::Node* nd = lst.NodeInsert  (8);
    lst.NodeInsert  (9);
    lst.NodeInsertBefore (lst.tail, 666);
    lst.NodeInsert  (189);
    lst.NodeDelete  (nd);
    lst.NodeInsert  (895);
    lst.NodeInsert  (879);
    lst.ListDump();
    lst.DotDump();
}
