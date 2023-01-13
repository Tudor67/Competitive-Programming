class Solution {
public:
    int beautySum(string s) {
        const int N = s.length();
        const int A = 26;

        int res = 0;
        vector<int> count(100 + A);
        vector<int> count2(N + 1);

        for(int i = 0; i < N; ++i){
            int minCount = 1;
            int maxCount = 1;
            for(int j = i; j < N; ++j){
                count2[count[s[j]]] -= 1;
                count[s[j]] += 1;
                count2[count[s[j]]] += 1;

                if(count[s[j]] == 1){
                    minCount = 1;
                }else{
                    while(count2[minCount] == 0){
                        minCount += 1;
                    }
                }
                maxCount = max(maxCount, count[s[j]]);

                res += (maxCount - minCount);
            }

            for(char c = 'a'; c <= 'z'; ++c){
                count2[count[c]] = 0;
                count[c] = 0;
            }
        }

        return res;
    }
};