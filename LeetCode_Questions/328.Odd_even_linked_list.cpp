class Solution
{
public:
    int length(ListNode *head)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode *oddEvenList(ListNode *head)
    {

        ListNode *result = new ListNode();
        ListNode *dummy1 = result;

        int len = length(head);
        if (len <= 2)
        {
            return head;
        }

        ListNode *odd = head;
        while (odd != NULL && odd->next != NULL)
        {
            // cout<<odd->val<<" ";
            ListNode *newnode = new ListNode(odd->val);
            dummy1->next = newnode;
            dummy1 = dummy1->next;
            odd = odd->next->next;
        }

        if (len % 2 != 0)
        {
            ListNode *newnode = new ListNode(odd->val);
            dummy1->next = newnode;
            dummy1 = dummy1->next;
        }

        ListNode *even = head->next;
        while (even && even->next)
        {

            ListNode *newnode = new ListNode(even->val);
            dummy1->next = newnode;
            dummy1 = dummy1->next;
            even = even->next->next;
        }
        if (len % 2 == 0)
        {
            ListNode *newnode = new ListNode(even->val);
            dummy1->next = newnode;
            dummy1 = dummy1->next;
        }
        return result->next;
    }
};