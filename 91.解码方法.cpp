动态规划
f[i]表示前i个字符可以表示的方案数
f[0]=1; 
如果s[i-1] 在1-9之间的话 f[i]+=f[i-1];
如果s[i-2]s[i-1] 在10-26之间的话 f[i-1]+=f[i-2]; 
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
            if(s[i]!='0') f[i+1]+=f[i];//如果是合法一位数 
            t=s[i]-'0'+10*(s[i-1]-'0');//计算组成两位数的大小 
            if(t>=10&&t<=26) f[i+1]+=f[i-1];
        }
        return f[n];    
    }
};
