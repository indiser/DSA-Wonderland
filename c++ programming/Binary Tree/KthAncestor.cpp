// Date: 13/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// TIme Complexity: O(logn+nlogn)
// Space Complexity: O(n log n)
class TreeAncestor
{
    public:
        vector<int> anc[16];
        TreeAncestor(int n, vector<int> &parent) //O(nlogn)
        {
            anc[0] = parent;
            for (int i = 1; i < 16; i++) {
                anc[i].resize(n);
                for (int v = 0; v < n; v++) {
                    if (anc[i - 1][v] == -1)
                        anc[i][v] = -1;
                    else
                        anc[i][v] = anc[i - 1][anc[i - 1][v]];
                }
            }
        }
        int getKthAncestor(int node, int k) //O(logn)
        {
            for (int i = 0; i < 16; i++) {
                if (node == -1)
                    return -1;
                if ((1 << i) & k)
                    node = anc[i][node];
            }
            return node;
        }
};

int main()
{
    int n = 7;
    vector<int> parent = {-1,0,0,1,1,2,2};
    TreeAncestor *treeAncestor = new TreeAncestor(n, parent);
    cout<< treeAncestor->getKthAncestor(3,1)<<endl;
    cout<< treeAncestor->getKthAncestor(5,2)<<endl;
    cout<< treeAncestor->getKthAncestor(6,3)<<endl;
    return 0;
}