#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int _val)
    {
        val=_val;
        next=nullptr;
    }
};

/*
 * Time Complexity: O(n) - traverse list twice (once to find length, once to find rotation point)
 * Space Complexity: O(1) - only using pointers, no extra space
 */
class Solution
{
    public:
        void traverse(ListNode *head)
        {
            if(!head) return;

            while(head != NULL)
            {
                cout << head->val << endl;
                head=head->next;
            }
        }

        ListNode *findLastNode(ListNode *head, int k)
        {
            int count=1;
            while(head != NULL)
            {
                if(count==k) return head;
                head=head->next;
                count++;
            }
            return head;
        }
        ListNode *rotateRight(ListNode *head, int k)
        {
            if(!head || k==0) return head;
            ListNode *tail=head;

            int length = 1;

            while (tail->next != NULL)
            {
                tail=tail->next;
                length++;
            }
            if(k % length == 0) return head;
            k=k%length;

            tail->next=head;
            ListNode *newLast=findLastNode(head, length -k);

            head=newLast->next;
            newLast->next=NULL;

            return head;
        }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *curr = head;

    for (int i = 2; i < 6; i++)
    {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    
    Solution sol;
    cout << "Original List:" << endl;
    sol.traverse(head);
    
    int k = 2;
    head = sol.rotateRight(head, k);
    
    cout << "\nRotated List (k=" << k << "):" << endl;
    sol.traverse(head);
    
    return 0;
}