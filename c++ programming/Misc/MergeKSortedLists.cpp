#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
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


        // ListNode *mergeKLists(vector<ListNode*> &lists)
        // {
        //     if (lists.empty())
        //     {
        //         return nullptr;
        //     }

        //     ListNode *head = lists[0];

        //     for (size_t i = 1; i < lists.size(); i++)
        //     {
        //         head = merge(head, lists[i]);
        //     }
        //     return head;
        // }

        // Time Complexity: O(N * logK)
        // Space Complexity: O(K)
        ListNode *mergeKLists(vector<ListNode*> &lists)
        {
            if (lists.empty()) return nullptr;
            ListNode *dummy = new ListNode(-1);
            ListNode *temp = dummy;
            priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;

            for (int i = 0; i < lists.size(); i++)
            {
                if(lists[i]) minHeap.push({lists[i]->val, lists[i]});
            }

            while(!minHeap.empty())
            {
                auto p = minHeap.top();
                minHeap.pop();

                if(p.second->next) minHeap.push({p.second->next->val, p.second->next});

                temp->next = p.second;
                temp = temp->next;
            }
            return dummy->next;
        }
};

int main()
{
    ListNode *list1=new ListNode(1);
    list1->next=new ListNode(4);
    list1->next->next=new ListNode(5);

    ListNode *list2=new ListNode(1);
    list2->next=new ListNode(3);
    list2->next->next=new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    ListNode *temp=NULL;
    Solution s;

    s.Traversal(list1);
    cout<<endl;

    s.Traversal(list2);
    cout<<endl;

    s.Traversal(list3);
    cout<<endl;

    vector<ListNode*> lists = {list1, list2, list3};
    temp = s.mergeKLists(lists);
    s.Traversal(temp);

    return 0;
}