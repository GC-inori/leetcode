二分法查找大于等于目标值最小的数 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if(target>nums.back()) return nums.size(); //特判边界 
        int l=0,r=nums.size()-1,mid;
        while(l<r)
        {
            mid=l+r>>1;
            if(target>nums[mid]) l=mid+1;
            else r=mid;
        }    
        return l;
    }
};
