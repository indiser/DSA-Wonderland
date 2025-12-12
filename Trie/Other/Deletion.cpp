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

        // bool hasNoChildren(TrieNode *node)
        // {
        //     for (int i = 0; i < 26; i++)
        //     {
        //         if(node->children[i])
        //             return false;
        //     }
        //     return true;
        // }
        // TrieNode *deleteHelper(TrieNode *currentNode,string &word, int depth)
        // {
        //     if(!currentNode)
        //         return nullptr;
            
        //     if(depth==word.length())
        //     {
        //         if(currentNode->isEndOfWord)
        //             currentNode->isEndOfWord=false;
                
        //         if(hasNoChildren(currentNode) && !currentNode->isEndOfWord)
        //         {
        //             delete currentNode;
        //             currentNode=nullptr;
        //         }
        //         return currentNode;
        //     }
        //     int index=word[depth]-'a';
        //     currentNode->children[index]=deleteHelper(currentNode->children[index],word,depth+1);
        //     if(hasNoChildren(currentNode) && !currentNode->isEndOfWord)
        //     {
        //         delete currentNode;
        //         currentNode=nullptr;
        //     }
        //     return currentNode;
        // }

    public:
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

        

        // void deleteTrie(string word)
        // {
        //     root=deleteHelper(root,word,0);
        // }

        void deleteWord(string word)
        {
            TrieNode *crawler=root;
            for(char c:word)
            {
                int index=c-'a';
                if(!crawler->children[index])
                    return;
                crawler=crawler->children[index];
            }
            if(crawler->isEndOfWord==true)
                crawler->isEndOfWord=false;
        }

        void printTrie(TrieNode *node, string prefix)
        {
            if(node->isEndOfWord)
            {
                cout<<prefix<<" ";
            }
            for (int i = 0; i < 26; i++)
            {
                if(node->children[i])
                {
                    printTrie(node->children[i],prefix+char('a'+i));
                }
            }
            
        }

        void printTrie() {printTrie(root,"");};

};

int main()
{
    Trie trie;

    trie.insert("abubakar");
    trie.insert("allahuakbar");
    trie.printTrie();
    cout<<endl;
    // trie.deleteTrie("abubakar");
    trie.deleteWord("abubakar");
    trie.printTrie();
}