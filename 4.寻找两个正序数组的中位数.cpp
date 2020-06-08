/*
为了方便讨论我们首先假设两个数组的长度分别为n,m，并且有n <= m，并且n + m是奇数，那么我们要找的数字其实就是两个数组合并后第k = (n + m + 1) / 2小的数字。我
们尝试将两个数组划分成两个部分，A数组左侧有i个元素，B数组左侧有j个元素，并且i + j = k。

          left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[n-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[m-1]
如果我们能够保证A[i - 1] <B[j]&&B[j-1]<A[i]，那么说明left_part中的所有元素都小于right_part中的元素，并且第k小的元素就是max(A[i - 1],B[j - 1])。
如果A[i - 1] > B[j]说明i偏大，我们需要将i缩小尝试得到A[i - 1] < B[j]。
如果B[j - 1] > A[i]说明i偏小，我们需要将i放大尝试得到B[j - 1] < A[i]。
那么我们使用二分查找来找到左边放多少个i数字比较合适，初始搜索区间为[0:n]，如果左边放置i个元素，那么右边放置j = k - i个元素。

接下来我们考虑一些边界条件：
如果i = 0，相当于最小的k个数都在B中，这时整体第k小的元素就是B[k - 1]
如果j = 0，相当于最小的k个数都在A中，这时整体第k小的元素就是A[k - 1]
否则，最小的k个数，i个在A中，j个在B中，这时整体第k小的元素就是max(A[i - 1],B[j - 1])

上面我们的讨论，我们是基于n + m是奇数的，这时候我们只需要找到上述元素就好了，
但是当n + m是偶数的时候，我们还需要找到right_part中最小的元素，这个值也就是min(A[i],B[j])，这时候仍然需要讨论一些边界情况：
如果i = n，那么A中没有比A[i - 1]还大的了，那么只能是B[j]
如果j = m，那么B中没有比B[j - 1]还大的了，那么只能是A[i]
否则，整体第k + 1小的元素就是min(A[i],A[j])
*/
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1); //在较小的上面二分
        int k=(nums1.size()+nums2.size()+1)/2,l=0,r=nums1.size(),mid,n1=nums1.size(),n2=nums2.size(); //k左半边元素数量
        while(l<=r)
        {
            int i=l+r>>1,j=k-i; // k>=i
            if(i<n1&&nums2[j-1]>nums1[i])  //k>=nums1.size() i<nums1.size()时j>=1
                l=i+1;
            else if(i&&nums1[i-1]>nums2[j])
                r=i-1;
            else
            {
                int max_left=0,min_right=0;
                if(!i) max_left=nums2[k-1];
                else if(!j) max_left=nums1[k-1];  //nums1和nums2个数相同时可能出现的情况
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

