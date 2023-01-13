class Solution {
public:
    int beautySum(string s) {
        const int N = s.length();
        const int A = 26;

        int res = 0;
        vector<int> count(100 + A);
        for(int i = 0; i < N; ++i){
            fill(count.begin() + 'a', count.begin() + 'z' + 1, 0);
            for(int j = i; j < N; ++j){
                count[s[j]] += 1;
                int minCount = N + 1;
                int maxCount = 0;
                for(char c = 'a'; c <= 'z'; ++c){
                    if(count[c] > 0){
                        minCount = min(minCount, count[c]);
                        maxCount = max(maxCount, count[c]);
                    }
                }
                res += (maxCount - minCount);
            }
        }

        return res;
    }
};