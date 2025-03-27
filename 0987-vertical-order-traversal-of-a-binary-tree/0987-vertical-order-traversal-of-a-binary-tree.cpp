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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes; // {x: {y: {values}}}
    queue<pair<TreeNode*, pair<int, int>>> q; // {node, {x, y}}

    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* curr = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(curr->val);

        if (curr->left) {
            q.push({curr->left, {x - 1, y + 1}});
        }
        if (curr->right) {
            q.push({curr->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto& p : nodes) {
        vector<int> level;
        for (auto& q : p.second) {
            level.insert(level.end(), q.second.begin(), q.second.end());
            // insert allows inserting multiple elements at once
            // insert(position, first, last) takes a range of iterators and appends them to the vector.
            // q.second is a multiset<int>, so q.second.begin() to q.second.end() gives an ordered range
            // of values.
        }
        ans.push_back(level);
    }

    return ans;
}

};