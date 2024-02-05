/*

Author : Shashvat Tiwari
Date : 21/11/2023
Problem : Determine if Two Trees are Identical
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
Video Solution : NA

*/

class Solution
{
public:
    bool isIdentical(Node *r1, Node *r2)
    {
        if (r1 == nullptr && r2 == nullptr)
            return true;

        if (r1 == nullptr || r2 == nullptr)
            return false;

        return (r1->data == r2->data) &&
               isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }
};