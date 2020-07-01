线性dp 
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        const int m=word1.size(),n=word2.size();
        int f[m+1][n+1];
        memset(f,0x3f,sizeof(f));
        for(int i=0;i<=n;i++) f[0][i]=i;
        for(int i=1;i<=m;i++)
            for(int j=0;j<=n;j++)
                if(!j) f[i][j]=i;
                else
                {
                    if(word1[i-1]==word2[j-1]) f[i][j]=f[i-1][j-1];  //如果两字母相等 
                    else f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
                }
        return f[m][n];
    }
};
