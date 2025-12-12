#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
    Tree(int x)
    {
        data=x;
        left=nullptr;
        right=nullptr;
    }
};


class Solution
{
    public:
        
        vector<vector<int>> levelOrderTraversal(Tree *root)
        {
            if(root == nullptr) return{};

            queue<Tree*> q;
            int level=0;

            vector<vector<int>> ans;
            q.push(root);

            while(!q.empty())
            {
                int len=q.size();
                ans.push_back({});

                for (int i = 0; i < len; i++)
                {
                    Tree *node=q.front();
                    q.pop();

                    ans[level].push_back(node->data);

                    if(node->left != nullptr) q.push(node->left);
                    if(node->right != nullptr) q.push(node->right);
                }
                level++;
            }
            return ans;
        }

};

int main()
{
    Tree* root = new Tree(3);
    root->left = new Tree(9);
    root->right = new Tree(20);
    root->right->left = new Tree(15);
    root->right->right = new Tree(7);
    
    Solution s;
    vector<vector<int>> ans = s.levelOrderTraversal(root);

    for(auto level : ans)
    {
        for(int val : level)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}