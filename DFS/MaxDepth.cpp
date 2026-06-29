/*
 * LeetCode 104: Maximum Depth of Binary Tree
 * 
 * Problem: Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path 
 * from the root node down to the farthest leaf node.
 * 
 * Time Complexity: O(n) - visit each node once
 * Space Complexity: O(h) - recursion stack for height of tree
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: null node has depth 0
        if (!root) return 0;
        
        // Recursively get max depth of left and right subtrees
        int leftSubtreeDepth = maxDepth(root->left);
        int rightSubtreeDepth = maxDepth(root->right);
        
        // Return 1 + max of both subtrees
        return 1 + max(leftSubtreeDepth, rightSubtreeDepth);
    }
};

// Test cases
int main() {
    Solution sol;
    
    // Test case 1: Balanced tree
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    
    cout << "Test 1 (Balanced tree) - Expected: 3, Got: " << sol.maxDepth(root1) << endl;
    
    // Test case 2: Linear tree (one-sided)
    //     2
    //      \
    //       3
    //        \
    //         4
    TreeNode* root2 = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(4);
    
    cout << "Test 2 (Linear tree) - Expected: 3, Got: " << sol.maxDepth(root2) << endl;
    
    // Test case 3: Single node
    TreeNode* root3 = new TreeNode(1);
    
    cout << "Test 3 (Single node) - Expected: 1, Got: " << sol.maxDepth(root3) << endl;
    
    // Test case 4: Empty tree
    cout << "Test 4 (Empty tree) - Expected: 0, Got: " << sol.maxDepth(nullptr) << endl;
    
    return 0;
}
