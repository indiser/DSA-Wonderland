#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) 
        {
            int time = 0;
            for(int i = 0; i < tickets.size(); i++) {
                if(i <= k) {
                    time += min(tickets[i], tickets[k]);
                } else {
                    time += min(tickets[i], tickets[k] - 1);
                }
            }
            return time;
    }
};

int main()
{
    Solution sol;
    vector<int> tickets = {2, 3, 2};
    int k = 2;
    cout << "Time needed: " << sol.timeRequiredToBuy(tickets, k) << endl;
    
    tickets = {5, 1, 1, 1};
    k = 0;
    cout << "Time needed: " << sol.timeRequiredToBuy(tickets, k) << endl;
    
    return 0;
}