#include<iostream>
#include<vector>
using namespace std;

// Solution-1:Naive Approach
// Time Complexity:O(nlogn)
// Space Complexity:O(n)
// void merge(vector<int> &arr, int l, int mid, int r)
// {
//     int i = l, j = mid+1;
//     vector<int> temp;

//     while(i <= mid && j <= r)
//     {
//         if(arr[i] < arr[j])
//         {
//             temp.push_back(i);
//             i++;
//         }
//         else
//         {
//             temp.push_back(j);
//             j++;
//         }
//     }

//     while(i <= mid)
//     {
//         temp.push_back(i);
//         i++;
//     }

//     while(j <= l)
//     {
//         temp.push_back(j);
//         j++;
//     }
// }

// void mergeSort(vector<int> &arr, int l, int r)
// {
//     if(l < r)
//     {
//         int mid=l+(r-l)/2;
//         mergeSort(arr, l, mid);
//         mergeSort(arr,mid+1,r);
//         merge(arr,l,mid,r);

//     }
// }

//Two pass Solution(Optimal Solution)
//Time Complexity:O(n)
//Space Complexity:O(1)

int twoPass(vector<int> &arr)
{
    int firstMax=-1, secondMax=-1;

    for(int val:arr)
    {
        if(firstMax < val)
            firstMax=val;
    }

    for(int val:arr)
    {
        if(secondMax < val && val != firstMax)
            secondMax=val;
    }
    return secondMax;
}

//One Pass(Expected Solution)
//Time Complexity:O(n)
//Space Complexity:O(1)
int onePass(vector<int> &arr)
{
    int firstMax=-1,secondMax=-1;

    for(int val:arr)
    {
        if(val > firstMax)
        {
            secondMax=firstMax;
            firstMax=val;
        }
        else if(val < firstMax && val > secondMax)
        {
            secondMax=val;
        }
    }
    return secondMax;
}

int main()
{
    vector<int> nums={12,35,1,10,34,1};
    int len=nums.size();
    // mergeSort(nums,0,len-1);
    cout<<"Second Largest element is:"<<onePass(nums)<<endl;

    return 0;
}