#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(m * n * 4^L) where m=rows, n=cols, L=word length
// Space Complexity: O(L) for recursion stack depth


class Solution
{
    public:
        
        bool findWord(vector<vector<char>> &board, string &word ,int wordIndex ,int row, int col)
        {
            if(wordIndex == word.length())
            {
                return true;
            }
            if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            {
                return false;
            }
            if(board[row][col] != word[wordIndex])
            {
                return false;
            }

            char originalChar=board[row][col];
            board[row][col]='#';

            if(findWord(board,word,wordIndex+1,row+1,col)) return true;
            if(findWord(board,word,wordIndex+1,row-1,col)) return true;
            if(findWord(board,word,wordIndex+1,row,col+1)) return true;
            if(findWord(board,word,wordIndex+1,row,col-1)) return true;

            board[row][col]=originalChar;
            return false;
        }
        bool generateWord(vector<vector<char>> &board, string &word)
        {

            if(word.empty()) return true;

            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[0].size(); j++)
                {
                    if(board[i][j]==word[0])
                    {
                        if(findWord(board,word,0,i,j))
                            return true;
                    }
                }
            }
            return false;
            
        }

};

int main()
{
    Solution s;
    
    // Test Case 1: Single character
    vector<vector<char>> board1 = {{'a'}};
    string word1 = "a";
    cout << "Test 1 - Board: [[a]], Word: \"a\" -> ";
    cout << (s.generateWord(board1, word1) ? "Found" : "Not Found") << endl;
    
    // Test Case 2: Regular case
    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word2 = "ABCB";
    cout << "Test 2 - Word: \"ABCB\" -> ";
    cout << (s.generateWord(board2, word2) ? "Found" : "Not Found") << endl;
    
    return 0;
}