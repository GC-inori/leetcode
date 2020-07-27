同上题
首先动态规划处理f[i][j] 表示s[i~j]是否是回文串
如果i==j 显然f[i][j]=1;
如果s[i]!=s[j]不是回文串
s[i]==s[j]
1.i==j-1此时只有两个字符组成 f[i][j]=1
2.j-1>i 此时f[i][j]=f[i+1][j-1] 
然后dp[i] 表示s[0~i-1] 可以分成几个回文部分 枚举以i-1为结尾的每一个字符串，记开始位置为j dp[i]=min(dp[i],dp[j]+1) 
class Solution {
public:
    int minCut(string s) 
    {
        if(s.empty()) return 0;
        const int n=s.size();
        vector<vector<bool>> f(n,vector<bool>(n,0));
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int len=1;len<=n;len++)
            for(int i=0;i+len-1<n;i++)
                if(len==1||(len==2&&s[i]==s[i+1]||(s[i]==s[i+len-1]&&f[i+1][i+len-2]))) f[i][i+len-1]=1;
        for(int i=0;i<n;i++)
            for(int j=i;~j;j--)
                if(f[j][i])
                    dp[i+1]=min(dp[i+1],1+dp[j]);
        return dp[n]-1;
    }
};
