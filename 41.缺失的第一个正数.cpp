��������   ������nums[i]������nums[nums[i]-1]�У����nums[i]<=0||nums[i]>nums[i] ||nums[i]==nums[nums[i]-1] ������  ��󷵻ص�һ��nums[i]!=i+1 ʱi+1��ֵ 
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
