//�ҹ���
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(s.size()<=numRows||numRows==1) return s;
        string res;
        int step1=2*numRows-2;  //ÿ��ѭ������Ϊstep1=2*numRows-2
        for(int i=0,n=s.size(),step2;i<numRows;i++)
            for(int j=i;j<n;j+=step1)
            {
                res.push_back(s[j]);
                step2=i?2*(numRows-i-1):0;   //��һ�к����һ�в���Ҫ��ӵڶ���
                if(step2&&j+step2<n) res.push_back(s[j+step2]);
            }
        return res;
    }
};
