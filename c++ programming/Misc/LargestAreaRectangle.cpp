#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
    public:
        int largestAreaRectangle(vector<int> &heights)
        {
            int len=heights.size();
            if(len==0)
                return 0;
            vector<int> left(heights.size()), right(heights.size());
            stack<int> s;
            int maxArea=0;

            //Right neaerest smaller element
            for (int i = len-1; i >= 0; i--)
            {
                while(s.size() > 0 && heights[s.top()] >= heights[i])
                {
                    s.pop();
                }
                right[i] = s.empty() ? len : s.top();
                s.push(i);
            }

            while(!s.empty())
                s.pop(); // Clear the stack for the next pass

            //Left nerest smaller element
            for (int i = 0; i < len; i++)
            {
                while(s.size() > 0 && heights[s.top()] >= heights[i])
                {
                    s.pop();
                }
                left[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }

            for (int i = 0; i < len; i++)
            {
                int width = right[i] - left[i] -1;
                int currArea = heights[i] * width;
                maxArea = max(maxArea, currArea);
            }
            return maxArea;
        }
};

int main()
{
    vector<int> heights={2,1,5,6,2,3};
    Solution s;
    cout<<s.largestAreaRectangle(heights)<<endl;
    return 0;
}