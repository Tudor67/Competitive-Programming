class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int N = names.size();
        
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        
        sort(p.begin(), p.end(),
             [&](const int& LHS, const int& RHS){
                 return (heights[LHS] > heights[RHS]);
             });
        
        vector<string> res(N);
        for(int i = 0; i < N; ++i){
            res[i] = names[p[i]];
        }
        
        return res;
    }
};