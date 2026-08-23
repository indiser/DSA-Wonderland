// Date: 05/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution
{
    public:
        void helper(vector<vector<int>> &image, int row, int col, int originalColor, int newColor)
        {
            if(row < 0 || row >= image.size() ||col < 0 || col >= image[0].size() || image[row][col] != originalColor) return;

            image[row][col] = newColor;
            helper(image, row + 1, col, originalColor, newColor);
            helper(image, row - 1, col, originalColor, newColor);
            helper(image, row, col + 1, originalColor, newColor);
            helper(image, row, col - 1, originalColor, newColor);
        }
        vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
        {
            int originalColor = image[sr][sc];
            if(image[sr][sc] != color) helper(image, sr, sc, originalColor, color);
            return image;
        }
};

int main()
{
    vector<vector<int>> image={
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sc = 1;
    int sr = 1;
    int color = 2;

    Solution s;
    vector<vector<int>> result = s.floodFill(image, sr, sc, color);

    for(auto val: result)
    {
        for(auto v: val)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}