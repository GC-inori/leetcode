class Solution {
public:
    int maxProfit(vector<int>& prices) //最大收应该每次在上升区间的最低点买，最高点卖出 
    {
        int res=0;
        for(int i=0,j,n=prices.size();i<n;i=j)
        {
            j=i+1;
            if(j<n&&prices[j]<=prices[i]) continue;//如果不上升 
            while(j<n&&prices[j]>=prices[j-1]) j++;//求上升的终点 
            res+=prices[j-1]-prices[i];
        }
        return res;    
    }
    int maxProfit(vector<int>& prices) //dp 
    {
        const int n=prices.size();
        int f[n+1][2];   //f[i][0]表示第i日空仓的最大收益 f[i][1]第i日有股票的最大收益 
        f[0][0]=0,f[0][1]=-1e9;
        for(int i=0;i<n;i++)
        {
            f[i+1][0]=max(f[i][0],f[i][1]+prices[i]);//要么前一天就空仓 要么前一天有股票今天卖出 
            f[i+1][1]=max(f[i][1],f[i][0]-prices[i]);//要么前一天有股篇 要么前一天空仓今天买股票 
        }
        return max(f[n][0],f[n][1]);    
    }
    int maxProfit(vector<int>& prices) //dp空间优化 
    {
        const int n=prices.size();
        int a=0,b=-1e9;
        for(int i=0,c;i<n;i++)
        {
            c=a;
            a=max(a,b+prices[i]);
            b=max(b,c-prices[i]);
        }
        return max(a,b);    
    }
};
