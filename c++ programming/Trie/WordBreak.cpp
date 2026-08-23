// Date: 03/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TrieNode
{
    public:
        TrieNode *children[26];
        bool isEndOfWord;

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
        Trie()
        {
            root = new TrieNode();
        }
        void insert(string &word)
        {
            TrieNode *crawler=root;

            for(char c:word)
            {
                int index=c-'a';
                if(!crawler->children[index])
                {
                    crawler->children[index]=new TrieNode;
                }
                crawler=crawler->children[index];
            }
            crawler->isEndOfWord=true;
        }
};

// Time Complexity: O(n^2 + m)
// Space Complexity: O(n + m)
class Solution
{
    public:
        bool wordBreakHealper(const string &str, int start, Trie &trie, vector<int> &memo)
        {
            if(start == str.length()) return true;
            if(memo[start] != -1) return memo[start];

            TrieNode *crawler = trie.root;
            for (int i = start; i < str.length(); i++)
            {
                int index = str[i] - 'a';
                if(!crawler->children[index]) break;

                crawler = crawler->children[index];
                if(crawler->isEndOfWord)
                {
                    if(wordBreakHealper(str, i+1, trie, memo)) return memo[start] = 1;
                }
            }
            return memo[start] = 0;
        }
        bool wordBreak(string str, vector<string> &wordDict)
        {
            if(str.empty() || wordDict.empty()) return false;
            Trie trie;

            for(auto &word: wordDict)
            {
                if(word.empty()) return false;
                trie.insert(word);
            }

            vector<int> memo(str.length(), -1);
            return wordBreakHealper(str, 0, trie, memo);
        }
};

int main()
{
    vector<string> wordDict = {"leet", "code"};
    string str = "leetcode";

    Solution s;
    if(s.wordBreak(str, wordDict)) 
        cout<<"True";
    else
        cout<<"False";
    return 0;
}