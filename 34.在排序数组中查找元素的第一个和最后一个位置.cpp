两次二分法 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.empty()||target<nums[0]||target>nums.back()) return {-1,-1};
        int pos1,pos2,l=0,r=nums.size()-1,mid;
        while(l<r)   //寻找左边界 
        {
            mid=l+r>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }    
        if(nums[l]!=target) return {-1,-1};
        pos1=l,l=0,r=nums.size()-1;
        while(l<r)  //右边界 
        {
            mid=l+r+1>>1;  //注意二分法mid取值 防止死循环 
            if(nums[mid]>target) r=mid-1;
            else l=mid;
        }
        pos2=l;
        return {pos1,pos2};
    }
};
