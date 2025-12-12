#include<iostream>
#include<vector>
using namespace std;

//Time Complexity:O(log(m*n))
//Space Complexity:O(1)

class Solution
{
    public:
     bool searchInRow(vector<vector<int>> &matrix, int target, int row)
     {
        int n=matrix[0].size(); //colums
        int start=0,end=n-1;
        while(start <= end)
        {
            int mid=start+(end-start)/2;

            if(matrix[row][mid]==target)
            {
                return true;
            }
            else if(matrix[row][mid] < target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return false;
     }
     bool search2DMatrix(vector<vector<int>> &matrix, int target)
     {
        int m=matrix.size(); //Row
        int n=matrix[0].size(); //Coloum
        int startRow=0,endRow=n-1;

        while(startRow <= endRow)
        {
            int midRow = startRow + (endRow - startRow) / 2;

            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1])
            {
                return searchInRow(matrix,target,midRow);
            }
            if(target >= matrix[midRow][n-1])
            {
                startRow = midRow + 1;
            }
            else
            {
                endRow = midRow - 1;
            }
        }
        return false;
     }

};

int main()
{
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    Solution s;
    cout<<s.search2DMatrix(matrix,target)<<endl;
    return 0;
}