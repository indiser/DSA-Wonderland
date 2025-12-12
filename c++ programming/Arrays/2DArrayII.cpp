#include<iostream>
#include<vector>
using namespace std;
//Time Complexity: O(m+n) where m is the number of rows and n is the number of columns in the matrix.
//Space Complexity: O(1)
class Solution
{
    public:
        bool searchInMatrix(vector<vector<int>>& matrix, int target)
        {
            int m = matrix.size();
            int n = matrix[0].size();

            int r=0,c=n-1;

            while(r<m && c>=0)
            {
                if(matrix[r][c] == target)
                    return true;
                else if(matrix[r][c] > target)
                    c--;
                else
                    r++;
            }
            return false;   
        }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
        {60, 61, 62, 63}
    };
    int target = 15;
    Solution s;
    cout<<s.searchInMatrix(matrix, target)<<endl;
    return 0;
}