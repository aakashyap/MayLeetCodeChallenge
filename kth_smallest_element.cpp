/*

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

 

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //solution 1 : not fast enough
    /*void inorder(TreeNode* root,vector<int>& sorted) {
        if (root != nullptr) {
            inorder(root->left,sorted);
            sorted.push_back(root->val);
            inorder(root->right,sorted);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return -1;
        vector<int> sorted;
        inorder(root,sorted);
        return sorted[k-1];
    }*/
    stack<TreeNode*> s;
    int kthSmallest(TreeNode* root, int k) {
        while(true) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            --k;
            TreeNode* temp = s.top();
            s.pop();
            if (k == 0) return temp->val;
            root = temp->right;
        }
    }
};