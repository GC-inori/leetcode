class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        long long t=n;
        int res=0;
        while(t)
        {
            res++;
            t-=t&-t;//t&-t ����ĩβ�����1 
        }
        return res;    
    }
};
