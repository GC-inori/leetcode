ֱ��ģ����ʽ�˷����㡣
�˻�����󳤶�Ϊ���������ĳ���֮�͡�
class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int mul1[120],mul2[120],res[230]={0},n=num1.size(),m=num2.size(),len=m+n-1;
        for(int i=0;i<n;i++) mul1[n-i-1]=num1[i]-'0';
        for(int i=0;i<m;i++) mul2[m-i-1]=num2[i]-'0';
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                res[i+j]+=mul1[i]*mul2[j];  //����ÿһλ�˻� 
                res[i+j+1]+=res[i+j]/10;
                res[i+j]%=10;
            }
        while(len&&res[len]==0) len--;  //len��С��0 ��ʱ������˽��Ϊ0 
        string ans;
        for(int i=len;~i;i--)
            ans.push_back(res[i]+'0');
        return ans;
    }
};
