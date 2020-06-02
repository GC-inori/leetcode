因为int型整数逆序后可能会溢出，所以我们要用long long记录中间结果；
在C++中，负数的取模运算和数学意义上的取模运算不同，结果还是负数，比如 ?12%10=?2，所以我们不需要对负数进行额外处理。
class Solution 
{
public:
    int reverse(int x) {
        long long res = 0;
        while(x)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res < INT_MIN || res > INT_MAX) return 0;
        return res;
    }
};
