class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        const int N = folder.size();
        
        vector<string> v = folder;
        sort(v.begin(), v.end());
        
        vector<string> folderNames = {v[0]};
        for(int i = 1; i < N; ++i){
            const int L = folderNames.back().length();
            if(folderNames.back().compare(0, L, v[i], 0, L) == 0 && L < (int)v[i].length() && v[i][L] == '/'){
                continue;
            }else{
                folderNames.push_back(v[i]);
            }
        }
        
        return folderNames;
    }
};