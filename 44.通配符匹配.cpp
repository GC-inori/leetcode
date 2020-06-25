第十题类似，双字符串匹配问题，用动态规划。
状态表示：f[i][j]代表s的前i-1个字符和p的前j-1个字符是否匹配。

状态初始化：f[0][0] = true，对于1 <= i <= m如果p[i - 1] = '*' && f[0][i - 1]那么f[0][i] = true，
			这对应着p以***as开头的字符串，因为*可以代表0个字符，所以可以往后匹配。
状态转移：
1.s[i - 1] == p[j - 1] || p[j - 1] == '?'，这时候是精准匹配，所以取决于s的前i - 1个字符和p的前j - 1个字符是否匹配。f[i][j] = f[i - 1][j - 1];
2.p[j - 1] == '*'，这个时候*可以代表空串或者任意多个字符。
	如果代表空串，那么dp[i][j] = dp[i][j - 1]
	如果不是空串，那么dp[i][j] = dp[i - 1][j]。这是因为*代表了任意多个字符，如果能匹配前i - 1个字符，那么就在*代表的字符串后面加上s[i]，就可以匹配前i个字符。
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        const int n=s.size(),m=p.size();
        bool f[n+1][m+1];
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=0;i<m;i++)
        {
            if(p[i]=='*') f[0][i+1]=1;
            else break;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(p[j-1]=='?'||p[j-1]==s[i-1]) f[i][j]=f[i-1][j-1];
                else if(p[j-1]=='*')
                    f[i][j]=f[i-1][j]||f[i][j-1];
            }
        return f[n][m];
    }
};
