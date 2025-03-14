class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.length();

        vector<vector<int>> suffCount(3, vector<int>(N + 1));
        for(int i = N - 1; i >= 0; --i){
            for(int j = 0; j < 3; ++j){
                suffCount[j][i] = suffCount[j][i + 1];
            }
            suffCount[s[i] - 'a'][i] += 1;
        }

        int validSubstrings = 0;
        for(int i = 0; i < N; ++i){
            int l = i;
            int r = N;
            while(l != r){
                int mid = (l + r) / 2;
                if(suffCount[0][i] - suffCount[0][mid + 1] >= 1 &&
                   suffCount[1][i] - suffCount[1][mid + 1] >= 1 &&
                   suffCount[2][i] - suffCount[2][mid + 1] >= 1){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }

            validSubstrings += (N - r);
        }

        return validSubstrings;
    }
};