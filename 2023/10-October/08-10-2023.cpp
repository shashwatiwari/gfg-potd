/*

Author : Shashvat Tiwari
Date : 08/10/2023
Problem : Insert in a Sorted List
Difficulty : Easy
Problem Link :https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
Video Solution : NA

*/

class Solution
{
public:
    // Definition for singly-linked list.
    struct Node
    {
        int data;
        Node *next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node *sortedInsert(Node *head, int data)
    {
        Node *newNode = new Node(data);

        if (!head || data < head->data)
        {
            // If the list is empty or data is smaller than the head, insert at the beginning.
            newNode->next = head;
            head = newNode;
            return head;
        }

        Node *current = head;

        // Find the appropriate position to insert the new node while maintaining sorted order.
        while (current->next && current->next->data < data)
        {
            current = current->next;
        }

        // Insert the new node after the current node.
        newNode->next = current->next;
        current->next = newNode;

        return head;
    }
};
