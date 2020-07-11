动态规划
f[len][i][j] 表示s1[i~i+len-1] 和 s2[j~j+len-1] 是不是扰乱字符串
class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        const int n=s1.size();
        bool f[n+1][n][n];
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                f[1][i][j]=s1[i]==s2[j];//f[1][i][j]表示s1[i]是否等于s2[j] 
        for(int len=2;len<=n;len++) //枚举字符串长度 
            for(int l1=0;l1+len<=n;l1++) //s1开始位置 
                for(int l2=0;l2+len<=n;l2++) //s2的开始位置 
                    for(int k=1;k<len;k++) //将s1和s2分为两部分 第一部分长为k 第二部分 len-k 
                        if((f[k][l1][l2]&&f[len-k][l1+k][l2+k])|| //如果不需要交换 
                           (f[k][l1][l2+len-k]&&f[len-k][l1+k][l2])) //需要交换两部分 
                        {
                            f[len][l1][l2]=1;
                            break; //有一种交换方式成立就返回 
                        }
        return f[n][0][0];
    }
};
