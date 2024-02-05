/*

Author : Shashvat Tiwari
Date : 07/10/2023
Problem : Pairwise swap elements of a linked list
Difficulty : Easy
Problem Link :https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
Video Solution : NA

*/

class Solution
{
public:
    Node *pairWiseSwap(struct Node *head)
    {
        // Check if the list is empty or has only one node
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Initialize pointers for swapping
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        int count = 0;

        // Traverse and swap pairs of nodes
        while (curr != NULL && count < 2)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively call pairWiseSwap on the remaining list
        if (next != NULL)
        {
            head->next = pairWiseSwap(next);
        }

        // 'prev' is the new head of the swapped pairs
        return prev;
    }
};
