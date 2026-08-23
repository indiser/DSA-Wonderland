// Date: 04/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
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
        ~Trie()
        {
            clear(root);
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
        void clear(TrieNode *node)
        {
            if(!node) return;
            for (int i = 0; i < 26; i++)
            {
                if(node->children[i] != nullptr) clear(node->children[i]);
            }
            delete node;
        }
};

// Time Complexity: O(S)  S = sum of all charecters in the input
// Space Complexity: O(S)
class Solution
{
    public:
        bool checkPrefixes(string &word, Trie &trie) 
        {
            TrieNode *crawler = trie.root;
            for (char c : word) {
                int index = c - 'a';
                crawler = crawler->children[index];
                if (crawler == nullptr || !crawler->isEndOfWord) return false;
            }
            return true;
        }
        string longestStringWithPrefix(vector<string> &str)
        {
            Trie trie;
            for(string &word: str) trie.insert(word);

            string result = "";
            for(string &word: str)
            {
                if(checkPrefixes(word, trie))
                {
                    if(word.length() > result.length() || (word.length() == result.length() && word < result)) result = word;
                }
            }

            return result;
        }
};

int main()
{
    vector<string> str={"a", "ap", "app", "appl", "apple", "apply"};

    Solution s;
    cout<<s.longestStringWithPrefix(str)<<endl;
    return 0;
}