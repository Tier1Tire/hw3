#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == NULL)
    {
        smaller = NULL;
        larger = NULL;
        return;
    }

    // Save this node and recursively split the remaining list.
    Node* current = head;
    head = head->next;
    llpivot(head, smaller, larger, pivot);

    // Place this earlier node before the nodes from the remaining list.
    if (current->val <= pivot)
    {
        current->next = smaller;
        smaller = current;
    }
    else
    {
        current->next = larger;
        larger = current;
    }
}
