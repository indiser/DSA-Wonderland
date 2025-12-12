#include<iostream>
#include<vector>
using namespace std;

// Solution-1:Brute-Force Approach(SElection Sort)
//Time Complexity:O(n^2)
//Space Complexity:O(1)
// class Solution
// {
//     public:
//         void swap(int &a, int &b)
//         {
//             int temp = a;
//             a = b;
//             b = temp;
//         }
//         int numberOfInversions(vector<int> &arr)
//         {
//             int count=0;
//             int len=arr.size();
//             for (int i = 0; i < len; i++)
//             {
//                 for (int j = i+1; j < len; j++)
//                 {
//                     if(arr[i] > arr[j])
//                     {
//                         swap(arr[i],arr[j]);
//                         count++;
//                     }
//                 }
//             }
//             return count;
//         }
// };


// Solution-2:Optimal Approach(MergeSort)
//Time Complexity:O(nlogn)
//Space complexity:O(n)


class Solution
{
    public:
        int merge(vector<int> &arr, int start, int mid, int end)
        {
            vector<int> temp;
            int i = start, j = mid+1;
            int inversionCount=0;
            while(i <= mid && j <= end)
            {
                if(arr[i] <= arr[j])
                {
                    temp.push_back(arr[i]);
                    i++;
                }
                else
                {
                    temp.push_back(arr[j]);
                    j++;
                    inversionCount+=(mid-i+1);
                }
            }

            while( i <= mid)
            {
                temp.push_back(arr[i]);
                i++;
            }

            while( j <= end)
            {
                temp.push_back(arr[j]);
                j++;
            }

            for(int index = 0, len = temp.size(); index < len; index++)
            {
                arr[index+start]=temp[index];
            }
            return inversionCount;
        }
        int mergeSort(vector<int> &arr, int start, int end)
        {
            if(start < end)
            {
                int mid = start + (end - start)/2;

                int leftInversionCount=mergeSort(arr,start,mid);
                int rightInversionCount=mergeSort(arr,mid+1,end);

                int inversionCount=merge(arr,start,mid,end);

                return leftInversionCount+rightInversionCount+inversionCount;
            }
            return 0;
        }
};

int main()
{
    vector<int> arr={4,2,1};
    int len=arr.size();
    Solution s;
    cout<<s.mergeSort(arr,0,len-1)<<endl;
    return 0;
}