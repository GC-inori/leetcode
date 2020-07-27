class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int res=0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(auto c:nums)
        {
            if(s.count(c-1)) continue;//��ֹ��β��� ÿ��ö����������ʱ ֻ����С�����ֿ�ʼö�� 
            int t=c+1;
            while(s.count(t)) t++;
            res=max(res,t-c);
        }
        return res;
    }
};
