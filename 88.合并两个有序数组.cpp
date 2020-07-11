class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        for(int i=m+n-1;i>=n;i--) nums1[i]=nums1[i-n];
        for(int i=0,j=n,k=0;i<n+m;i++)
        {
            if(j>=m+n||k<n&&nums2[k]<nums1[j]) nums1[i]=nums2[k++];//ÀàËÆ¹é²¢ÅÅÐò 
            else nums1[i]=nums1[j++];
        }    
    }
};
