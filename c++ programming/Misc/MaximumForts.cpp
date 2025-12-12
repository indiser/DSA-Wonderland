#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int capturedForts(vector<int> &forts)
        {
            if(forts.empty()) return 0;
            if(forts.size()==1) return 0;

            int len=forts.size();
            int l=0,maxCapture=0;
            for (int r = 0; r < len; r++)
            {
                if(forts[r]==1 || forts[r]==-1) //Checks if its a fort
                {
                    if(forts[l]==-forts[r] || forts[r]==-forts[l])
                    {
                        int w=r-l-1;
                        maxCapture=max(maxCapture,w);
                    }
                    l=r;
                }
            }
            return maxCapture;
        }
};

//Time complexity:O(n)
//Space complexity:O(1)

int main()
{
    vector<int> forts={1,0,0,-1,0,0,0,0,1};
    // vector<int> forts={1,0,0,-1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1};
    // vector<int> forts={0,0,1,-1};
    Solution s;
    cout<<s.capturedForts(forts)<<endl;
}