找到m、n中第一个不同的位置 
m=xxxx0......<=xxxx10000000 
n=xxxx1......>=xxxx10000000
按位与之后得到前缀
最终答案结尾xxxx000000 
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        for(int i=31;~i;i--)
        {
            if((m>>i)==(n>>i)) continue;
            return (m>>i)<<i;
        }
        return m;
    }
};
