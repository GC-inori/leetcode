�ҵ�m��n�е�һ����ͬ��λ�� 
m=xxxx0......<=xxxx10000000 
n=xxxx1......>=xxxx10000000
��λ��֮��õ�ǰ׺
���մ𰸽�βxxxx000000 
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
