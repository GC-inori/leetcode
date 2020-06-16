class Solution {
public:
	//两次二分法求解 
    int search(vector<int>& nums, int target) 
    {
        if(nums.empty()) return -1;
        int pos;
        if(nums[0]<nums.back()||nums.size()==1) pos=0; //第一个二分求出旋转后最小元素的位置pos 
        else
        {
            int l=0,r=nums.size()-1,mid;
            while(l<r)
            {
                mid=l+r>>1;
                if(nums[mid]>=nums[0]) l=mid+1;   //如果nums[mid]>=nums[0]说明nums[0-mid]都大于nums[0] pos一定在nums[mid+1~r] 
                else r=mid;  //nums[mid]<nums[0] 说明pos在nums[l~mid] 
            }
            pos=l;
        } 
        int l=0,n=nums.size(),r=n-1,mid;
        while(l<r)
        {
            mid=l+r>>1;
            if(nums[(mid+pos)%n]>=target) r=mid; //以pos为原点进行二分 pos-nums.size() 0-pos为有序数组 
            else l=mid+1;
        }
        l=(l+pos)%n;
        return nums[l]==target?l:-1;
    }
    //一次二分 
    int search(vector<int>& nums, int target) 
    {
        if(nums.empty()) return -1;
        int l=0,r=nums.size()-1,mid;
        while(l<r)
        {
            mid=l+r>>1;               //设0~pos单调增加（前半部分） pos-nums.size()-1单调增加 （后半部分） 
            if(nums[mid]>=nums[0]) // nums[mid]在数组前半部分
            {
                if(target<=nums[mid]&&target>=nums[0]) r=mid; //如果target介于nums[0]和nums[mid]之间，那么target一定在 l~mid中间 
                else l=mid+1; //否则在 mid+1~r 
            }
            else   //nums[mid]在后半部分 
            {
                if(nums[mid]<target&&nums[0]>target) l=mid+1; //同理可得 
                else r=mid;
            }
        }
        return nums[l]==target?l:-1;
    }
};
