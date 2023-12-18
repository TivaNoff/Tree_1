#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;

        return (p->val == q->val) &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);
    }
};

// Helper function to create a binary tree from an array
TreeNode* createTree(const vector<int>& values, int index) {
    if (index >= values.size() || values[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);

    return root;
}

int main() {
    Solution solution;

    // Example 1
    vector<int> p1 = { 1, 2, 3 };
    vector<int> q1 = { 1, 2, 3 };
    TreeNode* treeP1 = createTree(p1, 0);
    TreeNode* treeQ1 = createTree(q1, 0);
    cout << "Example 1: " << (solution.isSameTree(treeP1, treeQ1) ? "true" : "false") << endl;

    // Example 2
    vector<int> p2 = { 1, 2 };
    vector<int> q2 = { 1, -1, 2 };
    TreeNode* treeP2 = createTree(p2, 0);
    TreeNode* treeQ2 = createTree(q2, 0);
    cout << "Example 2: " << (solution.isSameTree(treeP2, treeQ2) ? "true" : "false") << endl;

    // Example 3
    vector<int> p3 = { 1, 2, 1 };
    vector<int> q3 = { 1, 1, 2 };
    TreeNode* treeP3 = createTree(p3, 0);
    TreeNode* treeQ3 = createTree(q3, 0);
    cout << "Example 3: " << (solution.isSameTree(treeP3, treeQ3) ? "true" : "false") << endl;

    return 0;
}
