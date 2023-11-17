/*

Author : Shashvat Tiwari
Date : 17/11/2023
Problem : Binary Tree To CDLL
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1
Video Solution : NA


### Approach:

1. **`convertToCDLLUtil` Function**:
   - This function recursively converts the binary tree into a CDLL.
   - It takes a `Node* root` as input and returns the head of the CDLL formed from the subtree rooted at `root`.

2. **Base Case**:
   - If the `root` is null, return `nullptr` as there's no CDLL to form.

3. **Recursion**:
   - For each node in the binary tree, the function first recursively processes its left and right subtrees.
   - It gets the CDLL head and tail of the left subtree and right subtree respectively.

4. **Handling Left Subtree**:
   - If the current node has a left subtree:
     - Set `leftHead` and `leftTail` pointers to the head and tail of the CDLL formed from the left subtree.
     - If `leftTail` exists:
       - Connect `leftTail->right` to the current `root` node and `root->left` to `leftTail`.
     - If `leftTail` doesn't exist, set `leftHead` to the `root` itself.

5. **Handling Right Subtree**:
   - If the current node has a right subtree:
     - Set `rightHead` and `rightTail` pointers to the head and tail of the CDLL formed from the right subtree.
     - If `rightHead` exists:
       - Connect `rightHead->left` to the current `root` node and `root->right` to `rightHead`.
     - If `rightHead` doesn't exist, set `rightTail` to the `root` itself.

6. **Connecting the CDLL**:
   - Connect the left subtree's CDLL to the current `root` node and the right subtree's CDLL.
   - Connect `leftHead->left` to `rightTail` and `rightTail->right` to `leftHead`, making the CDLL circular.

7. **Return**:
   - Return the `leftHead`, which represents the head of the CDLL formed from the entire subtree rooted at `root`.

8. **`bTreeToCList` Function**:
   - This function acts as a driver function, calling `convertToCDLLUtil` with the root of the binary tree.
   - It returns the head of the CDLL formed from the entire binary tree.
*/

Node *convertToCDLLUtil(Node *root)
{
    if (!root)
        return nullptr;

    Node *leftHead, *leftTail, *rightHead, *rightTail;
    leftHead = leftTail = rightHead = rightTail = nullptr;

    if (root->left)
    {
        auto leftList = convertToCDLLUtil(root->left);
        leftHead = leftList;
        leftTail = leftList->left;
    }
    if (root->right)
    {
        auto rightList = convertToCDLLUtil(root->right);
        rightHead = rightList;
        rightTail = rightList->left;
    }
    if (leftTail)
    {
        leftTail->right = root;
        root->left = leftTail;
    }
    else
    {
        leftHead = root;
    }
    if (rightHead)
    {
        rightHead->left = root;
        root->right = rightHead;
    }
    else
    {
        rightTail = root;
    }
    leftHead->left = rightTail;
    rightTail->right = leftHead;
    return leftHead;
}

Node *bTreeToCList(Node *root)
{
    if (!root)
        return nullptr;
    Node *head = convertToCDLLUtil(root);
    return head;
}
