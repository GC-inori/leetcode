��̬�滮
f[i]��ʾǰi���ַ����Ա�ʾ�ķ�����
f[0]=1; 
���s[i-1] ��1-9֮��Ļ� f[i]+=f[i-1];
���s[i-2]s[i-1] ��10-26֮��Ļ� f[i-1]+=f[i-2]; 
class Solution {
public:
    int numDecodings(string s) 
    {
        const int n=s.size();
        int f[n+1];
        f[0]=1,f[1]=s[0]!='0';
        for(int i=1,t;i<n;i++)
        {
            f[i+1]=0;
            if(s[i]!='0') f[i+1]+=f[i];//����ǺϷ�һλ�� 
            t=s[i]-'0'+10*(s[i-1]-'0');//���������λ���Ĵ�С 
            if(t>=10&&t<=26) f[i+1]+=f[i-1];
        }
        return f[n];    
    }
};
