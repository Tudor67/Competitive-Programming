class Solution {
public:
    string simplifyPath(string path) {
        const int N = path.length();

        vector<string> st;
        string dirName;

        for(int i = 0; i < N; ++i){
            if(path[i] != '/'){
                dirName += path[i];
            }

            if(path[i] == '/' || i == N - 1){
                if(dirName == ".." && !st.empty()){
                    st.pop_back();
                }else if(dirName != "." && dirName != ".." && !dirName.empty()){
                    st.push_back(dirName);
                }
                dirName.clear();
            }
        }

        string canonicalPath;
        for(string& dirName: st){
            canonicalPath += "/";
            canonicalPath += dirName;
        }

        if(canonicalPath.empty()){
            canonicalPath = "/";
        }

        return canonicalPath;
    }
};