#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

class TrieNode
{
    public:
        TrieNode *children[26];
        bool isEndOfWord;
        string word="";
        TrieNode()
        {
            isEndOfWord=false;
            for (int i = 0; i < 26; i++)
            {
                children[i]=nullptr;
            }
            
        }
};

class Trie
{
    public:
        TrieNode *root;
        Trie() {root= new TrieNode();};

        void insert(string word)
        {
            TrieNode *crawler=root;
            for(char c:word)
            {
                int index=c-'a';
                if(!crawler->children[index])
                {
                    crawler->children[index]=new TrieNode();
                }
                crawler=crawler->children[index];
            }
            crawler->word=word;
        }
};

class Solution
{
    public:
        void searchWords(vector<vector<char>> &board,int row,int col,TrieNode *node,set<string> &ans)
        {
            if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            {
                return;
            }

            if(board[row][col]=='#')
            {
                return;
            }

            char c=board[row][col];
            int index = c - 'a';

            if(node->children[index] == nullptr)
            {
                return;
            }

            node=node->children[index];

            if(!node->word.empty())
            {
                ans.insert(node->word);
                node->word="";
            }



            char original=board[row][col];
            board[row][col]='#';

            
            searchWords(board,row+1,col,node,ans);
            searchWords(board,row-1,col,node,ans);
            searchWords(board,row,col+1,node,ans);  
            searchWords(board,row,col-1,node,ans);  

            board[row][col]=original;


        }
        vector<string> wordSearch(vector<vector<char>> &board, vector<string> &words)
        {
            set<string> result;
            Trie trie;
            for (const string& word : words) {
                trie.insert(word);
            }
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[0].size(); j++)
                {
                    searchWords(board,i,j,trie.root,result);
                }
                
            }
            vector<string> ans(result.begin(),result.end());
            return ans;
        }
};

int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};
    Solution s;
    vector<string> ans=s.wordSearch(board,words);
    for(const auto& s:ans)
    {
        for(auto val:s)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}