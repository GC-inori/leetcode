���ƿ������� 
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int l=0,r=nums.size()-1;  //0~l-1 ��������0  r+1~nums.size()-1��ֹ����2 
        for(int i=0;i<=r;i++)
        {
            if(nums[i]==1) continue; //l~i��������1 
            if(nums[i]==2)
            {
                swap(nums[i],nums[r--]); //���� ����nums[r]��δ���� ��Ҫi-- 
                i--;
            }
            else swap(nums[l++],nums[i]); //l`i-1��ʱ����������1 0~l-1������0 �¼����1Ӧ�÷���λ��l ͬʱl����1������i 
			//0~i-1 ������ ֱ�ӽ�������  
        }    
    }
};
