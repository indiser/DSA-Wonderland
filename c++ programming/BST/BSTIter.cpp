// Date: 26/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(1)
// Space Complexity: O(h) [h = height of the tree]
class BSTIterator
{
    public:
        queue<int> result;
        BSTIterator(TreeNode *root)
        {
            if(!root) return;
            TreeNode *curr = root;

            while(curr != nullptr)
            {
                if(curr->left == nullptr)
                {
                    result.push(curr->val);
                    curr = curr->right;
                }
                else
                {
                    TreeNode *IP = curr->left;
                    while(IP->right != nullptr && IP->right != curr) IP=IP->right;

                    if(IP->right == nullptr)
                    {
                        IP->right = curr;
                        curr = curr->left;
                    }
                    else
                    {
                        IP->right = nullptr;
                        result.push(curr->val);
                        curr = curr->right;
                    }
                }
            }
        }

        int next()
        {
            int element = result.front();
            result.pop();
            return element;
        }
        bool hasNext()
        {
            return (!result.empty()) ? true : false;
        }
};

int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator *it = new BSTIterator(root);
    cout<<it->next()<<endl;
    cout<<it->next()<<endl;
    cout<<it->hasNext()<<endl;
    cout<<it->next()<<endl;
    cout<<it->hasNext()<<endl;
    cout<<it->next()<<endl;
    cout<<it->hasNext()<<endl;
    cout<<it->next()<<endl;
    cout<<it->hasNext()<<endl;

    return 0;
}