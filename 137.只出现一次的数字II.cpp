���Ƕ�����ÿһλ�ϳ��� 0 �� 1 �Ĵ������������ 1 �Ĵ���Ϊ 3k + 1����֤��������һλ�� 1
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
