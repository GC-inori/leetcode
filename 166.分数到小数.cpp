class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
	{
        long long x = numerator, y = denominator;
        if (x % y == 0) return to_string(x / y);
        string res;
        if ((x < 0) ^ (y < 0)) res += '-';//�ж��Ƿ�Ϊ���� 
        x = abs(x), y = abs(y);
        res += to_string(x / y) + '.', x %= y;
        unordered_map<long long, int> hash;//��¼�Ƿ���ֹ�ѭ���� 
        while (x) 
		{
            x *= 10;
            if(hash.count(x)) //���֮ǰ���ֹ�������x 
			{
                res = res.substr(0, hash[x]) + '(' + res.substr(hash[x]) + ')';//����С������������ 
                break;
            }
            hash[x] = res.size();
            res += to_string(x / y);
            x %= y;
        }
        return res;
    }
}; 
