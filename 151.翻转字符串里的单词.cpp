���η�ת �Ƚ�ÿ�����ʷ�ת �ٽ������ַ�����ת 
class Solution {
public:
    string reverseWords(string s) 
    {
        while(s.size()&&s.back()==' ') s.pop_back();//ȥ��ĩβ�ո� 
        if(s.empty()) return s;
        int k=0;
        for(int i=0,n=s.size(),t;i<n;i++)
        {
            if(s[i]==' ') continue;//�ҵ����ʿ�ʼλ�� 
            t=k;
            while(i<n&&s[i]!=' ') s[k++]=s[i++];//�ҵ�����λ�� 
            reverse(s.begin()+t,s.begin()+k);//��ת 
            if(i<n) s[k++]=' ';//�ڷǽ�β���ʺ���ӿո� 
        }
        s.erase(s.begin()+k,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};
