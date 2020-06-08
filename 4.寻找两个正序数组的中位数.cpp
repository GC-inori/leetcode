/*
Ϊ�˷��������������ȼ�����������ĳ��ȷֱ�Ϊn,m��������n <= m������n + m����������ô����Ҫ�ҵ�������ʵ������������ϲ����k = (n + m + 1) / 2С�����֡���
�ǳ��Խ��������黮�ֳ��������֣�A���������i��Ԫ�أ�B���������j��Ԫ�أ�����i + j = k��

          left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[n-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[m-1]
��������ܹ���֤A[i - 1] <B[j]&&B[j-1]<A[i]����ô˵��left_part�е�����Ԫ�ض�С��right_part�е�Ԫ�أ����ҵ�kС��Ԫ�ؾ���max(A[i - 1],B[j - 1])��
���A[i - 1] > B[j]˵��iƫ��������Ҫ��i��С���Եõ�A[i - 1] < B[j]��
���B[j - 1] > A[i]˵��iƫС��������Ҫ��i�Ŵ��Եõ�B[j - 1] < A[i]��
��ô����ʹ�ö��ֲ������ҵ���߷Ŷ��ٸ�i���ֱȽϺ��ʣ���ʼ��������Ϊ[0:n]�������߷���i��Ԫ�أ���ô�ұ߷���j = k - i��Ԫ�ء�

���������ǿ���һЩ�߽�������
���i = 0���൱����С��k��������B�У���ʱ�����kС��Ԫ�ؾ���B[k - 1]
���j = 0���൱����С��k��������A�У���ʱ�����kС��Ԫ�ؾ���A[k - 1]
������С��k������i����A�У�j����B�У���ʱ�����kС��Ԫ�ؾ���max(A[i - 1],B[j - 1])

�������ǵ����ۣ������ǻ���n + m�������ģ���ʱ������ֻ��Ҫ�ҵ�����Ԫ�ؾͺ��ˣ�
���ǵ�n + m��ż����ʱ�����ǻ���Ҫ�ҵ�right_part����С��Ԫ�أ����ֵҲ����min(A[i],B[j])����ʱ����Ȼ��Ҫ����һЩ�߽������
���i = n����ôA��û�б�A[i - 1]������ˣ���ôֻ����B[j]
���j = m����ôB��û�б�B[j - 1]������ˣ���ôֻ����A[i]
���������k + 1С��Ԫ�ؾ���min(A[i],A[j])
*/
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1); //�ڽ�С���������
        int k=(nums1.size()+nums2.size()+1)/2,l=0,r=nums1.size(),mid,n1=nums1.size(),n2=nums2.size(); //k����Ԫ������
        while(l<=r)
        {
            int i=l+r>>1,j=k-i; // k>=i
            if(i<n1&&nums2[j-1]>nums1[i])  //k>=nums1.size() i<nums1.size()ʱj>=1
                l=i+1;
            else if(i&&nums1[i-1]>nums2[j])
                r=i-1;
            else
            {
                int max_left=0,min_right=0;
                if(!i) max_left=nums2[k-1];
                else if(!j) max_left=nums1[k-1];  //nums1��nums2������ͬʱ���ܳ��ֵ����
                else max_left=max(nums1[i-1],nums2[j-1]);
                if((n1+n2)&1) return max_left;
                if(i==n1) min_right=nums2[j];
                else if(j==n2) min_right=nums1[i]; 
                else min_right=min(nums1[i],nums2[j]);
                return (max_left+min_right)/2.0;
            }
        }
        return 0.0;
    }
};

