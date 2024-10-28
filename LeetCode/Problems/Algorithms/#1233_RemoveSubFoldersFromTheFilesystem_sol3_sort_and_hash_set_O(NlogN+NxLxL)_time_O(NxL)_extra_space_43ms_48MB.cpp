class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        const int N = folders.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (folders[lhs].length() < folders[rhs].length());
             });

        unordered_set<string> foldersSet;
        for(int i: p){
            string s;
            bool isSubFolder = false;
            for(char c: folders[i]){
                if(c == '/'){
                    if(foldersSet.count(s)){
                        isSubFolder = true;
                        break;
                    }
                }
                s += c;
            }

            if(!isSubFolder){
                foldersSet.insert(folders[i]);
            }
        }

        return vector<string>{foldersSet.begin(), foldersSet.end()};
    }
};