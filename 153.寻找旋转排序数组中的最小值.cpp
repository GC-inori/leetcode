���ַ� 
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if(nums[0]<=nums.back()) return nums[0];//���û�з�ת����ֻ��һ��Ԫ�� 
        int l=1,r=nums.size()-1,mid;//�ҵ���һ������nums[0]��λ�� ��Ϊ��Сֵ 
        while(l<r)
        {
            mid=l+r>>1;
            if(nums[mid]>nums[0]) l=mid+1;
            else r=mid;
        }
        return nums[l];
    }
};
