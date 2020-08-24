进制转化 10-26 注意26进制从1开始 每次转化时要-1将 1-26映射为0-25 
class Solution {
public:
    string convertToTitle(int n) 
    {
        string res;
        while(n)
        {
            res.push_back((n-1)%26+'A');
            n=(n-1)/26;
        }
        return string(res.rbegin(),res.rend());
    }
};
