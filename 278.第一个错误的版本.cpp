// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
���ַ� 
class Solution {
public:
    int firstBadVersion(int n) 
    {
        int l=1,r=n,mid;
        while(l<r)    
        {
            mid=0ll+l+r>>1;//���ݽϴ� ����֮�Ϳ��ܱ�int 
            if(!isBadVersion(mid)) l=mid+1;
            else r=mid;
        }
        return l;
    }
};
