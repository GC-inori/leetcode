ͬ����
���ȶ�̬�滮����f[i][j] ��ʾs[i~j]�Ƿ��ǻ��Ĵ�
���i==j ��Ȼf[i][j]=1;
���s[i]!=s[j]���ǻ��Ĵ�
s[i]==s[j]
1.i==j-1��ʱֻ�������ַ���� f[i][j]=1
2.j-1>i ��ʱf[i][j]=f[i+1][j-1] 
Ȼ��dp[i] ��ʾs[0~i-1] ���Էֳɼ������Ĳ��� ö����i-1Ϊ��β��ÿһ���ַ������ǿ�ʼλ��Ϊj dp[i]=min(dp[i],dp[j]+1) 
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
