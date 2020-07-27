f[i][j]��ʾs[0~i-1] �� t[0~j-1] ������
�߽�f[i][0]=1
���s[i-1]==t[j-1] ��ô�����ַ������t[0~j-1] 1.s[0~i-2]��t[j-2]�ĸ�����Ϊf[i-1][j-1]��ÿ��һ��t[j-2]�����Ժ�s[i-1]���Ŀ�꣩ 2.s[0~i-2] �� t[0~j-1]�ĸ�����Ϊf[i-1][j]
���s[i-1]��=t[j-1] ��ôֻ�ܴ�s[0~i-2]��ѡt[0~j-1] ��Ϊf[i-1][j] 
class Solution {
public:
    int numDistinct(string s, string t) 
    {
        const int m=s.size(),n=t.size();
        long long f[m+1][n+1];
        memset(f,0,sizeof(f));
        for(int i=0;i<=m;i++) f[i][0]=1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(s[i-1]==t[j-1])
                    f[i][j]=f[i-1][j-1]+f[i-1][j];
                else f[i][j]=f[i-1][j]; 
        return f[m][n];
    }
    //�Ż�һά�ռ� 
    int numDistinct(string s, string t) 
    {
        const int m=s.size(),n=t.size();
        long long f[n+1];
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=1;i<=m;i++)
            for(int j=n;j;j--)
                if(s[i-1]==t[j-1])
                    f[j]+=f[j-1];
        return f[n];
    }
};
