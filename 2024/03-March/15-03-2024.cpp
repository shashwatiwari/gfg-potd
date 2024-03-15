/*

Author : Shashvat Tiwari
Date : 15/03/2024
Problem : Linked that is sorted alternatingly
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1
Video Solution : NA

-------------------------------------------------------------------------------------


Approach:
    Split the List: First, we need to split the linked list into two halves. We can do this using a slow and fast
    pointer approach. The slow pointer moves one step at a time while the fast pointer moves two steps at a time.
    When the fast pointer reaches the end of the list, the slow pointer will be at the middle of the list. We split the list at this point.

    Merge Sort: We recursively sort the two halves of the list using the merge sort algorithm.
    This involves splitting each half further until we reach single nodes, which are inherently sorted.

    Merge the Halves: Once we have sorted halves, we merge them back together in a sorted manner.
    We compare the values of the nodes in the two halves, starting from the heads of each half, and merge them into a new sorted list.

    Update the Head: Finally, we update the head of the original linked list to point to the head of the sorted list.

Code Explanation:
    split(Node head, Node* front, Node** back):** This function splits the linked list into two halves.
    It uses the slow and fast pointer approach to find the middle of the list and splits it at that point.

    merge(Node a, Node b):** This function merges two sorted linked lists a and b into a single sorted linked list.
    It compares the values of the nodes in a and b and merges them accordingly.

    sort(Node headRef):** This is the main function that sorts the linked list. It recursively splits the list
    into halves, sorts the halves, and then merges them back together. It updates the head of the original linked list to point to the sorted list.

    Time Complexity:
    The time complexity of this approach is O(n log n), where n is the number of nodes in the linked list.
    This is because merge sort has a time complexity of O(n log n), and each call to split and merge functions takes O(n) time.

    Space Complexity:
    The space complexity of this approach is O(log n), where n is the number of nodes in the linked list.
    This is because the recursion depth of the sort function is O(log n) due to the recursive splitting of the list.


*/

class Solution
{
public:
    void split(Node *head, Node **front, Node **back)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != nullptr)
        {
            fast = fast->next;
            if (fast != nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = head;
        *back = slow->next;
        slow->next = nullptr;
    }

    Node *merge(Node *a, Node *b)
    {
        Node dummy(-1);
        Node *tail = &dummy;
        dummy.next = nullptr;

        while (a != nullptr && b != nullptr)
        {
            if (a->data <= b->data)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = (a != nullptr) ? a : b;

        return dummy.next;
    }

    void sort(Node **headRef)
    {
        Node *head = *headRef;
        Node *a;
        Node *b;

        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        split(head, &a, &b);

        sort(&a);
        sort(&b);

        *headRef = merge(a, b);
    }
};