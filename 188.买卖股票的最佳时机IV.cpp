class Solution {
public:
    int maxProfit1(vector<int>& prices)
    {
        int a=-1e9,b=0;
        for(int i=0,n=prices.size(),t;i<n;i++)//a表示手里有股票 b表示手里没股票 
        {
            t=a;
            a=max(a,b-prices[i]);
            b=max(b,a+prices[i]);
        }
        return max(a,b);
    } 
    int maxProfit(int k, vector<int>& prices) 
    {
        if(k>prices.size()/2) return maxProfit1(prices);//等价于可以交易无限次 
        const int n=prices.size();
        int f[2][n+1][2],res=0;//f[i][j][k]表示前i天里最多交易j次 且第i天手里股票状态为k的最大收益 
        memset(f,0,sizeof(f));//交易0次都为0 
        f[1][0][1]=f[0][0][1]=-1e9;//边界值 
        for(int i=1;i<=k;i++)
            for(int j=0;j<n;j++)
            {
                f[i&1][j+1][0]=max(f[i&1][j][0],f[i&1][j][1]+prices[j]);//由转移方程可知 f[i][j][k]之和f[i-1][j][k] f[i][j][k]两层有关 故用滚动数组优化 
                f[i&1][j+1][1]=max(f[i&1][j][1],f[i-1&1][j][0]-prices[j]);
            }
        return f[k&1][n][0];
    }
};
