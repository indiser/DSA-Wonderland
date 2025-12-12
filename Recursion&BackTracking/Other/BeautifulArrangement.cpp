#include<iostream>
#include<vector>
using namespace std;


class Solution
{
    public:
        int count=0;
        void currentArrangement(int n, int position, vector<bool> &visited)
        {
            if (position > n)
            {
                count++;
                return;
            }

            for (int num = 1; num <= n; num++)
            {
                if(!visited[num] && (num%position==0 || position%num==0))
                {
                    visited[num]=true;
                    currentArrangement(n,position+1,visited);
                    visited[num]=false;
                }
            }
            
            
        }
        int generateArrangement(int n)
        {
            vector<bool> visited(n+1,false);

            currentArrangement(n,1,visited);

            return count;
        }
};

int main()
{
    int n=6;
    Solution s;
    cout<<s.generateArrangement(n)<<endl;
}