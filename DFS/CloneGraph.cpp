/*
 * LeetCode 133: Clone Graph
 * 
 * Problem: Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph. Each node in the graph contains 
 * a value (int) and a list of its neighbors.
 * 
 * Approach: Use DFS with a hash map to track visited nodes during cloning.
 * For each node, create a copy and recursively clone all neighbors.
 * 
 * Time Complexity: O(N + E) - N nodes, E edges
 * Space Complexity: O(N) - hash map to store cloned nodes
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> visited;
    
    Node* dfs(Node* node) {
        // Base case: null node
        if (!node) return nullptr;
        
        // If already cloned, return the clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        // Create a clone of current node
        Node* clone = new Node(node->val);
        visited[node] = clone;
        
        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }
        
        return clone;
    }

public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};

// Helper function to print graph (BFS traversal)
void printGraph(Node* node) {
    if (!node) {
        cout << "Empty graph\n";
        return;
    }
    
    unordered_map<Node*, bool> visited;
    vector<Node*> queue;
    queue.push_back(node);
    visited[node] = true;
    
    while (!queue.empty()) {
        Node* current = queue.front();
        queue.erase(queue.begin());
        
        cout << "Node " << current->val << ": neighbors = ";
        for (Node* neighbor : current->neighbors) {
            cout << neighbor->val << " ";
            if (visited.find(neighbor) == visited.end()) {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
        cout << "\n";
    }
}

// Test cases
int main() {
    Solution sol;
    
    // Test case 1: Small graph [[2,4],[1,3],[2,4],[1,3]]
    //     1 --- 2
    //     |     |
    //     4 --- 3
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};
    
    cout << "Original Graph:\n";
    printGraph(node1);
    
    Node* cloned = sol.cloneGraph(node1);
    cout << "\nCloned Graph:\n";
    printGraph(cloned);
    cout << "\n";
    
    // Test case 2: Single node with self-loop
    Node* single = new Node(1);
    single->neighbors = {single};
    
    cout << "Original Single Node with Self-loop:\n";
    printGraph(single);
    
    Node* clonedSingle = sol.cloneGraph(single);
    cout << "\nCloned Single Node:\n";
    printGraph(clonedSingle);
    
    return 0;
}
