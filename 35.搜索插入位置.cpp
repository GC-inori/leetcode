���ַ����Ҵ��ڵ���Ŀ��ֵ��С���� 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if(target>nums.back()) return nums.size(); //���б߽� 
        int l=0,r=nums.size()-1,mid;
        while(l<r)
        {
            mid=l+r>>1;
            if(target>nums[mid]) l=mid+1;
            else r=mid;
        }    
        return l;
    }
};
