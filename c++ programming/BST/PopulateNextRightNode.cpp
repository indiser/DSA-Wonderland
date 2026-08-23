// Date:22/06/2026
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Node
{
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


// Time Complexity: O(n)
// Space Complexity : O(n)
class Solution
{
    public:
        vector<vector<int>> levelOrderTraversal(Node *root)
        {
            if(root == nullptr) return{};

            queue<Node*> q;
            int level=0;

            vector<vector<int>> ans;
            q.push(root);

            while(!q.empty())
            {
                int len=q.size();
                ans.push_back({});

                for (int i = 0; i < len; i++)
                {
                    Node *node=q.front();
                    q.pop();

                    ans[level].push_back(node->val);

                    if(node->left != nullptr) q.push(node->left);
                    if(node->right != nullptr) q.push(node->right);
                }
                level++;
            }
            return ans;
        }
        Node *connect(Node *root)
        {
            if(!root) return nullptr;


            queue<Node*> q;
            
            q.push(root);

            while(!q.empty())
            {
                int len = q.size();

                for (int i = 0; i < len; i++)
                {
                    Node *node = q.front();
                    q.pop();

                    if(i < len - 1) node->next = q.front();

                    if(node->left != nullptr) q.push(node->left);
                    if(node->right != nullptr) q.push(node->right);
                }
            }
            
            return root;
        }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;
    Node *head = s.connect(root);
    vector<vector<int>> ans = s.levelOrderTraversal(head);

    for(auto val:ans)
    {
        for(auto v: val)
        {
            cout<< v <<" ";
        }
        cout<<endl;
    }
    return 0;
}