// Date: 30/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution
{
    public:
        // void heapify(vector<int> &arr, int n, int i)
        // {
        //     int largest = i;
        //     int l = 2 * i + 1;
        //     int r = 2 * i + 2;

        //     if(l < n && arr[l] > arr[largest]) largest = l;
        //     if(r < n && arr[r] > arr[largest]) largest = r;    // Creates max heap

        //     if(largest != i)
        //     {
        //         swap(arr[i], arr[largest]);
        //         heapify(arr, n, largest);
        //     }
        // }
        // vector<int> sortArray(vector<int> &nums)
        // {
        //     int n = nums.size();

        //     for (int i = n / 2 - 1; i >= 0; i--)
        //     {
        //         heapify(nums, n, i);
        //     }
            
        //     for (int i = n - 1; i >= 0; i--)
        //     {
        //         swap(nums[0], nums[i]);
        //         heapify(nums, i, 0);
        //     }
        //     return nums;
        // }
        vector<int> sortArray(vector<int> &nums)
        {
            priority_queue<int, vector<int>, greater<int>> minHeap;

            for(int val: nums) minHeap.push(val);

            vector<int> ans;
            while(!minHeap.empty())
            {
                int curr = minHeap.top();
                minHeap.pop();
                ans.push_back(curr);
            }

            return ans;
        }
};

int main()
{
    vector<int> nums = {5, 1, 1, 2, 0, 0};

    Solution s;
    vector<int> result = s.sortArray(nums);
    for(int val: result)
    {
        cout<<val<<" ";
    }
    return 0;
}