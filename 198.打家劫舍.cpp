f[i][j] ��ʾǰi�䷿���У���i����״̬Ϊj���������
f[i][0]=max(f[i-1][0],f[i-1][1]) ��һ��û��ٻ����˵����ֵ
f[i][1]=f[i-1][0]+nums[i]; 
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        int a=0,b=nums[0];//a��ʾû��� b��ʾ����� 
        for(int i=1,n=nums.size(),c;i<n;i++)
        {
            c=a;
            a=max(b,a);
            b=c+nums[i];
        }
        return max(a,b);
    }
};
