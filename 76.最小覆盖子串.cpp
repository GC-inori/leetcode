�����ù�ϣ��ͳ�Ƴ� TT �������ַ����ֵĴ���
Ȼ��������ָ�� l,r(r>+l)��ɨ�������ַ�����ͬʱ��һ����ϣ��ͳ��l-r֮��ÿ���ַ����ֵĴ�����ÿ�α�����Ҫ�Ĳ������£�
���� s[r]��ͬʱ���¹�ϣ��
��� s[l] �Ƿ���࣬����ǣ����Ƴ� s[j]s[j]��
��鵱ǰ�����Ƿ��Ѿ����� T �������ַ�������ǣ�����´𰸣�
class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int> hash;
        int cnt=0,mn=1e9,x;
        for(auto &c:t)
        {
            if(!hash.count(c)) cnt++;
            hash[c]++;
        }
        for(int l=0,r=0,n=s.size(),cur_cnt=0;r<n;r++)
        {
            if(hash[s[r]]==1) cur_cnt++; 
            hash[s[r]]--; //����s[r]�����s[r]==1˵������s[r]֮���и��ַ����������� cnt++  
            while(hash[s[l]]<0) hash[s[l++]]++;//���õĳ��� 
            if(cnt==cur_cnt&&r-l+1<mn) //���´� 
            {
                mn=r-l+1;
                x=l;
            }
               
        }
        return mn==1e9?"":s.substr(x,mn);  
    }
};
