只能买卖一次的话，当日最大收益即为当日股票价格减去之前几日股票价格的最小值 
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.empty()) return 0;
        int lmin=prices[0],res=0;
        for(int i=1,n=prices.size();i<n;i++)
        {
            if(prices[i]-lmin>res) res=prices[i]-lmin;//计算当日股票最大收益 
            if(lmin>prices[i]) lmin=prices[i];//更新最小值 
        }
        return res;
    }
};
