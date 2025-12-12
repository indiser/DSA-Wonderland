#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TrieNode
{
    public:
        TrieNode *children[26];
        bool isEndOfWord;
        int value;

        TrieNode()
        {
            value=0;
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
        Trie() { root=new TrieNode();};

        void insert(string word, int val)
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
            crawler->value=val;
        }

        int sumHelper(TrieNode *node)
        {
            int total=node->value;
            for (int i = 0; i < 26; i++)
            {
                if(node->children[i]!=nullptr)
                {
                    total+=sumHelper(node->children[i]);
                }
            }
            return total;
        }

        int sum(string prefix)
        {
            TrieNode *crawler=root;
            for(char c:prefix)
            {
                int index=c-'a';
                if(crawler->children[index]==nullptr)
                {
                    return 0;
                }
                crawler=crawler->children[index];
            }
            return sumHelper(crawler);
        }
};

int main()
{
    Trie trie;
    trie.insert("apple",3);
    cout<<trie.sum("ap")<<endl;
    trie.insert("app",2);
    cout<<trie.sum("ap")<<endl;
}