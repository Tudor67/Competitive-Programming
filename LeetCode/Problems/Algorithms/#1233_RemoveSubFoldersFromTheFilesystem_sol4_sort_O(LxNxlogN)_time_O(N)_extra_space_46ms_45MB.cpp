class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        const int N = folders.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (folders[lhs] < folders[rhs]);
             });

        vector<string> res;
        for(int i: p){
            if(!res.empty() &&
               res.back().length() < folders[i].length() &&
               folders[i][res.back().length()] == '/' &&
               equal(res.back().begin(), res.back().end(), folders[i].begin())){
                continue;
            }else{
                res.push_back(folders[i]);
            }
        }

        return res;
    }
};