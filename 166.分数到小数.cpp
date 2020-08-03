class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
	{
        long long x = numerator, y = denominator;
        if (x % y == 0) return to_string(x / y);
        string res;
        if ((x < 0) ^ (y < 0)) res += '-';//判断是否为负数 
        x = abs(x), y = abs(y);
        res += to_string(x / y) + '.', x %= y;
        unordered_map<long long, int> hash;//记录是否出现过循环节 
        while (x) 
		{
            x *= 10;
            if(hash.count(x)) //如果之前出现过被除数x 
			{
                res = res.substr(0, hash[x]) + '(' + res.substr(hash[x]) + ')';//拷贝小数和整数部分 
                break;
            }
            hash[x] = res.size();
            res += to_string(x / y);
            x %= y;
        }
        return res;
    }
}; 
