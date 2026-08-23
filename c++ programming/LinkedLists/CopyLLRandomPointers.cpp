#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node
{
    public:
        int val;
        Node *next;
        Node *random;

        Node(int _val)
        {
            val = _val;
            next = NULL;
            random = NULL;
        }
};


class Solution
{
    public:
        int indexOf(Node* head, int target)
        {
            Node *temp = head;
            int index = 0;

            while (temp != NULL)
            {
                if (temp->val == target)
                {
                    return index;
                }

                temp = temp->next;
                index++;
            }

            return -1;
        }
        void Traverse(Node *head)
        {
            if(!head) return;

            while(head != NULL)
            {
                cout << head->val << " ";
                head=head->next;
            }
        }
        Node *copyRandom(Node* head)
        {
            if(!head) return NULL;

            unordered_map<Node*, Node*> mp;
            Node *newHead=new Node(head->val);
            Node *oldTemp=head->next;
            Node *newTemp=newHead;
            mp[head]=newHead;
            while(oldTemp != NULL)
            {
                Node *copyNode=new Node(oldTemp->val);
                mp[oldTemp]=copyNode;
                newTemp->next=copyNode;
                oldTemp=oldTemp->next;
                newTemp=newTemp->next;
            }

            oldTemp=head; newTemp=newHead;

            while (oldTemp != NULL)
            {
                newTemp->random=mp[oldTemp->random];
                oldTemp=oldTemp->next;
                newTemp=newTemp->next;
            }

            return newHead;
            
        }
};


int main()
{
    Node *head = new Node(7);
    Node *n2 = new Node(13);
    Node *n3 = new Node(11);
    Node *n4 = new Node(10);
    Node *n5 = new Node(1);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    Solution s;
    head->random = NULL;
    n2->random = head;
    n3->random = n5;
    n4->random = n3;
    n5->random = head;

    cout << "Original List: ";
    s.Traverse(head);
    
    Node *copiedHead = s.copyRandom(head);
    
    cout << "\nCopied List: ";
    s.Traverse(copiedHead);
}