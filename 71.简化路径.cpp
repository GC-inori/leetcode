首先获取所有反斜杠之间的内容，那么总共有四种情况.，..，file_name，两个连续的反斜杠，使用一个栈来维护当前路径。
如果读到的是两个连续的反斜杠或者.，那么不做操作
如果读到的是文件名，入栈
如果读到的是..，如果栈不为空就退栈。
最后栈中的元素就是当前文件路径，注意是否为空。
class Solution {
public:
    string simplifyPath(string path) 
    {
        if(path.back()!='/') path.push_back('/');//在结尾填加反斜杠处理边界情况 
        vector<string> res; //用vector当作栈 
        for(int i=0,n=path.size(),j;i<n;i=j)
        {
            j=i+1;
            while(j<n&&path[j]!='/') j++;//读取两个反斜杠之间的内容 
            if(i+1==j) continue; //两个连续的反斜杠 
            string s=path.substr(i+1,j-i-1);
            if(s==".") continue;//当前目录 
            if(s=="..") //返回上级 
            {
                if(res.size()) res.pop_back();
            }
            else res.push_back(s); //文件名入栈 
        }
        if(res.empty()) return "/";
        string ans;
        for(auto &c:res) ans+="/"+c;
        return ans;
    }
};
