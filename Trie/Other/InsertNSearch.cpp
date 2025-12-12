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
        Trie() {root=new TrieNode();}

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
            crawler->isEndOfWord=true;
        }

        bool search(string word)
        {
            TrieNode *crawler=root;
            for(char c:word)
            {
                int index=c-'a';
                if(crawler->children[index]==NULL)
                {
                    return false;
                }
                crawler=crawler->children[index];
            }
            return crawler->isEndOfWord;
        }
        bool startsWith(string prefix)
        {
            TrieNode *crawler=root;

            for(char c:prefix)
            {
                int index=c-'a';
                if(crawler->children[index]==NULL)
                {
                    return false;
                }
                crawler=crawler->children[index];
            }
            return true;
        }
};

int main()
{
    Trie trie;
    trie.insert("abubakar");
    cout<<trie.search("abubakar")<<endl;
    cout<<trie.startsWith("bakar")<<endl;
}