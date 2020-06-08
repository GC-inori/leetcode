状态初始化：f[0][0] = true 其他f[i][j]=0 

状态转移：
s[i] == p[j] || p[j] == '.'，这时候是精准匹配，所以取决于s的前i - 1个字符和p的前j - 1个字符是否匹配。f[i][j] = f[i - 1][j - 1];
p[j] = '*'，根据*前的字符和s当前字符能否匹配分为两种情况：
如果不能匹配，那么*只能代表0个字符，这时候取决于s的前i个字符和p的前j - 2个字符是否匹配。f[i][j] = f[i][j - 2];

如果能匹配有2种可能的情况，需要对这两种情况取或：
代表0个字符，这时候这时候取决于s的前i个字符和p的前j - 2个字符是否匹配。f[i][j] = f[i][j - 2];
p[j-1]==s[i]||p[j-1]=='.'时 
代表1或多个字符，这时候这时候取决于s的前i-1个字符和p的前j个字符是否匹配。f[i][j] = f[i-1][j];
因为如果s的前i-1个字符和p的前j个字符匹配，那么s[i]与p[j]匹配，因为只需要*p[j]多匹配一个即可 

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        s=" "+s;
        p=" "+p;
        const int ns=s.size(),np=p.size();
        bool f[ns][np];
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=0;i<ns;i++)
            for(int j=1;j<np;j++)
            {
                if(j<np-1&&p[j+1]=='*') j++;
                if(i&&(s[i]==p[j]||p[j]=='.')) f[i][j]=f[i-1][j-1];  //如果i=0时只可能和 x*匹配  不可能是是s[i]==p[j] 
                else if(p[j]=='*')
                    f[i][j]=f[i][j-2]||(i&&(p[j-1]=='.'||p[j-1]==s[i])&&f[i-1][j]); //p[j-1]匹配多个 
            }
        return f[ns-1][np-1];
    }
};
