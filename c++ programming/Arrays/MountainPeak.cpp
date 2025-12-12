#include<iostream>
#include<vector>
using namespace std;


class Solution
{
    public:
        int findMountainPeak(vector<int> &heights)
        {
            int len=heights.size();
            int l=1,r=len-2;
            
            while(l <= r)
            {
                int mid=l+(r-l)/2;

                if(heights[mid-1] < heights[mid] && heights[mid] > heights[mid+1])
                {
                    return mid;
                }
                else if(heights[mid-1] < heights[mid])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            return -1;
        }
};

int main()
{
    // vector<int> heights={0,10,5,2};
    // vector<int> heights={0,1,0};
    // vector<int> heights={0,2,1,0};
    vector<int> heights={3,5,3,2,0};



    Solution s;
    cout<<s.findMountainPeak(heights)<<endl;
    return 0;
}