class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        n=(0+n)*(n+1)/2;//����0~n�ĺ� 
        for(auto &c:nums)   n-=c;
        return n;
    }
};
