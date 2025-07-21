class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        const int N = folders.size();

        vector<string> sortedFolders = folders;
        sort(sortedFolders.begin(), sortedFolders.end());

        vector<string> res = {sortedFolders[0]};
        for(int i = 1; i < N; ++i){
            int resLen = res.back().length();
            if(resLen < (int)sortedFolders[i].length() &&
               sortedFolders[i][resLen] == '/' &&
               res.back().compare(0, resLen, sortedFolders[i], 0, resLen) == 0){
                // ignore subfolders
            }else{
                res.push_back(sortedFolders[i]);
            }
        }

        return res;
    }
};