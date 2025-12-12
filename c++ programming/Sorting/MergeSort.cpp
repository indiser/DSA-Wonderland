#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i=start, j=mid+1;

    while(i <= mid && j <=end)
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
        }
    }

    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for(int index = 0, len = temp.size(); index < len; index++)
    {
        arr[start+index]=temp[index];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start)/2;

        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }
}

int main()
{
    vector<int> nums={9,8,7,6,1,5,4,3,2};
    int len=nums.size();
    mergeSort(nums,0,len-1);
    for(int val:nums)
        cout<<val<<endl;
    return 0;
}