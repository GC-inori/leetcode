class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k=nums.size()-k%nums.size();//计算需要将前几个向后启动k位 
        if(!k) return;
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());    
    }
};
