������ͬ�����־������֮����Ϊ 0��
0����������ֵ��ڸ����� 
����������Ԫ�������һ�𼴿ɵõ����� 1 �ε�Ԫ��ֵ��
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int res=0;
        for(auto &c:nums) res^=c;
        return res;
    }
};
