f[i][j][k] 表示在前j天内最多进行i次交易，且第j天有无股票状态为k的最大收益 k=0没有股票 k=1 有股票 
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        const int n=prices.size();
        int f[3][n+1][2];
        memset(f,0,sizeof(f));
        f[1][0][1]=f[2][0][1]=-1e9;//边界 
        for(int i=1;i<3;i++)
            for(int j=0;j<n;j++)
            {
                f[i][j+1][0]=max(f[i][j][1]+prices[j],f[i][j][0]);//要么前一天没股票 要么前一天有股票且今天卖出 
                f[i][j+1][1]=max(f[i][j][1],f[i-1][j][0]-prices[j]);//每次买入算一次交易  要么前一天有股票 要么要么今天买入 
            }
        return f[2][n][0];
    }
};
