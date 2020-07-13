f[i][j] 表示s10~i-1  s2 0~j-1能否匹配 s3 0~i+j-1
边界f[0][0]=1;
递推如果f[i][j]=1 s1[i]==s3[i+j] f[i+1][j]=1
				  s2[j]==s3[i+j] f[i][j+1]=1;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        const int m=s1.size(),n=s2.size();
        if(s3.size()!=m+n) return 0;
        bool f[m+1][n+1];
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                if(f[i][j])
                {
                    if(i<m&&s1[i]==s3[i+j]) f[i+1][j]=1;//i<m防止越界 
                    if(j<n&&s2[j]==s3[i+j]) f[i][j+1]=1;
                }
        return f[m][n]; 
    }
};
