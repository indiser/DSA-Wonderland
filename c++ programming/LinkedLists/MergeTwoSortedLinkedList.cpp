#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Time Complexity: O(n+m)
//Space Complexity:O(1)

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
        void Traversal(ListNode *head)
        {
            while (head != NULL)
            {
                cout<<head->val<<" ";
                head=head->next;
            }
            
        }
        
        ListNode *merge(ListNode *list1, ListNode *list2)
        {
            if(list1==NULL)
            {
                return list2;
            }
            if(list2==NULL)
            {
                return list1;
            }
            
            if(list1->val <= list2->val)
            {
                list1->next = merge(list1->next, list2);
                return list1;
            }
            else
            {
                list2->next = merge(list1, list2->next);
                return list2;
            }
        }
};

int main()
{
    ListNode *list1=new ListNode(1);
    list1->next=new ListNode(2);
    list1->next->next=new ListNode(4);

    ListNode *list2=new ListNode(1);
    list2->next=new ListNode(3);
    list2->next->next=new ListNode(4);

    ListNode *list3=NULL;
    Solution s;
    s.Traversal(list1);
    cout<<endl;
    s.Traversal(list2);
    cout<<endl;
    list3=s.merge(list1,list2);
    s.Traversal(list3);
}