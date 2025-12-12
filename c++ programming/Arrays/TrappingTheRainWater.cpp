#include<iostream>
#include<vector>
using namespace std;

// Solution-1:Optimal Approach(Prefix sum)
//Time Complexity:O(n)
//Space Complexity:O(n)
// class Solution
// {
//     public:
//         int trappedWater(vector<int> &heights)
//         {
//             int len=heights.size(),ans=0;

//             vector<int> lmax(len,0),rmax(len,0);

//             lmax[0]=heights[0];
//             rmax[len-1]=heights[len-1];

//             for (int i = 1; i < len; i++)
//             {
//                 lmax[i]=max(lmax[i-1],heights[i]);
//             }

//             for (int i = len-2; i >= 0; i--)
//             {
//                 rmax[i]=max(rmax[i+1],heights[i]);
//             }

//             for (int i = 0; i < len; i++)
//             {
//                 ans+=min(lmax[i],rmax[i])-heights[i];
//             }
            
//             return ans;
            
//         }
// };

// Solution-2:Optimal Solution(Two-Pointers)
//Time Complexity:O(n)
//Space Complexity:O(1)

class Solution
{
    public:
        int trappedWater(vector<int> &heights)
        {
            int len=heights.size(),ans=0;
            int l=0,r=len-1;
            int lmax=0,rmax=0;

            while(l < r)
            {
                lmax=max(lmax,heights[l]);
                rmax=max(rmax,heights[r]);

                if(lmax < rmax)
                {
                    ans+=lmax-heights[l];
                    l++;
                }
                else
                {
                    ans+=rmax-heights[r];
                    r--;
                }
            }

            return ans;
        }
};

int main()
{
    vector<int> heights={4,2,0,3,2,5};
    Solution s;
    cout<<s.trappedWater(heights)<<endl;
    return 0;
}