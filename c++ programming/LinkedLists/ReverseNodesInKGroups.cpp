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

// Time Complexity: O(n) - traverse the list once
// Space Complexity: O(n/k) - recursion stack depth
class Solution
{
    public:
        void Traverse(ListNode *head)
        {
            if(!head) return;

            while(head != NULL)
            {
                cout << head->val <<endl;
                head=head->next;
            }
        }
        ListNode *reverseKGroups(ListNode *head, int k)
        {
            ListNode *temp=head;
            int cnt=0;

            while (cnt < k)
            {
                if(temp==NULL) return head;
                temp=temp->next;
                cnt++;
            }

            ListNode *prevNode = reverseKGroups(temp,k);

            temp=head,cnt=0;

            while(cnt < k)
            {
                ListNode *next=temp->next;
                temp->next=prevNode;
                prevNode=temp;
                temp=next;
                cnt++;
            }

            return prevNode;
            
        }
};

// Time Complexity: O(n) - traverse the list once
// Space Complexity: O(n/k) - recursion stack depth
class Solution2
{
    public:
        ListNode* reverseWindow(ListNode* start, ListNode* end)
        {
            ListNode *prev = end, *curr = start;
            while(curr != end)
            {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }

        ListNode* reverseKGroups(ListNode* head, int k)
        {
            ListNode *start = head, *end = head;
            int cnt = 0;
            
            while(end && cnt < k)
            {
                end = end->next;
                cnt++;
            }
            
            if(cnt < k) return head;
            
            ListNode *newHead = reverseWindow(start, end);
            start->next = reverseKGroups(end, k);
            
            return newHead;
        }
};

// Time Complexity: O(n) - traverse the list once
// Space Complexity: O(1) - iterative approach with constant space
class Solution3
{
    public:
        ListNode* reverseKGroups(ListNode* head, int k)
        {
            ListNode dummy(0);
            dummy.next = head;
            ListNode *prevGroup = &dummy;
            
            while(true)
            {
                ListNode *kth = getKth(prevGroup, k);
                if(!kth) break;
                
                ListNode *groupNext = kth->next;
                ListNode *prev = kth->next, *curr = prevGroup->next;
                
                while(curr != groupNext)
                {
                    ListNode *next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                
                ListNode *temp = prevGroup->next;
                prevGroup->next = kth;
                prevGroup = temp;
            }
            
            return dummy.next;
        }
        
    private:
        ListNode* getKth(ListNode* curr, int k)
        {
            while(curr && k > 0)
            {
                curr = curr->next;
                k--;
            }
            return curr;
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

    Solution s;
    s.Traverse(head);

    cout << "After operation" <<endl;
    int k=2;
    head=s.reverseKGroups(head,k);
    s.Traverse(head);
}