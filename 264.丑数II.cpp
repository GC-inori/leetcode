class Solution {
public:
    int nthUglyNumber(int n) 
    {
        int f[1691];
        f[0]=1;
        for(int i=0,j=0,k=0,c=1;c<n;c++)
        {
            int t=min(f[i]*2,min(f[j]*3,f[k]*5));
            if(t==f[i]*2) i++;
            if(t==f[j]*3) j++;
            if(t==f[k]*5) k++;
            f[c]=t;
        }
        return f[n-1];
    }
};
