class Solution 
{
//������ָ��i,j.��ʾ��j��ʼ�����ظ��ַ��ִ�[j,i].
//��i����ƶ�ʱ,�������ظ�,˵����j��ʼ������ظ��ַ���Ϊ[j,i-1];
//��ʱ������ƶ�j����s[j]!=s[i]˵��[j+1,i]�����ظ��ַ���һֱ�ƶ�ֱ��s[k]==s[i],��ʱ[k+1,i]�����ظ��ַ�
//������t����[j+1,k],[t,i]�����ظ��ַ����Ҵ�t��ʼ������ַ�С�ڴ�j��ʼ�ġ�
public:
    int lengthOfLongestSubstring(string s) 
    {
        bool flag[300]; //ֻ��Ҫ�����Ƿ���[j,i]����һ��bool���鼴�� 
        memset(flag,0,sizeof(flag));
        int res=0;
        for(int i=0,j=0,n=s.size();i<n;i++)
        {
            if(!flag[s[i]])
            {
                flag[s[i]]=1;
                res=max(res,i-j+1);
            }
            else
            {
                while(s[j]!=s[i])
                {
                    flag[s[j]]=0; //��j+1��ʼ�����ظ��ַ���һ��С�ڴ�j��ʼ�� 
                    j++;
                }
                j++;
            }
        }
        return res;
    }
};

