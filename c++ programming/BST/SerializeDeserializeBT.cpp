// Date: 28/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// TIme Comeplxity: O(n)
// Space Complexity: O(n)
class Codec
{
    private:
        TreeNode* buildTree(queue<string>& q) 
        {
            if (q.empty()) return nullptr;
            string s = q.front();
            q.pop();
        
            if (s == "#") return nullptr;
        
            TreeNode* root = new TreeNode(stoi(s));
            root->left = buildTree(q);
            root->right = buildTree(q);
            return root;
        }
    public:
        vector<vector<int>> levelOrderTraversal(TreeNode *root)
        {
            if(root == nullptr) return{};

            queue<TreeNode*> q;
            int level=0;

            vector<vector<int>> ans;
            q.push(root);

            while(!q.empty())
            {
                int len=q.size();
                ans.push_back({});

                for (int i = 0; i < len; i++)
                {
                    TreeNode *node=q.front();
                    q.pop();

                    ans[level].push_back(node->val);

                    if(node->left != nullptr) q.push(node->left);
                    if(node->right != nullptr) q.push(node->right);
                }
                level++;
            }
            return ans;
        }

        string serialize(TreeNode *root)
        {
            if (!root) return "#,";
            return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        }

        
        TreeNode *deserialize(string data)
        {
            queue<string> q;
            stringstream ss(data);
            string item;
            while (getline(ss, item, ',')) {
                q.push(item);
            }
            return buildTree(q);
        }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(6);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Codec cer, dcer, s;

    cout<<"Before: "<<endl;

    vector<vector<int>> result1 = s.levelOrderTraversal(root);

    for(auto level : result1)
    {
        for(int val : level)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }

    TreeNode *ans = dcer.deserialize(cer.serialize(root));

    cout<<"After: "<<endl;

    vector<vector<int>> result = s.levelOrderTraversal(ans);

    for(auto level : result)
    {
        for(int val : level)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}