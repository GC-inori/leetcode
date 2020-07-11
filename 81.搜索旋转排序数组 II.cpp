这道题类似于33，不同点在于这道题里的数组可能包含相同元素。
目前能想到的二分做法的最坏时间复杂度都是 O(n)，所以就线性扫描了 
class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        for(auto &c:nums)
            if(c==target) return 1;
        return 0;
    }
};
