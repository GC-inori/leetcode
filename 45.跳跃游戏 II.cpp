ģ�� 
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int res=0,maxl=0,len=0;    //maxl��ǰ��������Ծ����Զ���� res��ǰ��Ծ���� 
        for(int i=0,n=nums.size();i<n;i++) //len res+1����Ծ����Զ����
        {
            if(i>maxl)  //���i>maxl ��Ҫ����һ�� 
            {
                res++;
                maxl=len;
            }
            len=max(len,nums[i]+i);  //��¼��һ����Զ����λ�� 
        }
        return res;
    }
};
