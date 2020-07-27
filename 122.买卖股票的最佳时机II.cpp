class Solution {
public:
    int maxProfit(vector<int>& prices) //�����Ӧ��ÿ���������������͵�����ߵ����� 
    {
        int res=0;
        for(int i=0,j,n=prices.size();i<n;i=j)
        {
            j=i+1;
            if(j<n&&prices[j]<=prices[i]) continue;//��������� 
            while(j<n&&prices[j]>=prices[j-1]) j++;//���������յ� 
            res+=prices[j-1]-prices[i];
        }
        return res;    
    }
    int maxProfit(vector<int>& prices) //dp 
    {
        const int n=prices.size();
        int f[n+1][2];   //f[i][0]��ʾ��i�տղֵ�������� f[i][1]��i���й�Ʊ��������� 
        f[0][0]=0,f[0][1]=-1e9;
        for(int i=0;i<n;i++)
        {
            f[i+1][0]=max(f[i][0],f[i][1]+prices[i]);//Ҫôǰһ��Ϳղ� Ҫôǰһ���й�Ʊ�������� 
            f[i+1][1]=max(f[i][1],f[i][0]-prices[i]);//Ҫôǰһ���й�ƪ Ҫôǰһ��ղֽ������Ʊ 
        }
        return max(f[n][0],f[n][1]);    
    }
    int maxProfit(vector<int>& prices) //dp�ռ��Ż� 
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
