ŷ��ɸ 
class Solution {
public:
    int countPrimes(int n) 
    {
        int cnt=0;
        vector<bool> f(n,0);
        int p[700010];
        for(int i=2;i<n;i++)
        {
            if(!f[i])
            {
                p[cnt++]=i;
                for(int j=0;j<cnt&&p[j]*i<n;j++) //�������� ����������Ҫɸ 
                    f[p[j]*i]=1;
            }
            else
            {
                for(int j=0;j<cnt&&p[j]*i<n;j++)//����ֻɸ����һ��Լ�� 
                {
                    f[p[j]*i]=1;
                    if(i%p[j]==0) break;
                }
            }
        }
        return cnt;
    }
};
