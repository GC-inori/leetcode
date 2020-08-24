class Solution {
public:
    bool isHappy(int n) 
    {
        bool f[810];//int范围内最大的数的各位数字的平方和小于10个9的平方和即810 所以用一个bool数组标记这个数字是否出现过 
        memset(f,0,sizeof(f));
        while(n!=1)
        {
            int t=0;
            while(n)
            {
                t+=(n%10)*(n%10);
                n/=10;
            }
            if(f[t]) return 0;//出现重复的有循环 
            f[t]=1;
            n=t;
        }    
        return 1;
    }
};
