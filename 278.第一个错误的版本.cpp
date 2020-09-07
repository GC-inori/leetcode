// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
二分法 
class Solution {
public:
    int firstBadVersion(int n) 
    {
        int l=1,r=n,mid;
        while(l<r)    
        {
            mid=0ll+l+r>>1;//数据较大 两数之和可能爆int 
            if(!isBadVersion(mid)) l=mid+1;
            else r=mid;
        }
        return l;
    }
};
