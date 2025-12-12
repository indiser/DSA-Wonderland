#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;
    int visitedCount;
    TrieNode()
    {
        isEndOfWord = false;
        visitedCount = 0;
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
            crawler->visitedCount++;
        }
        crawler->isEndOfWord = true;
    }
    string shortestPrefix(string word)
    {
        TrieNode *crawler = root;
        string prefix = "";
        vector<string> ans;
        for (char c : word)
        {
            int index = c - 'a';
            crawler = crawler->children[index];
            prefix.push_back(c);
            if (crawler->visitedCount == 1)
            {
                return prefix;
            }
        }
        return word;
    }
};

int main()
{
    vector<string> words = {"dog", "duck", "dove"};
    Trie trie;
    for (string s : words)
    {
        trie.insert(s);
    }
    vector<string> prefixes;
    for(string s:words)
    {
        prefixes.push_back(trie.shortestPrefix(s));
    }

    for(string s : prefixes)
    {
        cout << s << " ";
    }
}