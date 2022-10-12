class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int N = names.size();
        
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {heights[i], i};
        }
        
        sort(v.rbegin(), v.rend());
        
        vector<string> res(N);
        for(int i = 0; i < N; ++i){
            res[i] = names[v[i].second];
        }
        
        return res;
    }
};