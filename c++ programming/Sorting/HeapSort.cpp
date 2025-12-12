#include <iostream>
#include <vector>
using namespace std;

// Function to maintain the max-heap property
void heapify(vector<int> &nums, int n, int i)
{
    int largest = i;          // Initialize the largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // Check if the left child is larger than the root
    if (left < n && nums[left] > nums[largest])
        largest = left;

    // Check if the right child is larger than the largest so far
    if (right < n && nums[right] > nums[largest])
        largest = right;

    // If the largest is not the root, swap and recursively heapify
    if (largest != i)
    {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

// Function to perform heap sort
void heapSort(vector<int> &nums)
{
    int n = nums.size();

    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(nums, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root (largest) to the end
        swap(nums[0], nums[i]);

        // Call heapify on the reduced heap
        heapify(nums, i, 0);
    }
}

int main()
{
    vector<int> nums = {9, 8, 7, 6, 1, 5, 4, 3, 2};

    // Perform heap sort
    heapSort(nums);

    // Print the sorted array
    for (int val : nums)
        cout << val << " ";
    cout << endl;

    return 0;
}