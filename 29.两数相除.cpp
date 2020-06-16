类似快速幂 快速乘 
class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        long long x=abs(dividend),y=abs(divisor),pow[33],p=0,res=0;
        int flag=1;
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) flag=-1;
        while(y<=x)
        {
            pow[p++]=y;
            y+=y;
        }
        for(int i=p-1;i>=0&&x;i--)
            if(pow[i]<=x) x-=pow[i],res+=1ll<<i; //要用1ll 否则会按int计算 
        if(flag==-1) res=-res;
        if(res>INT_MAX) return INT_MAX;
        if(res<INT_MIN) return INT_MIN;
        return res;
    }
};
