class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        
        const int N = path.length();
        
        string st = "/";
        int prevPos = 0;
        for(int i = 1; i < N; ++i){
            if(path[i] == '/'){
                int len = i - prevPos - 1;
                string dirName = path.substr(prevPos + 1, len);
                
                if(dirName.empty() || dirName == "."){
                    // ignore
                }else if(dirName == ".."){
                    // remove dir from st
                    if((int)st.size() >= 2 && st.back() == '/'){
                        st.pop_back();
                    }
                    while((int)st.size() >= 2 && st.back() != '/'){
                        st.pop_back();
                    }
                }else{
                    st += dirName;
                    st += '/';
                }
                
                prevPos = i;
            }
        }
        
        if((int)st.size() >= 2 && st.back() == '/'){
            st.pop_back();
        }
        
        return st;
    }
};