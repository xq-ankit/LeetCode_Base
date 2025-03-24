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

//  balanced binary tree means for every node height[left]-height[right]<=1;
class Solution {
public:

    bool isBalanced(TreeNode* root) {
        return depth(root) !=-1;
    }
    int depth(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left_count= depth(root->left);
        int right_count=depth(root->right);
        if(left_count==-1 || right_count==-1) return -1;
        if(abs(left_count-right_count)>1) return -1;
        return max(left_count,right_count)+1;
    }
};