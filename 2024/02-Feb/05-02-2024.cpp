/*

Author : Shashvat Tiwari
Date : 05/02/2024
Problem : Sorted Insert for Circular Linked List
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1
Video Solution : NA

*/

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to insert a new node in sorted order in a circular linked list
Node *sortedInsert(Node *head, int x)
{
    Node *new_node = new Node(x);

    // If the list is empty, make the new node as the head and return it
    if (!head)
    {
        new_node->next = new_node;
        return new_node;
    }

    Node *temp = head;
    Node *prev = NULL;

    // Traverse the list to find the correct position to insert the new node
    do
    {
        prev = temp;
        temp = temp->next;

        // Check if the new node should be inserted between prev and temp
        if (x <= temp->data && x >= prev->data)
            break;

        // Check if the new node should be inserted at the end of the list
        if ((prev->data > temp->data) && (x <= temp->data || x >= prev->data))
            break;
    } while (temp != head);

    // Insert the new node between prev and temp
    prev->next = new_node;
    new_node->next = temp;

    // Update the head if the new node is inserted at the beginning
    if (x < head->data)
        head = new_node;

    return head;
}

// Function to print the circular linked list
void printList(Node *head)
{
    if (!head)
        return;

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

// Driver code
int main()
{
    int n, data;
    cout << "Enter the number of nodes in the circular linked list: ";
    cin >> n;

    Node *head = NULL;

    cout << "Enter the circular linked list values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        head = sortedInsert(head, data);
    }

    cout << "Enter the data to be inserted in sorted order: ";
    cin >> data;

    head = sortedInsert(head, data);

    cout << "Modified Circular Linked List: ";
    printList(head);

    return 0;
}
