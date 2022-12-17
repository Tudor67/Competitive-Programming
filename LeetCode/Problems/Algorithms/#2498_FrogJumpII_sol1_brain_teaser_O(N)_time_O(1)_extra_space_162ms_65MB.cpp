class Solution {
public:
    int maxJump(vector<int>& v) {
        const int N = v.size();
        
        int res = max(v[1] - v[0], v[N - 1] - v[N - 2]);
        for(int i = 2; i < N; ++i){
            res = max(res, v[i] - v[i - 2]);
        }

        return res;
    }
};