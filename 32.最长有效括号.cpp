˫��ɨ�衣

��һ���������ɨ�裬left��right�ֱ����ǰ�Ϸ��������Ÿ����������Ÿ���������������left ++������������right ++��
���left = right��˵���ҵ���һ���Ϸ������Ŷԣ����´𰸣����left < right��˵��������ôƥ�䶼�����ܺϷ��ˣ���ʱ��left��right��Ϊ0��

������������((())���������У��ò�����ȷ�⣬������Ǽ�����������ƥ��һ�Ρ�left>rightʱ��Ҳ�޷��ж��Ƿ�Ϸ��� "()(()"left=3 right=2 

�ڶ����һ���������ɨ�裬left��right�ֱ����ǰ�Ϸ��������Ÿ����������Ÿ���������������left ++������������right ++��
���left = right��˵���ҵ���һ���Ϸ������Ŷԣ����´𰸣����left > right��˵��ǰ����ôƥ�䶼�����ܺϷ��ˣ���ʱ��left��right��Ϊ0��

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int left=0,right=0,res=0;
        for(auto &c:s)
        {
            if(c=='(') left++;
            else
            {
                right++;
                if(right>left) right=left=0;
                else if(right==left) res=max(right<<1,res);
            }
        }
        right=left=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')') right++;
            else
            {
                left++;
                if(left>right) left=right=0;
                else if(left==right) res=max(left<<1,res);
            }
        }
        return res;    
    }
};
