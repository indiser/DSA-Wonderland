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
        vector<int> sz;
    public:
        DSU(int n)
        {
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
            sz.assign(n,1);
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
                if(sz[root_i] < sz[root_j])
                {
                    swap(root_i,root_j);
                }
                parent[root_i]=root_j;
                sz[root_i]+=sz[root_j];
            }
        }
};

int main()
{
    DSU dsu(6);
    
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(1, 2);
    
    cout << "Find(0): " << dsu.find(0) << endl;
    cout << "Find(3): " << dsu.find(3) << endl;
    cout << "Find(4): " << dsu.find(4) << endl;
    
    return 0;
}