class Solution {
public:
    string simplifyPath(string path) {
        string st = "/";
        
        int i = 0;
        int j = 1;
        while(j < path.length()){
            for(j = i + 1; j < path.length() && path[j] != '/'; ++j);
            string dirName = path.substr(i + 1, j - i - 1);
            if(dirName.empty() || dirName == "."){
                // ignore directory
            }else if(dirName == ".."){
                // remove previous directory (if possible)
                for(st.pop_back(); !st.empty() && st.back() != '/'; st.pop_back());
                if(st.empty()){
                    st += "/";
                }
            }else{
                // add directory
                st += dirName;
                st += "/";
            }
            i = j;
        }
        
        if(st.size() >= 2 && st.back() == '/'){
            st.pop_back();
        }
        
        return st;
    }
};