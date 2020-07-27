两个相同的数字经过异或之后会变为 0。
0异或其他数字等于该数字 
将数组所有元素异或在一起即可得到出现 1 次的元素值。
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int res=0;
        for(auto &c:nums) res^=c;
        return res;
    }
};
