二分法 
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if(nums[0]<=nums.back()) return nums[0];//如果没有翻转或者只有一个元素 
        int l=1,r=nums.size()-1,mid;//找到第一个下于nums[0]的位置 即为最小值 
        while(l<r)
        {
            mid=l+r>>1;
            if(nums[mid]>nums[0]) l=mid+1;
            else r=mid;
        }
        return nums[l];
    }
};
