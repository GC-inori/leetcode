ֻ������һ�εĻ�������������漴Ϊ���չ�Ʊ�۸��ȥ֮ǰ���չ�Ʊ�۸����Сֵ 
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.empty()) return 0;
        int lmin=prices[0],res=0;
        for(int i=1,n=prices.size();i<n;i++)
        {
            if(prices[i]-lmin>res) res=prices[i]-lmin;//���㵱�չ�Ʊ������� 
            if(lmin>prices[i]) lmin=prices[i];//������Сֵ 
        }
        return res;
    }
};
