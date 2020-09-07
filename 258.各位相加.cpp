只需要判断这个数字模 9 之后的余数（若余 0 则返回 9）。
可以证明每次操作后减少的数字为 9的倍数 故每次操作后mod9的余数不变 
class Solution {
public:
    int addDigits(int num) 
    {
        return (num-1)%9+1;//num==0时 返回0 
    }
};
