���� + ˫ָ��
������ѵ��������ȥ���ظ��⡣
�㷨���̣�
�������������
������������飺
�� nums[i]>0����Ϊ�Ѿ�����ã����Ժ��治�������������Ӻ͵��� 0��ֱ�ӷ��ؽ����
�����ظ�Ԫ�أ���������������ظ���
����ָ�� L=i+1����ָ�� R=n-1���� L<R ʱ��ִ��ѭ����
�� nums[i]+nums[L]+nums[R]==0��ִ��ѭ�����ж������ҽ��Ƿ����һλ���ظ���ȥ���ظ��⡣��ͬʱ�� L,R �Ƶ���һλ�ã�Ѱ���µĽ�
���ʹ��� 0��˵�� nums[R] ̫��R ����
����С�� 0��˵�� nums[L] ̫С��L ����
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(),nums.end());
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(i&&nums[i]==nums[i-1]) continue;  //ȥ���ظ��� 
            int l=i+1,r=n-1;
            if(nums[i]>0) break;
            while(l<r)
            {
                if(nums[l]+nums[r]==-nums[i])
                {
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++,r--;
                    while(l<r&&nums[l]==nums[l-1]) l++; //ȥ���ظ��� 
                    while(l<r&&nums[r]==nums[r+1]) r--;
                }
                else if(nums[l]+nums[r]<-nums[i]) l++;
                else r--;

            }
        }
        return res;
    }
};
