class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t res=0;
        for(int i=0;i<32;i++)
        {
            res=(res<<1)|(n&1);//每次先将res左移一位 再将n的末尾添加到res的末尾 
            n>>=1; //n右移一位 
        }
        return res;
    }
};
