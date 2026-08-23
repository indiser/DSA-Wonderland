#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<utility>
#include<algorithm>
using namespace std;

class DSU
{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(int n)
        {
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
            rank.assign(n,1);
        }

        int find(int i)
        {
            if(parent[i]==i)
            {
                return i;
            }
            return parent[i]=find(parent[i]);
        }

        void unite(int i, int j)
        {
            int root_i=find(i);
            int root_j=find(j);

            if(root_i != root_j)
            {
                if(rank[root_i] < rank[root_j])
                {
                    swap(root_i,root_j);
                }
                parent[root_i]=root_j;
                rank[root_i]+=rank[root_j];
            }
        }
};

int main()
{
    DSU dsu(6);
    
    dsu.unite(0, 1);
    cout << "Find(0): " << dsu.find(0) << endl;
    dsu.unite(2, 3);
    cout << "Find(3): " << dsu.find(3) << endl;
    dsu.unite(1, 2);
    cout << "Find(4): " << dsu.find(4) << endl;
    
    return 0;
}