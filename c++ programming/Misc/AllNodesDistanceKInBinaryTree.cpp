#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

class Solution
{
    public:
        void buildGraph(TreeNode *node, unordered_map<TreeNode*, vector<TreeNode*>>& adj)
        {
            if(!node) return;
            if(node->left)
            {
                adj[node].push_back(node->left);
                adj[node->left].push_back(node);
                buildGraph(node->left, adj);
            }
            if(node->right)
            {
                adj[node].push_back(node->right);
                adj[node->right].push_back(node);
                buildGraph(node->right, adj);
            }
        }

        vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
        {
            vector<int> ans;
            unordered_map<TreeNode*,vector<TreeNode*>> adj;
            buildGraph(root, adj);
            queue<TreeNode*> q;
            unordered_map<TreeNode*, bool> visited;
            q.push(target);
            visited[target] = true;
            int distance = 0;

            while (!q.empty())
            {
                if(distance == k)
                {
                    while(!q.empty())
                    {
                        ans.push_back(q.front()->val);
                        q.pop();
                    }
                    break;
                }
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    TreeNode *curr = q.front();
                    q.pop();
                    for(TreeNode *neighbor: adj[curr])
                    {
                        if(!visited[neighbor])
                        {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                distance++;
            }
            return ans;
        }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode *target=root->left;
    int k=2;
    Solution s;
    vector<int> ans=s.distanceK(root,target,k);
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}