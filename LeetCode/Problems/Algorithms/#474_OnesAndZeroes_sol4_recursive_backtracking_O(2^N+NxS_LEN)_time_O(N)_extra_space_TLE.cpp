class Solution {
private:
    vector<int> zerosAt;
    vector<int> onesAt;
    
    int solve(int i, int zeros, int ones){
        if(i == -1){
            return 0;
        }
        int opt1 = 0;
        if(zeros >= zerosAt[i] && ones >= onesAt[i]){
            opt1 = 1 + solve(i - 1, zeros - zerosAt[i], ones - onesAt[i]);
        }
        int opt2 = solve(i - 1, zeros, ones);
        return max(opt1, opt2);
    }
    
public:
    int findMaxForm(vector<string>& strs, int ZEROS, int ONES) {
        const int N = strs.size();
        zerosAt.resize(N);
        onesAt.resize(N);
        for(int i = 0; i < N; ++i){
            zerosAt[i] = count(strs[i].begin(), strs[i].end(), '0');
            onesAt[i] = count(strs[i].begin(), strs[i].end(), '1');
        }
        return solve(N - 1, ZEROS, ONES);
    }
};