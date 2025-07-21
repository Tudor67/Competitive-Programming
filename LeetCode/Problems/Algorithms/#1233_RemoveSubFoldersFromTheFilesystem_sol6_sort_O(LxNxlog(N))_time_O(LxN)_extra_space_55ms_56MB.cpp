class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        const int N = folders.size();

        vector<string> sortedFolders = folders;
        sort(sortedFolders.begin(), sortedFolders.end());

        vector<bool> isSubFolder(N, false);
        vector<string> res;
        for(int i = 0; i < N; ++i){
            if(!isSubFolder[i]){
                res.push_back(sortedFolders[i]);
                const int LEN = sortedFolders[i].length();
                for(int j = i + 1; j < N; ++j){
                    if(!isSubFolder[j] &&
                       LEN < (int)sortedFolders[j].length() &&
                       sortedFolders[j][LEN] == '/' &&
                       sortedFolders[i].compare(0, LEN, sortedFolders[j], 0, LEN) == 0){
                        isSubFolder[j] = true;
                    }else{
                        break;
                    }
                }
            }
        }

        return res;
    }
};