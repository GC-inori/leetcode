�����ȡ�ַ�����ת������������26����ת10���ơ�
���磬BC=2��26^1+3��26^0=55��
class Solution {
public:
    int titleToNumber(string s) 
    {
        long long p=1,res=0;
        for(int i=s.size()-1;~i;i--)
        {
            res+=p*(s[i]-'A'+1);
            p*=26;
        }
        return res;
    }
};
