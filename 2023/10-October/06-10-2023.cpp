/*

Author : Shashvat Tiwari
Date : 06/10/2023
Problem : Reverse alternate nodes in Link List
Difficulty : Medium
Problem Link :https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1
Video Solution : NA

*/

class Solution
{
public:
    void insert()
    {
        int n, value;
        cin >> n;
        struct Node *temp;
        for (int i = 0; i < n; i++)
        {
            cin >> value;
            if (i == 0)
            {
                start = new Node(value);
                temp = start;
                continue;
            }
            else
            {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }
    }

    void printList(struct Node *node)
    {
        while (node != NULL)
        {
            cout << node->data;
            node = node->next;
        }
        cout << endl;
    }

    void rearrange(struct Node *odd)
    {
        struct Node *even = odd;
        struct Node *revOdd = NULL;
        struct Node *itr = odd;
        while (itr)
        {
            struct Node *nextItr = itr->next;
            if (nextItr)
            {
                even->next = itr->next->next;
                if (even->next)
                    even = even->next;
                nextItr->next = revOdd;
                revOdd = nextItr;
            }
            else
                break;
            itr = even;
        }
        even->next = revOdd;
    }
};
