˫ָ���ƶ� 
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        int res=1; //��ʾ���ظ����ָ��� 
        for(int i=1,n=nums.size();i<n;i++)
            if(nums[i]!=nums[i-1]) nums[res++]=nums[i]; //�����ǰһ������ȣ���ô�������ظ��� 
        return res;
    }
};
