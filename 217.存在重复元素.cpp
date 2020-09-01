class Solution {
public:
    bool containsDuplicate(vector<int>& nums) //�������� 
    {
        unordered_set<int> us;
        for(auto &c:nums)
            if(us.count(c)) return 1;
            else us.insert(c);
        return 0;
    }
};
