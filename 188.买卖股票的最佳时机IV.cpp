class Solution {
public:
    int maxProfit1(vector<int>& prices)
    {
        int a=-1e9,b=0;
        for(int i=0,n=prices.size(),t;i<n;i++)//a��ʾ�����й�Ʊ b��ʾ����û��Ʊ 
        {
            t=a;
            a=max(a,b-prices[i]);
            b=max(b,a+prices[i]);
        }
        return max(a,b);
    } 
    int maxProfit(int k, vector<int>& prices) 
    {
        if(k>prices.size()/2) return maxProfit1(prices);//�ȼ��ڿ��Խ������޴� 
        const int n=prices.size();
        int f[2][n+1][2],res=0;//f[i][j][k]��ʾǰi������ཻ��j�� �ҵ�i�������Ʊ״̬Ϊk��������� 
        memset(f,0,sizeof(f));//����0�ζ�Ϊ0 
        f[1][0][1]=f[0][0][1]=-1e9;//�߽�ֵ 
        for(int i=1;i<=k;i++)
            for(int j=0;j<n;j++)
            {
                f[i&1][j+1][0]=max(f[i&1][j][0],f[i&1][j][1]+prices[j]);//��ת�Ʒ��̿�֪ f[i][j][k]֮��f[i-1][j][k] f[i][j][k]�����й� ���ù��������Ż� 
                f[i&1][j+1][1]=max(f[i&1][j][1],f[i-1&1][j][0]-prices[j]);
            }
        return f[k&1][n][0];
    }
};
