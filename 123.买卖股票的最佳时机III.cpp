f[i][j][k] ��ʾ��ǰj����������i�ν��ף��ҵ�j�����޹�Ʊ״̬Ϊk��������� k=0û�й�Ʊ k=1 �й�Ʊ 
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        const int n=prices.size();
        int f[3][n+1][2];
        memset(f,0,sizeof(f));
        f[1][0][1]=f[2][0][1]=-1e9;//�߽� 
        for(int i=1;i<3;i++)
            for(int j=0;j<n;j++)
            {
                f[i][j+1][0]=max(f[i][j][1]+prices[j],f[i][j][0]);//Ҫôǰһ��û��Ʊ Ҫôǰһ���й�Ʊ�ҽ������� 
                f[i][j+1][1]=max(f[i][j][1],f[i-1][j][0]-prices[j]);//ÿ��������һ�ν���  Ҫôǰһ���й�Ʊ ҪôҪô�������� 
            }
        return f[2][n][0];
    }
};
