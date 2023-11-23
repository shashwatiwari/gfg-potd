/*

Author : Shashvat Tiwari
Date : 23/11/2023
Problem : AVL Tree Insertion
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/avl-tree-insertion/1
Video Solution : NA


Approach:
Insertion: Begin with the regular BST insertion algorithm for AVL trees.

Balancing: After each insertion, check the balance factor of each node
 in the path traversed during insertion.

Rotations: Perform rotations (LL, RR, LR, RL) if the balance factor
becomes greater than 1 or less than -1, which violates the AVL property.
Inorder Traversal: Perform an inorder traversal of the tree after each
insertion, checking for any violations in the tree's balance. If there's
a violation, print an error message followed by the current state of the
tree's inorder traversal.

*/

#include <iostream>
#include <algorithm>
using namespace std;

// Structure for a node in AVL Tree
struct Node
{
    int data;
    Node *left, *right;
    int height;
};

class Solution
{
public:
    // Function to get the height of a node
    int getHeight(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    // Function to get the balance factor of a node
    int getBalance(Node *node)
    {
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right rotation function
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    // Left rotation function
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Function to insert a node into AVL tree
    Node *insertToAVL(Node *node, int data)
    {
        if (node == NULL)
        {
            return (new Node(data));
        }

        // Perform regular BST insertion
        if (data < node->data)
        {
            node->left = insertToAVL(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insertToAVL(node->right, data);
        }
        else
        {
            // Duplicate keys are not allowed in AVL trees
            return node;
        }

        // Update height of this node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get the balance factor of this node
        int balance = getBalance(node);

        // Perform rotations if needed to maintain AVL property

        // Left Left Case (LL)
        if (balance > 1 && data < node->left->data)
        {
            return rightRotate(node);
        }

        // Right Right Case (RR)
        if (balance < -1 && data > node->right->data)
        {
            return leftRotate(node);
        }

        // Left Right Case (LR)
        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case (RL)
        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Function to perform inorder traversal of the tree
    void inorderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        // Traverse left subtree
        inorderTraversal(root->left);

        // Print the current node's data
        cout << root->data << " ";

        // Traverse right subtree
        inorderTraversal(root->right);
    }
};

// Main function for testing the AVL tree insertion
int main()
{
    Solution solution;
    Node *root = NULL;
    int N = 7;
    int values[] = {21, 26, 30, 9, 4, 14, 28};

    // Insert values one by one and print inorder traversal after each insertion
    for (int i = 0; i < N; ++i)
    {
        root = solution.insertToAVL(root, values[i]);
        solution.inorderTraversal(root);
        cout << endl;
    }

    return 0;
}
