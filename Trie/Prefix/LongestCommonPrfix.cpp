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
        Trie() {root=new TrieNode();};

        void insert(string word)
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

        string longestCommonPrefix()
        {
            string result="";
            TrieNode *crawler=root;

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
    vector<string> prefix={"flower","flow","flight"};
    Trie trie;
    for(const string& s:prefix)
    {
        trie.insert(s);
    }
    cout<<trie.longestCommonPrefix()<<endl;
}