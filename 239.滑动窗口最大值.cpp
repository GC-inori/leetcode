单调队列 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(k==1) return nums;
        int q[100000+10]={0},f=0,t=0;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(i-q[f]>=k) f++;
            while(t>=f&&nums[i]>=nums[q[t]]) t--;
            q[++t]=i;
            if(i>=k-1) res.push_back(nums[q[f]]);
        }
        return res;
    }
};
