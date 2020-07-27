f[i][j]表示s[0~i-1] 中 t[0~j-1] 的数量
边界f[i][0]=1
如果s[i-1]==t[j-1] 那么有两种方法组成t[0~j-1] 1.s[0~i-2]中t[j-2]的个数即为f[i-1][j-1]（每有一个t[j-2]都可以和s[i-1]组成目标） 2.s[0~i-2] 中 t[0~j-1]的个数即为f[i-1][j]
如果s[i-1]！=t[j-1] 那么只能从s[0~i-2]中选t[0~j-1] 即为f[i-1][j] 
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
    //优化一维空间 
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
