有几个因子5结尾就有几个0 因为2的数量肯定比5多 每个5都可以和2凑成10 
class Solution {
public:
    int trailingZeroes(int n) 
    {
        int res=0;
        while(n)
        {
            res+=n/5;//计算5 25 125。。。的数量 
            n/=5;
        }
        return res;
    }
};
