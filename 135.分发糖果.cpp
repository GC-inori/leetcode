��l[i] r[i]�ֱ��ʾ����ߵ�i��С�������ٷ������ǹ� �Ͱ��ұ����ٷ������ǹ�
l[i]=i��������ݼ���С��������+1 
���ո������ٷ�max(l[i],r[i])�� 
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size(),res=0;
        vector<int> l(ratings.size(),1),r=l;
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1]) l[i]=l[i-1]+1;
        for(int i=n-2;~i;i--)
            if(ratings[i]>ratings[i+1]) r[i]=r[i+1]+1;
        for(int i=0;i<n;i++)
            res+=max(l[i],r[i]);
        return res;
    }
};
