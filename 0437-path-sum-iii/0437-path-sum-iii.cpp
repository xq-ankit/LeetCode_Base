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
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return 0;
        }
        int c=countpath(root,targetSum,0);
        int left=pathSum(root->left,targetSum);
        int right=pathSum(root->right,targetSum);
        return c+left+right;
    }


    int countpath(TreeNode* root,int targetSum,long sum){
        if(root==nullptr){
            return 0;
        }
        int c=0;
        if((sum+=root->val)==targetSum){
            c++;
        }
        int left=countpath(root->left,targetSum,sum);
        int right=countpath(root->right,targetSum,sum);
        return left+right+c;
    }
};