������������ظ�ֵ�϶�������ĿҪ�� ������set���� 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        set<long long> s;
        s.insert(1e12);
        s.insert(-1e12);
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(i>k)
                s.erase(nums[i-k-1]);
            auto tt=s.lower_bound(nums[i]);//�Ҵ��һ�����ڵ���nums[i]���� 
            if(abs(*tt-nums[i])<=t) return 1;
            tt--;//�ҵ�С��nums[i]������ 
            if(abs(*tt-nums[i])<=t) return 1;
            s.insert(nums[i]);
        }
        return 0;
    }
};
