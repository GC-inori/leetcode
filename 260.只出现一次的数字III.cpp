首先将所有数字进行异或，求出异或和 sum。sum 必定不为 0。
找到 sum 二进制表示下不为 0 的其中一个位置。此时，可以根据这个位置是否为 1，将数组中的数字分为两部分。注意到，这两个数字会分别位于一部分中。
将这一位为 0 的数字分为一组，为 1 的数字分为一组，分别求异或和，得到最终的两个数字。
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int s=0;
        for(auto &c:nums)
            s^=c;
        int t=s&(-s),s1=0,s2=0;
        for(auto &c:nums)
            if(c&t) s1^=c;
            else s2^=c;
        return {s1,s2};
    }
};
