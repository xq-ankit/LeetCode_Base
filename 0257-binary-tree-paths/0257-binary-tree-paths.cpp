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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        path(root,"",ans);
        return ans;
    }
    void path(TreeNode* root,string temp,vector<string>&ans){
           if(!isLeafnode(root))temp+=to_string(root->val)+"->";
           else temp+=to_string(root->val);
            if(isLeafnode(root)){
                ans.push_back(temp);
                return;
            }
            if(root->left) path(root->left,temp,ans);
            if(root->right) path(root->right,temp,ans);
    }
    bool isLeafnode(TreeNode* root){
        return root->left==nullptr && root->right==nullptr;
    }
};