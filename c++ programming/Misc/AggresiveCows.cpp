#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        bool isPossible(vector<int> &arr, int size, int C, int minimumDistAllowed)
        {
            int cows=1,lastStallPos=arr[0];

            for (int i = 1; i < size; i++)
            {
                if((arr[i]-lastStallPos) >= minimumDistAllowed)
                {
                    cows++;
                    lastStallPos=arr[i];
                }
                if(cows==C)
                {
                    return true;
                }
            }
            return false;
        }
        int aggresiveCowsDistance(vector<int> &arr, int C)
        {
            int len=arr.size();
            sort(arr.begin(),arr.end());
            int st=1, end=arr[len-1]-arr[0],ans=-1;

            while(st <= end)
            {
                int mid=st+(end-st)/2;
                if(isPossible(arr,len,C,mid))
                {
                    ans=mid;
                    st=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
            return ans;
        }
};

int main()
{
    vector<int> arr={1,2,8,4,9};
    int C=3;
    Solution s;
    cout<<s.aggresiveCowsDistance(arr,C)<<endl;
    return 0;
}