class Solution {
public:
	//���ζ��ַ���� 
    int search(vector<int>& nums, int target) 
    {
        if(nums.empty()) return -1;
        int pos;
        if(nums[0]<nums.back()||nums.size()==1) pos=0; //��һ�����������ת����СԪ�ص�λ��pos 
        else
        {
            int l=0,r=nums.size()-1,mid;
            while(l<r)
            {
                mid=l+r>>1;
                if(nums[mid]>=nums[0]) l=mid+1;   //���nums[mid]>=nums[0]˵��nums[0-mid]������nums[0] posһ����nums[mid+1~r] 
                else r=mid;  //nums[mid]<nums[0] ˵��pos��nums[l~mid] 
            }
            pos=l;
        } 
        int l=0,n=nums.size(),r=n-1,mid;
        while(l<r)
        {
            mid=l+r>>1;
            if(nums[(mid+pos)%n]>=target) r=mid; //��posΪԭ����ж��� pos-nums.size() 0-posΪ�������� 
            else l=mid+1;
        }
        l=(l+pos)%n;
        return nums[l]==target?l:-1;
    }
    //һ�ζ��� 
    int search(vector<int>& nums, int target) 
    {
        if(nums.empty()) return -1;
        int l=0,r=nums.size()-1,mid;
        while(l<r)
        {
            mid=l+r>>1;               //��0~pos�������ӣ�ǰ�벿�֣� pos-nums.size()-1�������� ����벿�֣� 
            if(nums[mid]>=nums[0]) // nums[mid]������ǰ�벿��
            {
                if(target<=nums[mid]&&target>=nums[0]) r=mid; //���target����nums[0]��nums[mid]֮�䣬��ôtargetһ���� l~mid�м� 
                else l=mid+1; //������ mid+1~r 
            }
            else   //nums[mid]�ں�벿�� 
            {
                if(nums[mid]<target&&nums[0]>target) l=mid+1; //ͬ��ɵ� 
                else r=mid;
            }
        }
        return nums[l]==target?l:-1;
    }
};
