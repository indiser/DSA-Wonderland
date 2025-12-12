#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); };

    void insert(string word)
    {
        TrieNode *crawler = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (!crawler->children[index])
            {
                crawler->children[index] = new TrieNode();
            }
            crawler = crawler->children[index];
        }
        crawler->isEndOfWord = true;
    }

    vector<string> splitSentence(string str)
    {
        vector<string> ans;
        int len = str.length();
        int index = 0;

        string word = "";
        for (int i = 0; i < len; i++)
        {
            if (isblank(str[i]))
            {
                if (!word.empty())
                {
                    ans.push_back(word);
                    word = "";
                }
            }
            else
            {
                word += str[i];
            }
        }
        if (!word.empty())
        {
            ans.push_back(word);
        }
        
        return ans;
    }
    string findShortestRoot(string word)
    {
        TrieNode *crawler=root;
        string prefix="";
        for(char c:word)
        {
            int index=c-'a';
            
            if(crawler->children[index]==nullptr)
            {
                return word;
            }
            crawler=crawler->children[index];
            prefix.push_back(c);
            if(crawler->isEndOfWord)
            {
                return prefix;
            }
        }
        return word;
    }
};

int main()
{
    string sentence="the cattle was rattled by the battery";
    vector<string> list={"cat","rat","bat"};
    Trie trie;
    for(string s:list)
    {
        trie.insert(s);
    }
    vector<string> ans=trie.splitSentence(sentence);
    string result="";
    for(string s:ans)
    {
        result+=trie.findShortestRoot(s)+" ";
    }
    cout<<result<<endl;

}