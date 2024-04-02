/*

Author : Shashvat Tiwari
Date : 16/03/2024
Problem : Delete Without Head Pointer
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1
Video Solution : NA

-------------------------------------------------------------------------------------

In this implementation, del_node is the node to be deleted. We copy the value of del_node's next node to del_node,
then update del_node's next pointer to skip the next node, and finally delete the next node.

This approach has a time complexity of O(1) because it only requires a constant number of operations,
regardless of the size of the linked list.


*/

class Solution
{
public:
    void deleteNode(Node *del_node)
    {
        Node *temp = del_node->next;
        del_node->data = temp->data;
        del_node->next = temp->next;
        delete temp;
    }
};