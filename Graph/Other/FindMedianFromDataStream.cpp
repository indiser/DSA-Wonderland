#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Time Complexity:
- addNum(): O(log n)
  - Push to maxHeap: O(log n)
  - Move top from maxHeap to minHeap: O(log n) + O(log n)
  - Rebalancing (if needed): O(log n) + O(log n)
  - Total: O(log n)
- findMedian(): O(1)
  - Simply access heap tops: O(1)

Space Complexity: O(n)
- Two heaps store all n numbers
- maxHeap: O(n/2) in worst case
- minHeap: O(n/2) in worst case
- Total: O(n)
- No additional auxiliary space needed
*/
class MedianFinder {
private:
    priority_queue<int> maxHeap; // Left half (smaller numbers)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Right half (larger numbers)
    
public:
    MedianFinder() {
        // Constructor - heaps are automatically initialized
    }
    
    void addNum(int num) {
        // Add to maxHeap first
        maxHeap.push(num);
        
        // Move the largest from maxHeap to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Balance the heaps - maxHeap should have equal or one more element
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    cout << "=== Find Median from Data Stream ===" << endl;
    
    MedianFinder mf;
    
    cout << "\nAdding numbers and finding median after each insertion:" << endl;
    
    // Test sequence: 1, 2, 3, 4, 5
    vector<int> nums = {1, 2, 3, 4, 5};
    
    for(int num : nums) {
        mf.addNum(num);
        double median = mf.findMedian();
        
        cout << "Added " << num << " -> Current median: " << median << endl;
    }
    
    cout << "\nTest Case 2: Mixed positive and negative numbers" << endl;
    MedianFinder mf2;
    
    vector<int> nums2 = {-1, -2, -3, -4, -5};
    
    for(int num : nums2) {
        mf2.addNum(num);
        double median = mf2.findMedian();
        
        cout << "Added " << num << " -> Current median: " << median << endl;
    }
    
    cout << "\nTest Case 3: Random order insertion" << endl;
    MedianFinder mf3;
    
    vector<int> nums3 = {6, 10, 2, 6, 5, 0, 6, 3, 1, 0, 0};
    
    for(int num : nums3) {
        mf3.addNum(num);
        double median = mf3.findMedian();
        
        cout << "Added " << num << " -> Current median: " << median << endl;
    }
    
    cout << "\nAlgorithm: Two heaps approach" << endl;
    cout << "- Max heap stores smaller half of numbers" << endl;
    cout << "- Min heap stores larger half of numbers" << endl;
    cout << "- Median is either top of max heap or average of both tops" << endl;
    cout << "Time: O(log n) for addNum, O(1) for findMedian" << endl;
    cout << "Space: O(n) for storing all numbers" << endl;
    
    return 0;
}