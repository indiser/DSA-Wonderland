#include<iostream>
#include<vector>
using namespace std;

//Time Complexity: O(log(m*n)) where m is the number of rows and n is the number of columns
//Space Complexity: O(1)
class Solution
{
    public:
        bool searchInRow(vector<vector<int>>& matrix, int target,int row)
        {
            int n=matrix[0].size();
            int start=0,end=n-1;

            while(start<=end)
            {
                int mid=start+(end-start)/2;

                if(matrix[row][mid]==target)
                {
                    return true;
                }
                else if(matrix[row][mid]<target)
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
        bool searchMatrix(vector<vector<int>>& matrix, int target)
        {
            int m=matrix.size(); //Toatl Rows
            int n=matrix[0].size(); //Toatl Colums
            int startRow=0,endRow=m-1;

            while(startRow<=endRow)
            {
                int midRow=startRow+(endRow-startRow)/2;

                if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1])
                {
                    //To find the row
                    return searchInRow(matrix,target,midRow);
                }
                else if(target >= matrix[midRow][n-1])
                {
                    //Right
                    startRow=midRow+1;
                }
                else
                {
                    //Left
                    endRow=midRow-1;
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
    cout<<s.searchMatrix(matrix,target)<<endl;
    return 0;
}