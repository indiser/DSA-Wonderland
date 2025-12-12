#include<iostream>
#include<vector>
using namespace std;


//Brute-Force Approach:
//Time Complixity:O(m*n)*(m+n) +O(m*n)
//Space Complexity:O(1) + O(m*n) + O(m*n) = O(m*n)

// class Solution
// {
//     public:
//         void markRow(vector<vector<int>> &matrix, int i)
//         {
//             int m=matrix.size();
//             for (int j = 0; j < m; j++)
//             {
//                 if(matrix[i][j]!=0)
//                 {
//                     matrix[i][j]=-1;
//                 }
//             }
            
//         }
//         void markColumn(vector<vector<int>> &matrix, int j)
//         {
//             int n=matrix[0].size();
//             for (int i = 0; i < n; i++)
//             {
//                 if(matrix[i][j]!=0)
//                 {
//                     matrix[i][j]=-1;
//                 }
//             }
            
//         }
//         vector<vector<int>> matrixZero(vector<vector<int>> &matrix)
//         {
//             int m=matrix.size(); //Row
//             int n=matrix[0].size(); //Coloum

//             for (int i = 0; i < m; i++)
//             {
//                 for (int j = 0; j < n; j++)
//                 {
//                     if(matrix[i][j]==0)
//                     {
//                         markRow(matrix,i);
//                         markColumn(matrix,j);
//                     }
//                 }
                
//             }

//             for (int i = 0; i < m; i++)
//             {
//                 for (int j = 0; j < n; j++)
//                 {
//                     if(matrix[i][j]==-1)
//                     {
//                         matrix[i][j]=0;
//                     }
//                 }
                
//             }
//             return matrix;
//         }
// };

// Better Approach:
//Time Complexity:O(m*n)+O(m*n)
//Space Complexity:O(m,n)
// class Solution
// {
//     public:
//         vector<vector<int>> matrixZero(vector<vector<int>> &matrix)
//         {
//             int m=matrix.size();
//             int n=matrix[0].size();

//             vector<int> col(n, 0);
//             vector<int> row(m, 0);

//             for (int i = 0; i < m; i++)
//             {
//                 for (int j = 0; j < n; j++)
//                 {
//                     if(matrix[i][j]==0)
//                     {
//                         row[i]=1;
//                         col[j]=1;
//                     }
//                 }
//             }
            
//             for (int i = 0; i < m; i++)
//             {
//                 for (int j = 0; j < m; j++)
//                 {
//                     if(row[i] || col[j])
//                     {
//                         matrix[i][j]=0;
//                     }
//                 }
//             }
//             return matrix;
//         }
// };

//Optimal Approach:
//Time Complexity:O(m*n)
//Space Complexity:O(1)

class Solution
{
    public:
        vector<vector<int>> matrixZero(vector<vector<int>> &matrix)
        {
            int m=matrix.size();
            int n=matrix[0].size();

            int col0=1;

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(matrix[i][j]==0)
                    {
                        matrix[i][0]=0;
                        if(j!=0)
                        {
                            matrix[0][j]=0;
                        }
                        else
                        {
                            col0=0;
                        }
                    }
                }
            }
            
            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < m; j++)
                {
                    if(matrix[i][j] != 0)
                    {
                        if(matrix[0][j]==0 || matrix[i][0]==0)
                        {
                            matrix[i][j]=0;
                        }
                    }
                }
            }

            if(matrix[0][0]==0)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[0][j]=0;
                }
                
            }

            if(col0==0)
            {
                for (int i = 0; i < m; i++)
                {
                    matrix[i][0]=0;
                }
                
            }
            return matrix;
        }
};

int main()
{
    vector<vector<int>> matrix={{1,1,1},{1,0,1},{1,1,1}};
    Solution s;
    vector<vector<int>> result = s.matrixZero(matrix);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}