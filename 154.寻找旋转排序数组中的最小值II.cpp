class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        while(nums.size()>1&&nums.back()==nums[0]) nums.pop_back();//ȥ����β��ͬԪ�� 
        if(nums.back()>=nums[0]) return nums[0];//���ֻ��һ����û�з�ת 
        int l=1,r=nums.size()-1,mid;
        while(l<r)//���ַ����ҵ�һ��С��nums[0]��Ԫ�� 
        {
            mid=l+r>>1;
            if(nums[mid]>=nums[0]) l=mid+1;
            else r=mid;
        }
        return nums[l];
    }
};
