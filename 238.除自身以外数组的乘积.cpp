���� output ���鵱����ʱ�洢�ռ䣬�� output[i] Ϊ�� nums[0] * nums[1] * ... * num[i - 1]��
Ȼ�������ĩβ���ñ��� end ��¼ĩβ�������ֵĳ˻���ÿ�θ��� output[i] ���ɵõ��𰸡�
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res(nums.size());
        res[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            res[i]=res[i-1]*nums[i];
        for(int i=nums.size()-1,end=1;~i;i--)
        {
            if(i) res[i]=end*res[i-1];
            else res[i]=end;
            end*=nums[i];
        }
        return res;
    }
};
