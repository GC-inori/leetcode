模拟 
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
            while(j<n&&len+words[j].size()<maxWidth)  //求本行应该填的单词 i~j-1 两个单词间至少一个空格 
            {
                len+=words[j].size()+1;
                j++;
            }
            if(j==n||j==i+1)  //如果是最后一行或者是只填一个单词 左对齐 
            {
                for(int k=i+1;k<j;k++)
                    tmp+=" "+words[k];
                for(int k=len;k<maxWidth;k++) tmp.push_back(' ');  //末尾填充空格 
            }
            else
            {
                int l=len-j+i+1;  //计算字母总数 
                len=(maxWidth-l)/(j-i-1); //较少的空格数量 
                string s1,s2;
                for(int k=0;k<len;k++) s2.push_back(' ');
                s1=" "+s2; //s1较多的空格 
                for(int k=i+1,cnt=maxWidth-l-len*(j-i-1);k<j;k++)
                    if(k-i<=cnt) //较多空格的数量cnt 
                        tmp+=s1+words[k];
                    else tmp+=s2+words[k];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
