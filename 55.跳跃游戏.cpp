class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int st=nums.size()-1;  //st��ʾ�ܹ�����ĩβ��С�ĵ� 
        for(int i=nums.size()-2;i>=0;i--) //�ӵ����ڶ����㿪ʼ 
            if(nums[i]+i>=st) st=i;  //����ܵ������ 
        return st==0; //�ж�����ܷ񵽴� 
    }
};
