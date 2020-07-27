考虑二进制每一位上出现 0 和 1 的次数，如果出现 1 的次数为 3k + 1，则证明答案中这一位是 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int bit = 0; bit < 32; bit++)
        {
            int counter = 0;
            for (int i = 0; i < nums.size(); i++)
                counter += (nums[i] >> bit) & 1;
            ans += (counter % 3) << bit;
        }

        return ans;
    }
};
