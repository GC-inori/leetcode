��l��r�ֱ�����߱������飬���l�ĸ߶�С��r�ĸ߶ȣ���ô��lΪ�߽������������l-rΧ�ɵģ����Ϊh[l]*(r-l) l++
�����ƶ�rָ�� ÿ�������һ��Ϊ�߽���ʢˮ�߶�Ϊh[l]��h[r]�������� 
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int l=0,r=height.size()-1,res=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                res=max((r-l)*height[l],res);  //���ʢˮ 
                l++;
            }
            else
            {
                res=max((r-l)*height[r],res); //���ұ߽�ʢˮ 
                r--;
            }
        }
        return res;
    }
};
