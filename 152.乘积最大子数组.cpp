Max��ʾ��nums[i]��β�����������˻������ֵ Min��ʾ��nums[i]��β�����������˻�����Сֵ 
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int Max=nums[0],Min=nums[0],t1,t2,res=nums[0];
        for(int i=1,n=nums.size();i<n;i++)
        {
            t1=Max*nums[i],t2=nums[i]*Min;
            Max=max(nums[i],max(t1,t2));//Ҫôֻ�����Լ� Ҫô��ǰ��������������� 
            Min=min(nums[i],min(t1,t2));
            res=max(res,Max);
        }
        return res;
    }
};
