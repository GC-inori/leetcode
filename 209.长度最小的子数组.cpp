����ÿ��λ�� i���ҵ�������С�� j������ [i, j] �ĺʹ��� s����� j >= i�������Ǹ��´� j - i + 1��������Ϊ��ʱ [i, j] �ĺ�һ���Ǵ��ڵ��� s �ģ����Ҷ��� i ��˵ j �����������о�����С�ġ�
���� j ������ i ���󵥵������ģ������ǿ�����˫ָ�롣
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int res=1e9,now=0;
        int i=0,j=0;
        while(j<nums.size())
        {
            now+=nums[j];
            while(now>=s)
            {
                res=min(res,j-i+1);
                now-=nums[i++];
            }
            j++;
        }
        return res==1e9?0:res;
    }
};
