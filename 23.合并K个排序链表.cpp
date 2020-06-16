�����д��ϲ���������������еݹ���δ���������ǰ��������зֳ������֣�ÿ���ֵݹ���кϲ���Ȼ�󽫵�ǰ���������ֺϲ��Ľ���ٽ��ж��ϲ�����
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(vector<ListNode*>& lists,int beg,int ed)  //beg�ϲ���ʼλ�� ed����λ�� 
    {
        if(beg==ed) return lists[beg];
        int mid=beg+ed>>1;
        ListNode* l=merge(lists,beg,mid);
        ListNode* r=merge(lists,mid+1,ed);
        ListNode* res=new ListNode,*cur=res;
        while(l&&r)
        {
            if(l->val<r->val)
            {
                cur->next=l;
                l=l->next;
            }
            else
            {
                cur->next=r;
                r=r->next;
            }
            cur=cur->next;
        }
        if(l) cur->next=l;
        else cur->next=r;
        cur=res;
        res=res->next;
        delete cur;
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()<2) return lists.empty()?NULL:lists[0];
        return merge(lists,0,lists.size()-1);
    }
};
