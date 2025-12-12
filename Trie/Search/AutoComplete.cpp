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

void insert(TrieNode *root, string word)
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

bool startsWith(TrieNode *root, string word)
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
    return true;
}

void collectWords(TrieNode *node, string currentPrefix, vector<string> &results)
{
    if(node->isEndOfWord==true)
    {
        results.push_back(currentPrefix);
    }
    for (int i = 0; i < 26; i++)
    {
        if(node->children[i]!=NULL)
        {
            char nextChar = 'a' + i;
            collectWords(node->children[i], currentPrefix + nextChar, results);
        }
    }
    
}

int main()
{
    vector<string> list={"cat", "car", "cart", "dog"};
    TrieNode *root=new TrieNode();

    for(string s:list)
    {
        insert(root,s);
    }

    string prefix="ca";
    
    TrieNode *prefixNode=root;
    bool prefixExists=true;
    vector<string> result;
    for(char c:prefix)
    {
        int index=c-'a';
        if(prefixNode->children[index])
        {
            prefixNode=prefixNode->children[index];
        }
        else
        {
            prefixExists=false;
            break;
        }
    }
    if(prefixExists)
    {
        collectWords(prefixNode,prefix,result);
    }

    for(string s:result)
    {
        cout<<s<<endl;
    }
}
