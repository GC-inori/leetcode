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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        auto h=new ListNode;
        h->next=head;//����ͷ�ڵ� 
        auto now=h;//��ǰλ�� 
        for(int i=1;i<m;i++)//�ҵ���m-1��λ�� 
            now=now->next;
        auto tail=now->next;//��ת��Ľ�β�ǵ�mλ�õ�Ԫ�� 
        auto p=now;//p��ͷ�巨��ͷ 
        now=now->next;//�ƶ�����mλ 
        for(int i=m;i<=n;i++)//ͷ�巨��ת���� 
        {
            auto tmp=now->next;
            now->next=p->next;
            p->next=now;
            now=tmp;
        }
        tail->next=now;//����βԪ�غ�֮������ƴ��һ�� 
        return h->next;
    }
};
