#include<iostream>
#include<vector>
using namespace std;
// Leetcode - 88: MergeSortedArray
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
class Solution
{
    public:
        vector<int> mergeSortedArray(vector<int> &A, int m, vector<int> &B, int n)
        {
            int index=m+n-1,i=m-1,j=n-1;

            while(i>=0 && j>=0)
            {
                if(A[i]>=B[j])
                {
                    A[index--]=A[i--];
                }
                else
                {
                    A[index--]=B[j--];
                }
            }
            while(j>=0)
            {
                A[index--]=B[j--];
            }
        }

};

int main()
{
    vector<int> num1={1,2,3,0,0,0};
    vector<int> num2={2,5,6};
    int m=num1.size();
    int n=num2.size();

    Solution s;
    vector<int> SortedArray=s.mergeSortedArray(num1,m,num2,n);
    for(int val:SortedArray)
    {
        cout<<val<<endl;
    }
}