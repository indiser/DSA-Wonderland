#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class ListNode
{
    public:
        int val;
        ListNode *next;

        ListNode()
        {
            val=0;
            next=NULL;
        }
        
        ListNode(int _val)
        {
            val=_val;
            next=NULL;
        }

        ListNode(int _val, ListNode *_next)
        {
            val=_val;
            next=_next;
        }
};

/*
Time Complexity: O(max(m, n)) where m and n are lengths of the two linked lists
Space Complexity: O(max(m, n)) for the result linked list
*/
class Solution
{
    public:
        void Traverse(ListNode *head)
        {
            if (!head) return;

            while(head != NULL)
            {
                cout << head->val << endl;
                head=head->next;
            }
        }
        ListNode *addTwoNumbers(ListNode *node1, ListNode *node2)
        {
            if (!node1) return node2;
            if (!node2) return node1;

            ListNode *addNode=new ListNode();
            ListNode *curr=addNode;
            int carry=0;

            while (node1 != NULL || node2 != NULL || carry != 0)
            {
                int sum=carry;
                
                if (node1 != NULL)
                {
                    sum+=node1->val;
                    node1=node1->next;
                }
                
                if (node2 != NULL)
                {
                    sum+=node2->val;
                    node2=node2->next;
                }

                carry=sum/10;
                curr->next=new ListNode(sum %10);
                curr=curr->next;
            }
            return addNode->next;
        }
};

int main()
{
    ListNode *node1=new ListNode(2);
    ListNode *n2= new ListNode(4);
    ListNode *n3=new ListNode(3);

    node1->next=n2;
    n2->next=n3;
    n3->next=NULL;

    ListNode *node2=new ListNode(5);
    ListNode *m3=new ListNode(6);
    ListNode *m4=new ListNode(4);

    node2->next=m3;
    m3->next=m4;
    m4->next=NULL;

    Solution s;

    ListNode *result=s.addTwoNumbers(node1,node2);

    s.Traverse(result);

    return 0;
    
}