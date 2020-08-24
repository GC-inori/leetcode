由于要寻找的数字数量大于数组的一半 所以删除掉两个不同的数字不影响答案 
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int res=INT_MIN,cnt=0;
        for(auto &c:nums)
        {
            if(c==res) cnt++;//如果相同个数+1 
            else if(cnt) cnt--;//输出两个不同元素 
            else res=c,cnt++;//跟新当前值 
        }
        return res;    
    }
};
