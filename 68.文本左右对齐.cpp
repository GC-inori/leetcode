ģ�� 
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> res;
        for(int i=0,n=words.size(),j,len;i<n;i=j)
        {
            string tmp=words[i];
            j=i+1;
            len=words[i].size();
            while(j<n&&len+words[j].size()<maxWidth)  //����Ӧ����ĵ��� i~j-1 �������ʼ�����һ���ո� 
            {
                len+=words[j].size()+1;
                j++;
            }
            if(j==n||j==i+1)  //��������һ�л�����ֻ��һ������ ����� 
            {
                for(int k=i+1;k<j;k++)
                    tmp+=" "+words[k];
                for(int k=len;k<maxWidth;k++) tmp.push_back(' ');  //ĩβ���ո� 
            }
            else
            {
                int l=len-j+i+1;  //������ĸ���� 
                len=(maxWidth-l)/(j-i-1); //���ٵĿո����� 
                string s1,s2;
                for(int k=0;k<len;k++) s2.push_back(' ');
                s1=" "+s2; //s1�϶�Ŀո� 
                for(int k=i+1,cnt=maxWidth-l-len*(j-i-1);k<j;k++)
                    if(k-i<=cnt) //�϶�ո������cnt 
                        tmp+=s1+words[k];
                    else tmp+=s2+words[k];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
