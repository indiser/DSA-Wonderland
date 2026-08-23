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

// Time Complexity: O(n * m)
// Space Comeplxity: O(n * m)
class Solution
{
    public:
        string longestCommonPrefix(vector<string> &str)
        {
            if(str.empty()) return "";

            Trie trie;

            for (string &word : str) 
            {
                if (word.empty()) return "";
                trie.insert(word);
            }
            TrieNode *crawler = trie.root;
            
            string result = "";
            while(true)
            {
                if(crawler->isEndOfWord)
                    break;
                int chlidCount=0;
                int nextNodeIndex=-1;

                for (int i = 0; i < 26; i++)
                {
                    if(crawler->children[i]!=nullptr)
                    {
                        chlidCount++;
                        nextNodeIndex=i;
                    }
                }
                if(chlidCount!=1)
                    break;
                result.push_back('a'+nextNodeIndex);
                crawler=crawler->children[nextNodeIndex];
            }
            return result;
        }
};

int main()
{
    vector<string> str={"flower", "flow", "flight"};

    Solution s;
    cout<<s.longestCommonPrefix(str)<<endl;
    return 0;
}