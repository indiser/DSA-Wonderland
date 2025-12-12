#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution
{
    public:
        void Traversel(ListNode *head)
        {
            while (head != NULL)
            {
                cout << head->val << " ";
                head = head->next;
            }
        }

        ListNode *middleLinkedList(ListNode *head)
        {
            ListNode *slow=head;
            ListNode *fast=head;

            while(fast != NULL && fast->next != NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            }

            return slow;
        }

};

int main()
{
    ListNode *head=new ListNode(1);
    ListNode *curr=head;
    for(int i=2;i<=5;i++)
    {
        curr->next=new ListNode(i);
        curr=curr->next;
    }

    Solution s;
    s.Traversel(head);
    ListNode *middle = s.middleLinkedList(head);
    cout<<"The middle node value : "<<middle->val<<endl;
    return 0;
}