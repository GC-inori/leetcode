����ҪѰ�ҵ������������������һ�� ����ɾ����������ͬ�����ֲ�Ӱ��� 
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int res=INT_MIN,cnt=0;
        for(auto &c:nums)
        {
            if(c==res) cnt++;//�����ͬ����+1 
            else if(cnt) cnt--;//���������ͬԪ�� 
            else res=c,cnt++;//���µ�ǰֵ 
        }
        return res;    
    }
};
