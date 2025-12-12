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
        Trie() { root=new TrieNode();};

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
        bool searchHelper(TrieNode *currentNode,string &word,int index)
        {
            if(index==word.length())
            {
                return currentNode->isEndOfWord;
            }
            char c=word[index];
            if(c=='.')
            {
                for (int i = 0; i < 26; i++)
                {
                    if(currentNode->children[i]!=nullptr)
                    {
                        if(searchHelper(currentNode->children[i],word,index+1))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            else
            {
                int charIndex=c-'a';
                TrieNode *child=currentNode->children[charIndex];
                if(child==nullptr)
                {
                    return false;
                }
                return searchHelper(child, word, index+1);
            }
        }

        bool search(string word)
        {
            return searchHelper(root, word, 0);
        }
};

int main()
{
    vector<string> word={"dad","pad","mad","bad"};
    Trie trie;

    for(string s:word)
    {
        trie.insert(s);
    }
    cout << boolalpha;
    cout << "Searching for 'pad': " << trie.search("pad") << endl;
    cout << "Searching for '.ad': " << trie.search(".ad") << endl;
    cout << "Searching for 'b.d': " << trie.search("b.d") << endl;
    cout << "Searching for 'b.g': " << trie.search("b.g") << endl;
    cout << "Searching for '..d': " << trie.search("..d") << endl; 

}