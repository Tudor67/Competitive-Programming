class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        const int N = digits.size();
        const int MAX_VALID_NUM = 999;

        vector<bool> vis(MAX_VALID_NUM + 1, false);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                for(int k = 0; k < N; ++k){
                    if(i != j && i != k && j != k &&
                       digits[i] != 0 && digits[k] % 2 == 0){
                        vis[digits[i] * 100 + digits[j] * 10 + digits[k]] = true;
                    }
                }
            }
        }

        return count(vis.begin(), vis.end(), true);
    }
};