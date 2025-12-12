#include<iostream>
#include<vector>
using namespace std;

//Time Complexity:O(nlogn)
//Space Complexity:O(1)

class Solution
{
    public:
        bool isValid(vector<int> &arr, int size, int k, int maxPagesAllocated)
        {
            int students = 1, pages = 0;

            for (int i = 0; i < size; i++)
            {
                if(arr[i] > maxPagesAllocated)
                {
                    return false;
                }
                if(pages + arr[i] <= maxPagesAllocated)
                {
                    pages+=arr[i];
                }
                else
                {
                    students++;
                    pages = arr[i];
                }
            }
            
            return students > k ? false : true;
        }
        int numberOfAllocatedBooks(vector<int> &arr, int k)
        {
            int len = arr.size();
            int sum = 0,ans = 0;
            if( k > len)
                return -1;
            
            for (int val: arr)
            {
                sum+=val;
            }
            
            int st = 0, end = sum;

            while(st <= end)
            {
                int mid = st +(end - st)/2;

                if(isValid(arr,len,k,mid))
                {
                    ans = mid;
                    end = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
            }
            return ans;
        }
};

int main()
{
    vector<int> arr={22, 23, 67};
    int k = 1;
    Solution s;
    cout<<s.numberOfAllocatedBooks(arr,k)<<endl;
    return 0;
}