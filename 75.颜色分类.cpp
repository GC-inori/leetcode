类似快速排序 
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int l=0,r=nums.size()-1;  //0~l-1 放置数字0  r+1~nums.size()-1防止数字2 
        for(int i=0;i<=r;i++)
        {
            if(nums[i]==1) continue; //l~i放置数字1 
            if(nums[i]==2)
            {
                swap(nums[i],nums[r--]); //交换 由于nums[r]尚未排序 需要i-- 
                i--;
            }
            else swap(nums[l++],nums[i]); //l`i-1此时放置了数字1 0~l-1是数字0 新加入的1应该放在位置l 同时l处的1交换到i 
			//0~i-1 已排序 直接交换即可  
        }    
    }
};
