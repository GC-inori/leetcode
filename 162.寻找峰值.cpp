���ַ� 
��� nums[i-1] < nums[i]������� nums[i-1], nums[i], ... nums[n-1] �ǵ����ģ��� nums[n-1]���Ƿ�ֵ�����nums[i-1], nums[i], ... nums[n-1]���ǵ����ģ���� i ��ʼ��
	��һ������ nums[i] > nums[i+1]�� i ���Ƿ�ֵ������ [i-1~n-1] ��һ������һ����ֵ��
��� nums[i-1] > nums[i]��ͬ��ɵ� [0,i-1] ��һ������һ����ֵ��
���Կ���ÿ�ζ����е㣬ͨ���ж� nums[i-1] �� nums[i] �Ĵ�С��ϵ�������ж����������ı�һ���з�ֵ���Ӷ����Խ�����������Сһ�롣
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int l=0,r=nums.size()-1,mid;
        while(l<r)
        {
            mid=l+r+1>>1;
            if(nums[mid]>nums[mid-1]) l=mid;
            else r=mid-1;
        }
        return l;
    }
};
