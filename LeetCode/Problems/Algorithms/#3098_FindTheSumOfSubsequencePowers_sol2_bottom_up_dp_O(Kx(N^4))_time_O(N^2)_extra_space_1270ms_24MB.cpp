class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> diffs;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                diffs.push_back(sortedNums[j] - sortedNums[i]);
            }
        }

        sort(diffs.begin(), diffs.end());
        diffs.resize(unique(diffs.begin(), diffs.end()) - diffs.begin());

        int res = 0;
        vector<vector<int>> dpG(k + 1, vector<int>(N));
        vector<vector<int>> dpE(k + 1, vector<int>(N));

        for(int diff: diffs){
            // dpG[len][i]: number of subsequences of length len, min difference > diff,
            //              and the last taken element sortedNums[i]
            // dpE[len][i]: number of subsequences of length len, min difference == diff,
            //              and the last taken element sortedNums[i]
            fill(dpG[2].begin(), dpG[2].end(), 0);
            fill(dpE[2].begin(), dpE[2].end(), 0);
            for(int i = 0; i < N; ++i){
                for(int j = i + 1; j < N; ++j){
                    if(sortedNums[j] - sortedNums[i] > diff){
                        dpG[2][j] += 1;
                    }
                    if(sortedNums[j] - sortedNums[i] == diff){
                        dpE[2][j] += 1;
                    }
                }
            }

            for(int len = 3; len <= k; ++len){
                fill(dpG[len].begin(), dpG[len].end(), 0);
                fill(dpE[len].begin(), dpE[len].end(), 0);
                for(int i = 0; i < N; ++i){
                    for(int j = i + 1; j < N; ++j){
                        if(sortedNums[j] - sortedNums[i] > diff){
                            dpG[len][j] += dpG[len - 1][i];
                            dpG[len][j] %= MODULO;
                            dpE[len][j] += dpE[len - 1][i];
                            dpE[len][j] %= MODULO;
                        }else if(sortedNums[j] - sortedNums[i] == diff){
                            dpE[len][j] += dpG[len - 1][i];
                            dpE[len][j] %= MODULO;
                            dpE[len][j] += dpE[len - 1][i];
                            dpE[len][j] %= MODULO;
                        }
                    }
                }
            }

            for(int i = 0; i < N; ++i){
                res += (long long)diff * (long long)dpE[k][i] % MODULO;
                res %= MODULO;
            }
        }

        return res;
    }
};