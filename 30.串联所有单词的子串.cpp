�������ڡ���Ϊÿ�������еĳ�����ͬ����ô���ǿ��Ը���ÿ��ö�ٵ���ʼλ�ý��仮��Ϊlen�鲻ͬ��ƥ�䡣
���� 
len = 3,s = abcdefghijkl
����1: abc def ghi jkl
����2: bcd efg hij
����3: cde fgh ijk

����ö�����еĻ������λ�ã�Ȼ��j-words[0].size()*(words.size()-1),j�ֱ����ǰ���ڵ�����ָ�룬cur_hash��¼��ǰ������ÿ�����ʳ��ֵĴ�����cnt��¼words�кʹ������ظ����ʵ�������ÿ�ζ���һ�����ʣ�
�����ǰ����û�г��ֹ���˵��ʧ���ˣ���ô��jָ����ƣ�����ƥ�䡣
������ֹ�������cur_hash��
�����ǰ���ʳ��ָ���С�ڵ���������Ҫ�ĵ��ʸ�������ô˵���ҵ���һ���µĿ�����ĵ��ʣ�����cnt��
�����ǰ���ʵ��ʳ��ָ�������������Ҫ�ĵ��ʸ�������ô�õ���û�ò��ø���cnt 
���cnt==words.size() ˵���ҵ��˴𰸼�¼ 

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> res;
        if(s.empty()||words.empty()||words[0].empty()) return res;
        unordered_map<string,int> hash;
        for(auto &c:words) hash[c]++;  //��¼words��ÿ�����ʵĸ��� 
        for(int i=0,n1=words[0].size(),n2=s.size(),n3=words.size();i<n1;i++)
        {
            unordered_map<string,int> cur_hash;
            for(int j=i,cnt=0;j+n1-1<n2;j+=n1)
            {
                if((j-i)/n1>=n3)
                {
                    string tmp=s.substr(j-n3*n1,n1);
                    cur_hash[tmp]--;
                    if(hash.count(tmp)&&hash[tmp]>cur_hash[tmp]) cnt--; //�����γ����ڵĵ���������ƥ�䵥�ʸ�����һ 
                }
                string tmp=s.substr(j,n1);
                cur_hash[tmp]++;
                if(hash.count(tmp)&&hash[tmp]>=cur_hash[tmp]) cnt++;//�����ν����ڵĵ���������ƥ�䵥�ʸ�����һ 
                if(cnt==n3) res.push_back(j-(n3-1)*n1);
            }
        }
        return res;
    }
};
