class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        const int N = s.length();
        const int INITIAL_ONES = count(s.begin(), s.end(), '1');
        const int Q = queries.size();

        vector<int> zeros;
        vector<int> starts;
        int currZeros = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '0'){
                currZeros += 1;
                if(i + 1 == N || s[i + 1] == '1'){
                    zeros.push_back(currZeros);
                    starts.push_back(i - currZeros + 1);
                    currZeros = 0;
                }
            }
        }

        vector<int> res(Q);
        for(int qIdx = 0; qIdx < Q; ++qIdx){
            int l = queries[qIdx][0];
            int r = queries[qIdx][1];

            int maxGain = 0;
            for(int i = 0; i + 1 < (int)zeros.size(); ++i){
                if(l <= starts[i] + zeros[i] - 1 && starts[i + 1] <= r){
                    int currGain = zeros[i] - max(0, l - starts[i]) +
                                   zeros[i + 1] - max(0, (starts[i + 1] + zeros[i + 1] - 1) - r);
                    maxGain = max(maxGain, currGain);
                }
            }

            res[qIdx] = INITIAL_ONES + maxGain;
        }

        return res;
    }
};