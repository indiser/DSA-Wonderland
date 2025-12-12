#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

using Graph=map<int,multiset<int>>;

void findEulerPath(Graph &adj)
{
    map<int,int> degrees;
    for(const auto& pair:adj)
    {
        degrees[pair.first]=pair.second.size();
    }

    int odd_degree_count=0;
    int start_node=-1;

    for(const auto& pair:degrees)
    {
        if(pair.second % 2 != 0)
        {
            odd_degree_count++;
            start_node=pair.first;
        }
    }

    if (odd_degree_count > 2) {
        cout << "No Eulerian Path or Circuit exists." << endl;
        return;
    }

    if(start_node==-1)
    {
        start_node=adj.begin()->first;
    }

    // Hiens Algorithm
    stack<int> st;
    st.push(start_node);
    vector<int> path;
    while(!st.empty())
    {
        int u=st.top();
        if(!adj[u].empty())
        {
            int v=*adj[u].begin();
            st.push(v);
            adj[u].erase(adj[u].begin());
            adj[v].erase(adj[v].find(u));
        }
        else
        {
            path.push_back(u);
            st.pop();
        }
    }
    reverse(path.begin(),path.end());
    
    cout << "\nEulerian Path: ";
    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if(i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
}

int main()
{
    cout << "=== Eulerian Path and Circuit ===" << endl;
    
    // Test case 1: Eulerian Circuit (all vertices have even degree)
    cout << "\nTest Case 1: Eulerian Circuit" << endl;
    Graph graph1;
    graph1[0] = {1, 2};
    graph1[1] = {0, 2};
    graph1[2] = {0, 1};
    
    cout << "Graph edges:" << endl;
    for(auto& pair : graph1)
    {
        int u = pair.first;
        for(int v : pair.second)
        {
            if(u <= v) // Avoid printing same edge twice
                cout << "  " << u << " -- " << v << endl;
        }
    }
    
    cout << "\nVertex degrees:" << endl;
    for(auto& pair : graph1)
    {
        cout << "  Vertex " << pair.first << ": degree " << pair.second.size() << endl;
    }
    
    cout << "All vertices have even degree -> Eulerian Circuit exists";
    findEulerPath(graph1);
    
    // Test case 2: Eulerian Path (exactly 2 vertices have odd degree)
    cout << "\n\nTest Case 2: Eulerian Path" << endl;
    Graph graph2;
    graph2[0] = {1, 2};
    graph2[1] = {0, 2, 3};
    graph2[2] = {0, 1, 3};
    graph2[3] = {1, 2};
    
    cout << "Graph edges:" << endl;
    for(auto& pair : graph2)
    {
        int u = pair.first;
        for(int v : pair.second)
        {
            if(u <= v) // Avoid printing same edge twice
                cout << "  " << u << " -- " << v << endl;
        }
    }
    
    cout << "\nVertex degrees:" << endl;
    for(auto& pair : graph2)
    {
        cout << "  Vertex " << pair.first << ": degree " << pair.second.size() << endl;
    }
    
    cout << "Exactly 2 vertices have odd degree -> Eulerian Path exists";
    findEulerPath(graph2);
    
    // Test case 3: No Eulerian Path (more than 2 vertices have odd degree)
    cout << "\n\nTest Case 3: No Eulerian Path" << endl;
    Graph graph3;
    graph3[0] = {1};
    graph3[1] = {0, 2};
    graph3[2] = {1, 3};
    graph3[3] = {2};
    
    cout << "Graph edges:" << endl;
    for(auto& pair : graph3)
    {
        int u = pair.first;
        for(int v : pair.second)
        {
            if(u <= v) // Avoid printing same edge twice
                cout << "  " << u << " -- " << v << endl;
        }
    }
    
    cout << "\nVertex degrees:" << endl;
    for(auto& pair : graph3)
    {
        cout << "  Vertex " << pair.first << ": degree " << pair.second.size() << endl;
    }
    
    cout << "All 4 vertices have odd degree -> No Eulerian Path exists";
    findEulerPath(graph3);
    
    cout << "\n\nEulerian Path Rules:" << endl;
    cout << "- Circuit: All vertices have even degree" << endl;
    cout << "- Path: Exactly 2 vertices have odd degree" << endl;
    cout << "- None: More than 2 vertices have odd degree" << endl;
    
    return 0;
}