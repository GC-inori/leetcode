��s=ss+t ���� ssΪ���Ĵ�
��Ŀ��Ϊ ~t+ss+t ~t��ʾt�ķ�ת�ַ���
Ҫ��~t��С ��ss��� ��Ҫ��ss�����ǰ׺
��p=ss+t+" "+~t+~ss;
����ssΪ���Ĵ���ss=~ss��
����p���ǰ׺�ͺ�׺��ȵĳ���
kmp�㷨 
class Solution {
public:
    string shortestPalindrome(string s) 
    {
        string t=s;
        s=s+' '+string(s.rbegin(),s.rend())+'&';
        const int n=s.size();
        int Next[n];
        int k=Next[0]=-1,i=0;
        while(i<n)
        {
            while(~k&&s[i]!=s[k]) k=Next[k];
            i++,k++;
            if(i>=n) break;
            Next[i]=k;
        }
        s=t.substr(Next[n-1]);
        return string(s.rbegin(),s.rend())+t;
    }
};
