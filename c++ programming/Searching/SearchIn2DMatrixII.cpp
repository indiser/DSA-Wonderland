#include<iostream>
#include<vector>
using namespace std;

//Time Complexity:O(m+n)
//Space Complexity:O(1)

class Solution
{
    public:
        bool searchInMatrix(vector<vector<int>> &matrix, int target)
        {
            int m=matrix.size();//Coloum
            int n=matrix[0].size();//Row

            int r=0,c=n-1;

            while(r<m && c>=0)
            {
                if(target == matrix[r][c])
                {
                    return true;
                }
                else if(target < matrix[r][c])
                {
                    c--;
                }
                else
                {
                    r++;
                }
            }
            return false;
        }
};

int main()
{
    vector<vector<int>> matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=30;
    Solution s;
    cout<<s.searchInMatrix(matrix,target)<<endl;
    return 0;
}