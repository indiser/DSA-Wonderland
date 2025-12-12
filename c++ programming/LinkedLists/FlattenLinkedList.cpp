#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node
{
    public:
        int val;
        Node *prev;
        Node *next;
        Node *child;
        
        Node(int v)
        {
            val=v;
            prev=nullptr;
            next=nullptr;
            child=nullptr;
        }
};

class Solution
{
    public:
        void Traverse(Node *head)
        {
            if(!head) return;
            
            cout << head->val << " ";
            
            if(head->child) {
                Traverse(head->child);
            }
            
            Traverse(head->next);
        }
        Node *flatten(Node *head)
        {
            
        }
};

int main()
{
    // Create main list: 1-2-3-4-5-6
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;
    
    // Create child list: 7-8-9-10
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;
    
    // Create grandchild list: 11-12
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);
    
    n11->next = n12; n12->prev = n11;
    
    // Connect child relationships
    n3->child = n7;  // 3 points to 7
    n8->child = n11; // 8 points to 11

    Solution s;
    s.Traverse(n1);
    
    return 0;
}