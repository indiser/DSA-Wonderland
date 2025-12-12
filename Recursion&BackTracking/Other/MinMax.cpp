#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution
{
    public:
        int evaluate(vector<vector<char>> &board)
        {
            for (int row = 0; row < 3; row++)
            {
                if(board[row][0]!=' ' &&board[row][0]==board[row][1] && board[row][1]==board[row][2])
                {
                    return board[row][0]=='X' ? 10 : -10;
                }
            }

            for (int col = 0; col < 3; col++)
            {
                if(board[0][col]!=' ' && board[0][col]==board[1][col] && board[1][col]==board[2][col])
                {
                    return board[0][col]=='X' ? 10 : -10;

                }
            }

            if(board[0][0]!=' ' && board[0][0]==board[1][1] && board[1][1]==board[2][2])
            {
                return board[0][0]=='X' ? 10 : -10;
            }

            if(board[0][2]!=' ' && board[0][2]==board[1][1] && board[1][1]==board[2][0])
            {
                return board[0][2]=='X' ? 10 : -10;

            }
            return 0;
            
        }
        bool areMovesLeft(vector<vector<char>> &board)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if(board[i][j]==' ')
                    {
                        return true;
                    }
                }
                
            }
            return false;
            
        }
        int minmax(vector<vector<char>> &board, bool isMaxTurn)
        {
            int score=evaluate(board);

            if(score==10 || score==-10 || !areMovesLeft(board))
            {
                return score;
            }
            
            if(isMaxTurn)
            {
                int bestScore=INT_MIN;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if(board[i][j]==' ')
                        {
                            board[i][j]='X';
                            bestScore=max(bestScore,minmax(board,!isMaxTurn));
                            board[i][j]=' ';
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                int bestScore=INT_MAX;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if(board[i][j]==' ')
                        {
                            board[i][j]='O';
                            bestScore=min(bestScore,minmax(board,!isMaxTurn));
                            board[i][j]=' ';
                        }
                    }
                }
                return bestScore;
            }

        }
        pair<int,int> findBestMove(vector<vector<char>> &board)
        {
            int bestScore=-10000;
            pair<int,int> bestMove={-1,-1};

            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    if(board[row][col]==' ')
                    {
                        board[row][col]='X';
                        int moveScore=minmax(board,false);
                        board[row][col]=' ';
                        if(moveScore>bestScore)
                        {
                            bestScore=moveScore;
                            bestMove={row,col};
                        }
                    }
                    
                }
            }
            return bestMove;
        }
};

int main()
{
    vector<vector<char>> board={
        {'X', 'O', 'X'},
        {'X', 'X', 'O'},
        {'O', 'O', ' '}
    };

    Solution s;
    pair<int,int> move = s.findBestMove(board);
    cout << "(" << move.first << ", " << move.second << ")" << endl;
    board[move.first][move.second]='X';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    
}