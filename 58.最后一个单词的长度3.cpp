class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        while(s.size()&&s.back()==' ') s.pop_back(); //ȥ����β�ո� 
        int res=0;
        for(int i=s.size()-1;~i;i--)
        {
            if(s[i]!=' ') res++; //��Ϊ�ո���� 
            else return res;  //���򷵻� 
        }
        return res;    
    }
};
