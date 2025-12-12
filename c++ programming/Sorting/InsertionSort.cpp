#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &nums,int len)
{
    for (int i = 1; i < len; i++)
    {
        int key=nums[i];
        int j=i-1;
        while(j>=0 && nums[j]>key)
        {
            nums[j+1]=nums[j];
            j=j-1;
        }
        nums[j+1]=key;
    }
}


int main()
{
    vector<int> nums = {9, 8, 7, 6, 1, 5, 4, 3, 2};
    int len=nums.size();
    insertionSort(nums,len);

    // Print the sorted array
    for (int val : nums)
        cout << val << endl;
    return 0;
}