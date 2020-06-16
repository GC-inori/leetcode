����һ�����о��ǴӺ���ǰѰ�ҵ�һ�����ֽ���ĵط���������ط����������ߴ�������С�����ֽ������ٰѸ�λ��֮������Ϊ����

��ĩβ��ǰ�������nums[i]>= max nums[i+1~ĩβ] �Ļ�������ô������������
���� �ҵ���ߴ�������С�����ֽ�������ʱ nums[i+1~ĩβ]Ϊ�������� ֱ�ӷ�ת���� 
��Ϊ��һ������ 
 
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size()<2) return;
        int rmax=nums.back();
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<rmax)
            {
                int l=i+1,r=nums.size()-1,mid;
                while(l<r)  //���ַ��ҵ����ڸ�ֵ����Сֵ 
                {
                    mid=l+r+1>>1;
                    if(nums[mid]>nums[i]) l=mid;
                    else r=mid-1;
                }
                swap(nums[i],nums[l]);
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
            else rmax=nums[i];
        }
        reverse(nums.begin(),nums.end());    //���Ϊ��������ֱ�ӷ�ת 
    }
};
