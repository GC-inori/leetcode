���� + ˫ָ�� ����15�� 
�㷨���̣�
�������������
������������飺

����ָ�� L=i+1����ָ�� R=n-1���� L<R ʱ��ִ��ѭ����
����target�� nums[i]+nums[L]+nums[R]�Ĳ�ֵ 
�� nums[i]+nums[L]+nums[R]==target������
���ʹ��� target��˵�� nums[R] ̫��R ����
����С�� target��˵�� nums[L] ̫С��L ����
class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int res=1e8;
        for(int i=0,n=nums.size();i<n;i++)
        {
            int l=i+1,r=n-1,a;
            while(l<r)
            {
                a=nums[i]+nums[l]+nums[r];
                if(abs(res-target)>abs(a-target)) res=a;
                if(res==target) return res;
                if(a>target) r--;
                else l++; 
            }
        }
        return res;
    }
};
