ÊýÎ»dp 
class Solution {
public:
    int f[11][10],ten[11];
    int dp(int x)
    {
        vector<int> v;
        int t=x;
        while(x)
        {
            v.push_back(x%10);
            x/=10;
        }
        int res=0;
        for(int i=v.size()-1;~i;i--)
        {
            for(int j=0;j<v[i];j++) res+=f[i+1][j];
            if(v[i]==1)
                res+=t%ten[i]+1;
        }
        return res;
    }
    int countDigitOne(int n) 
    {
        if(n<=0) return 0;
        memset(f,0,sizeof(f));
        f[1][1]=1;
        ten[0]=1;
        for(int i=1;i<10;i++) ten[i]=ten[i-1]*10;
        for(long long i=2,t=10;i<=10;i++,t*=10)
            for(int j=0;j<10;j++)
            {
                if(j==1) f[i][j]+=t;
                for(int k=0;k<10;k++)
                    f[i][j]+=f[i-1][k];
            }
        return dp(n);
    }
};
