利用 output 数组当做临时存储空间，令 output[i] 为从 nums[0] * nums[1] * ... * num[i - 1]。
然后从数组末尾，用变量 end 记录末尾若干数字的乘积，每次更新 output[i] 即可得到答案。
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
