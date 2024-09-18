class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        const int N = word.length();

        vector<int> z(N);
        int l = 0;
        int r = 0;
        for(int i = 1; i < N; ++i){
            if(i <= r){
                z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < N && word[z[i]] == word[i + z[i]]){
                z[i] += 1;
            }
            if(r <= i + z[i] - 1){
                l = i;
                r = i + z[i] - 1;
            }
        }

        for(int i = k; i < N; i += k){
            if(i + z[i] == N){
                return i / k;
            }
        }

        return (N + k - 1) / k;
    }
};