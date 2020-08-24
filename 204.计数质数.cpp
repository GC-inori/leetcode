欧拉筛 
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
                for(int j=0;j<cnt&&p[j]*i<n;j++) //对于质数 所有质数都要筛 
                    f[p[j]*i]=1;
            }
            else
            {
                for(int j=0;j<cnt&&p[j]*i<n;j++)//合数只筛到第一个约数 
                {
                    f[p[j]*i]=1;
                    if(i%p[j]==0) break;
                }
            }
        }
        return cnt;
    }
};
