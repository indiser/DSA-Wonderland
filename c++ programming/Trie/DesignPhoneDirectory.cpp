// Date: 03/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(n)
class PhoneDirectory
{
    public:
        vector<bool> visited;
        queue<int> q;
        PhoneDirectory(int maxNumbers)
        {
            visited.assign(maxNumbers, true);
            for (int i = 0; i < maxNumbers; i++)
            {
                q.push(i);
            }
            
        }
        int get()
        {
            if(q.empty()) return -1;
            int element = q.front();
            q.pop();
            visited[element] = false;
            return element;
        }
        bool check(int number)
        {
            return visited[number];
        }
        void release(int number)
        {
            if(visited[number] != true)
            {
                visited[number] = true;
                q.push(number);
            }
        }
};


int main()
{
    PhoneDirectory pd(3);
    
    cout << pd.get() << "\n";      // 0
    cout << pd.get() << "\n";      // 1
    cout << pd.check(2) << "\n";   // 1 (true)
    cout << pd.get() << "\n";      // 2
    cout << pd.check(2) << "\n";   // 0 (false)
    
    pd.release(2);
    cout << pd.check(2) << "\n";   // 1 (true)
    
    return 0;
}