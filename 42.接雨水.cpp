˫ָ���㷨
��ʼʱl = 0, r = n - 1��lmax,rmax�ֱ����lָ��������ֵ����rָ���Ҳ����ֵ�����height[l] < height[r]��˵����ʱ�谭��ǰʢˮ������࣬���Խ�lָ�����ơ�
���height[l] < height[r]
1. rmax>=lmax ��Ȼ�� height[l]����ʢˮlmax-height[l];
2. rmax<lmax ��ôlָ�벻���ƶ���ֱ�� height[l] < height[r] ��ʱ height[l]����ʢˮlmax-height[l]����height[l]���������ֵ��Ϊheight[l] < height[r]�� 
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int lmax=0,rmax=0,l=0,r=height.size()-1,res=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                if(height[l]>lmax) lmax=height[l];
                res+=lmax-height[l++];
            }
            else
            {
                if(height[r]>rmax) rmax=height[r];
                res+=rmax-height[r--];
            }
        }
        return res;    
    }
};
