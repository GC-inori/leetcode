由于数组有序，所以相同元素一定是相邻的。
定义一个指针 len，表示新数组的末尾，然后从前往后扫描原数组，如果当前数不等于 nums[len] 且不等于 nums[len-1]或nums[k-2]，则将当前数插入新数组的末尾。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int len=0;
        for(auto &c:nums)
            if(len<2||nums[len-1]!=c||nums[len-2]!=c)
                nums[len++]=c;
        return len;
    }
};
