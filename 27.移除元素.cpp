����26�� 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        if(nums.empty()) return 0;
        int res=0;  //������val�ĸ��� 
        for(int i=0,n=nums.size();i<n;i++)
            if(nums[i]!=val) nums[res++]=nums[i];  //���������ƶ� 
        return res;
    }
};
