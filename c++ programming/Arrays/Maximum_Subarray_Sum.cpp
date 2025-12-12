#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // Printing subarray
    // int arr[]={1,2,3,4,5};
    // int len=sizeof(arr)/sizeof(arr[0]);
    // for (int start = 0; start < len; start++)
    // {
    //     for (int end = start; end < len; end++)
    //     {
    //         for (int i = start; i < end; i++)
    //         {
    //             cout<<arr[i];
    //         }
    //         cout<<" ";
    //     }
    //     cout<<endl;
        
    // }

    // Brute_Force Approach
    // int arr[]={3,-4,5,4,-1,7,-8};
    // int maxSum=INT_MIN;
    // int len=sizeof(arr)/sizeof(arr[0]);
    // for (int start = 0; start < len; start++)
    // {
    //     int currSum=0;
    //     for (int end = start; end < len; end++)
    //     {
    //         currSum+=arr[end];
    //         maxSum=max(currSum,maxSum);
    //     }
    // }
    // cout<<"The maximum sum is: "<<maxSum<<endl;


    // Kadanes Algorithm
    vector<int> vec={3,-4,5,4,-1,7,-8};
    int maxSum=INT_MIN,currSum=0;
    for(int val : vec)
    {
        currSum+=val;
        maxSum=max(maxSum,currSum);
        if(currSum<0)
            currSum=0;
    }
    cout<<"Kadanes algorithm Maximum subarray sum is: "<<maxSum<<endl;
    return 0;
    
}