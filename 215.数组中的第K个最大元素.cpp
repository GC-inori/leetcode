基于类似快速排序的找第k的数 
class Solution {
public:
    int sort(int l,int r,int k,vector<int>& nums)
    {
        if(l>=r) return nums[l];
        int i=l-1,j=r+1,x=nums[l+r>>1];
        while(i<j)
        {
            do i++;while(nums[i]>x);
            do j--;while(nums[j]<x);
            if(i<j) swap(nums[i],nums[j]);
        }
        if(k>j-l+1) return sort(j+1,r,k-j+l-1,nums);//如果k在左半边 
        return sort(l,j,k,nums);//在右半边 
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        return sort(0,nums.size()-1,k,nums);
    }
};
