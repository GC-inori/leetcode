��Hָ�� 
class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int l=-1,r=citations.size()-1,mid,n=citations.size();//��-1��ֹԽ�� 
        while(l<r)
        {
            mid=l+r+1>>1;
            if(citations[mid]>n-mid-1) r=mid-1;
            else l=mid;
        }
        return n-l-1;
    }
};
