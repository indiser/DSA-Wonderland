#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution
{
    public:
        set<string> st;
        void findBoggles(vector<vector<char>> &board,const set<string> &dictionary,set<string> &foundWord,int row, int col,vector<vector<bool>> &visited,string &currentWord)
        {

            if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            {
                return;
            }

            if(visited[row][col]==true)
            {
                return;
            }


            currentWord.push_back(board[row][col]);
            visited[row][col]=true;

            if(dictionary.count(currentWord))
            {
                foundWord.insert(currentWord);
            }

            findBoggles(board, dictionary, foundWord, row+1, col, visited, currentWord);
            findBoggles(board, dictionary, foundWord, row-1, col, visited, currentWord);
            findBoggles(board, dictionary, foundWord, row, col+1, visited, currentWord);
            findBoggles(board, dictionary, foundWord, row, col-1, visited, currentWord);
            findBoggles(board, dictionary, foundWord, row-1, col-1, visited, currentWord);
            findBoggles(board, dictionary, foundWord, row-1, col+1, visited, currentWord);
            findBoggles(board, dictionary, foundWord, row+1, col-1, visited, currentWord);
            findBoggles(board, dictionary, foundWord, row+1, col+1, visited, currentWord);



            visited[row][col]=false;
            currentWord.pop_back();
            

        }
        vector<string> generateBoggles(vector<vector<char>> &board, const set<string> &dictionary)
        {
            string currentWord="";
            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
            set<string> foundWord;

            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[0].size(); j++)
                {
                    findBoggles(board, dictionary, foundWord, i, j, visited, currentWord);
                }
                
            }
            vector<string> ans(foundWord.begin(),foundWord.end());
            return ans;
            
        }

};

int main()
{
    vector<vector<char>> board = {
        {'G', 'I', 'Z', 'Z'},
        {'U', 'E', 'K', 'S'},
        {'Q', 'S', 'E', 'L'},
        {'C', 'A', 'T', 'S'}
    };

    set<string> dictionary = {"GEEKS", "FOR", "QUIZ", "CAT", "SEEK", "QUIZZES", "SAT", "SACK", "SACKS"};
    Solution s;
    vector<string> ans=s.generateBoggles(board, dictionary);

    for (const string& word : ans) {
        cout << word << endl;
    }

}