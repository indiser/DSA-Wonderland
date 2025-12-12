#include<iostream>
#include<vector>
using namespace std;

//Same as the book allocation problem

//Time Complexity:O(nlogN)
//Space Complexity:O(1)

class Solution
{
    public:
        bool isValid(vector<int> &arr, int size, int k, int maxPaintAllocated)
        {
            int painters=1, paint=0;

            for (int i = 0; i < size; i++)
            {
                if(arr[i] > maxPaintAllocated)
                {
                    return false;
                }

                if(paint+arr[i]<=maxPaintAllocated)
                {
                    paint+=arr[i];
                }
                else
                {
                    painters++;
                    paint=arr[i];
                }
            }
            return painters > k ? false : true;
        }
        int paintersPartition(vector<int> &arr, int k)
        {
            int len=arr.size();
            int sum=0,ans=0;

            if(k>len)
                return -1;
            
            for(int val:arr)
                sum+=val;

            int st=0,end=sum;

            while(st <= end)
            {
                int mid=st+(end-st)/2;

                if(isValid(arr,len,k,mid))
                {
                    ans=mid;
                    end=mid-1;
                }
                else
                {
                    st=mid+1;
                }
            }
            return ans;
        }
};

int main()
{
    // vector<int> arr={5,10,30,20,15};
    vector<int> arr={10,20,30,40};

    // int k=3;
    int k=2;
    Solution s;
    cout<<s.paintersPartition(arr,k)<<endl;
    return 0;
}