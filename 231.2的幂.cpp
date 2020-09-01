class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        return n>0&&!(n-(n&(-n))); //n<=0 肯定不是 n&(-n) 二进制下最低位的1 如果只有这一个1的话就是二的整次幂 
    }
};
