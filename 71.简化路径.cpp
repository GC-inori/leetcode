���Ȼ�ȡ���з�б��֮������ݣ���ô�ܹ����������.��..��file_name�����������ķ�б�ܣ�ʹ��һ��ջ��ά����ǰ·����
��������������������ķ�б�ܻ���.����ô��������
������������ļ�������ջ
�����������..�����ջ��Ϊ�վ���ջ��
���ջ�е�Ԫ�ؾ��ǵ�ǰ�ļ�·����ע���Ƿ�Ϊ�ա�
class Solution {
public:
    string simplifyPath(string path) 
    {
        if(path.back()!='/') path.push_back('/');//�ڽ�β��ӷ�б�ܴ���߽���� 
        vector<string> res; //��vector����ջ 
        for(int i=0,n=path.size(),j;i<n;i=j)
        {
            j=i+1;
            while(j<n&&path[j]!='/') j++;//��ȡ������б��֮������� 
            if(i+1==j) continue; //���������ķ�б�� 
            string s=path.substr(i+1,j-i-1);
            if(s==".") continue;//��ǰĿ¼ 
            if(s=="..") //�����ϼ� 
            {
                if(res.size()) res.pop_back();
            }
            else res.push_back(s); //�ļ�����ջ 
        }
        if(res.empty()) return "/";
        string ans;
        for(auto &c:res) ans+="/"+c;
        return ans;
    }
};
