class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k=nums.size()-k%nums.size();//������Ҫ��ǰ�����������kλ 
        if(!k) return;
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());    
    }
};
