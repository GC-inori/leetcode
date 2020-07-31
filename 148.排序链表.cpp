/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 �Ե����ϵĹ鲢���� 
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        int cnt=0;
        for(auto p=head;p;p=p->next) cnt++;//���������� 
        auto h=new ListNode(0),cur=h,p=head,q=p,ne=p;//p��һ���鲢����ʼλ�� q�ڶ����鲢����ʼλ�� ne��һ�ι鲢��ʼλ�� 
        h->next=head;//h����ͷ�ڵ� 
        for(int i=1;i<cnt;i<<=1)//i�鲢�γ��� 
        {
            cur=h;//cur����λ�� 
            for(int j=1;j+i<=cnt;j+=2*i)//ö�ٿ�ʼλ�� 
            {
                q=p=cur->next;
                for(int k=0;k<i&&q;k++) q=q->next;//q����ƶ�i������ڶ����鲢����ʼλ�� 
                ne=q;
                for(int k=0;k<i&&ne;k++) ne=ne->next;//ne����ƶ�i������ ne��һ�ι鲢��ʼλ�� 
                int n1=0,n2=0;
                while(n1<i&&n2<i&&p&&q)//�鲢 
                {
                    if(p->val<=q->val) cur=cur->next=p,p=p->next,n1++;
                    else cur=cur->next=q,q=q->next,n2++;
                }
                while(n1<i&&p) cur=cur->next=p,p=p->next,n1++;//�鲢ʣ��Ԫ�� 
                while(n2<i&&q) cur=cur->next=q,q=q->next,n2++;
                cur->next=ne;//���´ο�ʼλ�ýӹ��� 
            }
        }
        return h->next;
    }
};
