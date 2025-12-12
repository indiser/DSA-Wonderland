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
    private:
        TrieNode *root;
    public:
        int count=0;
        Trie() {root=new TrieNode;};

        void insert(string word)
        {
            TrieNode *crawler=root;
            for(char c:word)
            {
                int index=c-'a';
                if(!crawler->children[index])
                {
                    crawler->children[index]=new TrieNode;
                    count++;
                }
                crawler=crawler->children[index];
            }
            crawler->isEndOfWord=true;
        }
};

class Solution
{
    public:
        int countSubstrings(string str)
        {
            Trie trie;
            int len=str.length();
            for (int i = 0; i < len; i++)
            {
                string prefix=str.substr(i);
                trie.insert(prefix);
            }
            return trie.count;
        }
};
int main()
{
    string str="aba";
    Solution s;
    cout<<s.countSubstrings(str)<<endl;
}