#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int T;

void List::NodeDelete (Node* nd)
{
    assert (this);
    assert (nd);

    if (nd == head)
        head = nd->next;
    if (nd == tail)
        tail = nd->prev;
    if (nd != head && nd != tail)
    {
        (nd->prev)->next = nd->next;
        (nd->next)->prev = nd->prev;
    }
    delete (nd);
};

List::Node* List::NodeInsert (T value)
{
    assert (this);

    Node* nd;
    nd = new Node;
    if (head == NULL)
    {
        head = nd;
        tail = nd;
    }
    else
    {
        tail->next = nd;
        nd->prev = tail;
        tail = nd;
    };
    nd->data = value;
    return nd;
};

List::Node* List::NodeInsertAfter (Node * nd_prev, T value)
{
    assert (this);
    assert (nd_prev);

    Node* nd;
    nd = new Node;
    if (nd_prev == tail)
    {
        tail = nd;
        nd->prev = nd_prev;
        nd_prev->next = nd;
    }
    else
    {
        nd->prev = nd_prev;
        nd->next = nd_prev->next;
        (nd_prev->next)->prev = nd;
        nd_prev->next = nd;
    }
    nd->data = value;
    return nd;
};

List::Node* List::NodeInsertBefore (Node* nd_next, T value)
{
    assert (this);
    assert (nd_next);

    Node* nd;
    nd = new Node;
    if (nd_next == head)
    {
        head = nd;
        nd->next = nd_next;
        nd_next->prev = nd;
    }
    else
    {
        nd->next = nd_next;
        nd->prev = nd_next->prev;
        (nd_next->prev)->next = nd;
        nd_next->prev = nd;
    }
    nd->data = value;
    return nd;
};

T List::NodeGetData (Node * nd)
{
    assert (this);
    assert (nd);

    return (nd->data);
};

List::Node* List::NodeGetNext (Node * nd)
{
    assert (this);
    assert (nd);
    return (nd->next);
};

void List::ListDump ()
{
    assert (this);

    List::Node* nd;
    nd = head;
    if (nd == NULL)
        printf ("List clear\n");
    else
    {
        printf ("Node   Node ptr     Last ptr     Nd value   Next ptr\n");
        printf ("head   0x%p   0x%p   %8d   0x%p\n\n\n", head, head->prev, head->data, head->next);
        while (nd != NULL)
        {
            printf ("       0x%p   0x%p   %8d   0x%p\n", nd, nd->prev, nd->data, nd->next);
            nd = nd->next;
        };
        printf ("\n\ntail   0x%p   0x%p   %8d   0x%p\n", tail, tail->prev, tail->data, tail->next);
    }
};

int List::DotDump ()
{
    assert (this);

    List::Node* nd = head;
    FILE* file = fopen ("graph_dump.txt", "w");
    fprintf (file, "digraph G{\n");
    fprintf (file, "rankdir = LR\n");
    fprintf (file, "info [shape = record, style = rounded, color = blue, label = \" <head_ptr> Head = 0x%p | <tail_ptr> Tail = 0x%p \"]", head, tail);
    fprintf (file, "%d [shape = record, style = rounded, color = blue, label = \"<pointer> Pointer: 0x%p | <data> Data: %d | {<prev> Prev: 0x%p | <next> Next: 0x%p}\"]\n", nd, nd, nd->data, nd->prev, nd->next);
    fprintf (file, "info:<head> -> %d:<data>[color = grey]\n", nd);

    do
    {
        nd = nd->next;
        fprintf (file, "%d [shape = record, style = rounded, color = blue, label = \"<pointer> Pointer: 0x%p | <data> Data: %d | {<prev> Prev: 0x%p | <next> Next: 0x%p}\"]\n", nd, nd, nd->data, nd->prev, nd->next);
        fprintf (file, "%d:<next> -> %d:<data>[color = blue]\n", nd->prev, nd);
        fprintf (file, "%d:<prev> -> %d:<data>[color = blue]\n", nd, nd->prev);


    }
    while (nd->next);
    fprintf (file, "}");
    fclose (file);
    system ("C:\\Progtam\\bin\\dot.exe -Tpng C:\\Programs\\List\\graph_dump.txt -o C:\\Programs\\List\\dump.png");
    system ("del graph_dump.txt");
    system ("dump.png");

    return 0;
}





