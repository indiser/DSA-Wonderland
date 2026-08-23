// Date: 15/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

// Time Complexity: O(nlogk)
// Space Complexity: O(k)
class KthLargest
{
    public:
        int k;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        KthLargest(int k, vector<int> &nums)
        {
            this->k=k;
            for(int val: nums)
                add(val);
        }
        int add(int val)
        {
            minHeap.push(val);
            if(minHeap.size() > k) minHeap.pop();
            return minHeap.top();
        }
};

int main()
{
    int k = 3;
    vector<int> nums = {4, 5 , 8, 2};
    KthLargest *kl = new KthLargest(k, nums);

    cout<<kl->add(2)<<endl;
    cout<<kl->add(10)<<endl;
    cout<<kl->add(9)<<endl;
    cout<<kl->add(9)<<endl;
    
    return 0;
}