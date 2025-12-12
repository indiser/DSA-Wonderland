#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity:O(nlogn+n^3)
// Space Complexity:O(unique qutuplets)

class Solution
{
private:
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        int n1=mid-left+1;
        int n2=right-mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
        {
            L[i]=nums[left+i];
        }
        for (int i = 0; i < n2; i++)
        {
            R[i]=nums[mid+1+i];
        }
        int i = 0 , j = 0, k = left;
        while(i<n1 && j<n2)
        {
            if(L[i]<=R[j])
            {
                nums[k]=L[i];
                i++;
            }
            else
            {
                nums[k]=R[j];
                j++;
            }
            k++;
        }

        while(i<n1)
        {
            nums[k]=L[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            nums[k]=R[j];
            j++;
            k++;
        }
        
    }
    void mergeSort(vector<int> &nums, int left, int right)
    {
        if(left>=right)
            return;
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int len=nums.size();
        mergeSort(nums,0,len);
        vector<vector<int>> ans;

        for (int i = 0; i < len; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; 
            for (int j = i + 1; j < len;)
            {
                int p = j + 1, q = len - 1;

                while (p < q)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;
                        while (p < q && nums[p] == nums[p - 1])
                            p++;
                    }
                    else if (sum < target)
                    {
                        p++;
                    }
                    else
                    {
                        q--;
                    }
                }
                j++;
                while (j < len && nums[j] == nums[j - 1])
                    j++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution s;
    vector<vector<int>> result = s.fourSum(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i][0] << "," << result[i][1] << "," << result[i][2] << "," << result[i][3] << "]" << endl;
    }
}