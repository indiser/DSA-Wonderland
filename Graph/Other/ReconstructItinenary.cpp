#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
#include<stack>
#include<algorithm>
using namespace std;

/*
Time Complexity: O(E log E)
- E: number of tickets (edges)
- Building adjacency list: O(E)
- Sorting destinations for each airport: O(E log E) in worst case
- Hierholzer's algorithm: O(E) - each edge processed once
- Reversing result: O(E)
- Total: O(E log E) dominated by sorting

Space Complexity: O(E)
- Adjacency list: O(E) to store all flight connections
- Stack: O(E) maximum depth in worst case
- Result array: O(E) to store the itinerary
- No additional recursive space needed
*/
class Solution
{
    public:
        unordered_map<string, vector<string>> adjList(vector<vector<string>>& tickets)
        {
            unordered_map<string, vector<string>> adj;
            for(auto ticket:tickets)
            {
                string u=ticket[0];
                string v=ticket[1];
                adj[u].push_back(v);
            }
            return adj;
        }
        vector<string> findItinerary(vector<vector<string>>& tickets) 
        {
            unordered_map<string, vector<string>> adj = adjList(tickets);
            
            // Sort destinations for lexicographical order
            for(auto& pair : adj)
            {
                sort(pair.second.begin(), pair.second.end());
            }
            
            stack<string> st;
            vector<string> result;
            st.push("JFK");

            while(!st.empty())
            {
                string curr = st.top();
                if(!adj[curr].empty())
                {
                    string next = adj[curr].front();
                    adj[curr].erase(adj[curr].begin());
                    st.push(next);
                }
                else
                {
                    result.push_back(curr);
                    st.pop();
                }
            }
            
            reverse(result.begin(), result.end());
            return result;
        }
};

int main()
{
    cout << "=== Reconstruct Itinerary ===" << endl;
    
    Solution sol;
    
    // Test case 1: Simple round trip
    cout << "\nTest Case 1: Simple round trip" << endl;
    vector<vector<string>> tickets1 = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    
    cout << "Flight tickets:" << endl;
    for(auto ticket : tickets1)
    {
        cout << "  " << ticket[0] << " -> " << ticket[1] << endl;
    }
    
    cout << "\nStarting from JFK, finding itinerary..." << endl;
    vector<string> itinerary1 = sol.findItinerary(tickets1);
    
    cout << "\nReconstructed itinerary: ";
    for(int i = 0; i < itinerary1.size(); i++)
    {
        cout << itinerary1[i];
        if(i < itinerary1.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    // Test case 2: Multiple possible paths (lexicographical order)
    cout << "\nTest Case 2: Multiple paths (lexicographical preference)" << endl;
    vector<vector<string>> tickets2 = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    
    cout << "Flight tickets:" << endl;
    for(auto ticket : tickets2)
    {
        cout << "  " << ticket[0] << " -> " << ticket[1] << endl;
    }
    
    cout << "\nStarting from JFK, finding lexicographically smallest itinerary..." << endl;
    vector<string> itinerary2 = sol.findItinerary(tickets2);
    
    cout << "\nReconstructed itinerary: ";
    for(int i = 0; i < itinerary2.size(); i++)
    {
        cout << itinerary2[i];
        if(i < itinerary2.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    // Test case 3: Linear path
    cout << "\nTest Case 3: Linear path" << endl;
    vector<vector<string>> tickets3 = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    
    cout << "Flight tickets:" << endl;
    for(auto ticket : tickets3)
    {
        cout << "  " << ticket[0] << " -> " << ticket[1] << endl;
    }
    
    cout << "\nStarting from JFK, finding itinerary..." << endl;
    vector<string> itinerary3 = sol.findItinerary(tickets3);
    
    cout << "\nReconstructed itinerary: ";
    for(int i = 0; i < itinerary3.size(); i++)
    {
        cout << itinerary3[i];
        if(i < itinerary3.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    cout << "\nAlgorithm: Hierholzer's algorithm for Eulerian path" << endl;
    cout << "Always starts from JFK and finds lexicographically smallest valid itinerary" << endl;
    cout << "Uses all tickets exactly once" << endl;
    
    return 0;
}