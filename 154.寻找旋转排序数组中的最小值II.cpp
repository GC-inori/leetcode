class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        while(nums.size()>1&&nums.back()==nums[0]) nums.pop_back();//去除结尾相同元素 
        if(nums.back()>=nums[0]) return nums[0];//如果只有一个或没有翻转 
        int l=1,r=nums.size()-1,mid;
        while(l<r)//二分法查找第一个小于nums[0]的元素 
        {
            mid=l+r>>1;
            if(nums[mid]>=nums[0]) l=mid+1;
            else r=mid;
        }
        return nums[l];
    }
};
