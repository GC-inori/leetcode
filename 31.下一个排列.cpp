找下一个排列就是从后往前寻找第一个出现降序的地方，把这个地方的数字与后边大于他最小的数字交换，再把该位置之后整理为升序。

从末尾向前遍历如果nums[i]>= max nums[i+1~末尾] 的话不论怎么调整都不会变大
否则 找到后边大于他最小的数字交换，此时 nums[i+1~末尾]为降序序列 直接反转即可 
即为下一个排列 
 
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size()<2) return;
        int rmax=nums.back();
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<rmax)
            {
                int l=i+1,r=nums.size()-1,mid;
                while(l<r)  //二分法找到大于该值的最小值 
                {
                    mid=l+r+1>>1;
                    if(nums[mid]>nums[i]) l=mid;
                    else r=mid-1;
                }
                swap(nums[i],nums[l]);
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
            else rmax=nums[i];
        }
        reverse(nums.begin(),nums.end());    //如果为最大的序列直接反转 
    }
};
