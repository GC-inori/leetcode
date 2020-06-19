索引排序   将数字nums[i]保存在nums[nums[i]-1]中，如果nums[i]<=0||nums[i]>nums[i] ||nums[i]==nums[nums[i]-1] 不操作  最后返回第一个nums[i]!=i+1 时i+1的值 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        for(int i=0,n=nums.size();i<n;i++)
        {
            while(nums[i]>0&&nums[i]<n&&nums[i]!=i+1)
            {
                if(nums[i]==nums[nums[i]-1]) break;
                swap(nums[i],nums[nums[i]-1]);
            }
        }    
        for(int i=0,n=nums.size();i<n;i++)
            if(nums[i]!=i+1) return i+1;
        return nums.size()+1;
    }
};
