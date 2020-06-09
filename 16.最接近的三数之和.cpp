排序 + 双指针 类似15题 
算法流程：
对数组进行排序。
遍历排序后数组：

令左指针 L=i+1，右指针 R=n-1，当 L<R 时，执行循环：
跟新target与 nums[i]+nums[L]+nums[R]的差值 
当 nums[i]+nums[L]+nums[R]==target，返回
若和大于 target，说明 nums[R] 太大，R 左移
若和小于 target，说明 nums[L] 太小，L 右移
class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int res=1e8;
        for(int i=0,n=nums.size();i<n;i++)
        {
            int l=i+1,r=n-1,a;
            while(l<r)
            {
                a=nums[i]+nums[l]+nums[r];
                if(abs(res-target)>abs(a-target)) res=a;
                if(res==target) return res;
                if(a>target) r--;
                else l++; 
            }
        }
        return res;
    }
};
