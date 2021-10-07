class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        const int N = s.length();
        const int Q = queries.size();
        
        vector<int> prefixCountMask(N);
        prefixCountMask[0] = (1 << (s[0] - 'a'));
        for(int i = 1; i < N; ++i){
            prefixCountMask[i] = prefixCountMask[i - 1] ^ (1 << (s[i] - 'a'));
        }
        
        vector<bool> answer(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int rangeCountMask = prefixCountMask[r];
            if(l >= 1){
                rangeCountMask ^= prefixCountMask[l - 1];
            }
            if(__builtin_popcount((unsigned int)rangeCountMask) - 1 <= 2 * k){
                answer[i] = true;
            }else{
                answer[i] = false;
            }
        }
        
        return answer;
    }
};