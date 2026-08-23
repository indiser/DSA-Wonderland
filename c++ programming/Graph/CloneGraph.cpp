// Date: 15/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
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

// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* dfs(Node *node)
    {
        if(visited.count(node)) return visited[node];
        Node *newNode = new Node(node->val);
        visited[node] = newNode;
        for(Node* neighbour : node->neighbors) newNode->neighbors.push_back(dfs(neighbour));
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return dfs(node);
    }
    void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
        if (!node || visited[node]) return;
    
        visited[node] = true;
        cout << "Node " << node->val << " neighbors: ";
        for (Node* neighbor : node->neighbors) {
            cout << neighbor->val << " ";
        }
        cout << "\n";
    
        for (Node* neighbor : node->neighbors) {
            printGraph(neighbor, visited);
        }
}
};

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution s;
    Node* clonedNode = s.cloneGraph(node1);

    cout << "Original Graph:\n";
    unordered_map<Node*, bool> visited1;
    s.printGraph(node1, visited1);

    cout << "\nCloned Graph:\n";
    unordered_map<Node*, bool> visited2;
    s.printGraph(clonedNode, visited2);

    return 0;
}