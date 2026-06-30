class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.length();
        const int INF = 1e9;

        vector<int> nextA(N + 1, INF);
        vector<int> nextB(N + 1, INF);
        vector<int> nextC(N + 1, INF);
        for(int i = N - 1; i >= 0; --i){
            nextA[i] = nextA[i + 1];
            nextB[i] = nextB[i + 1];
            nextC[i] = nextC[i + 1];
            if(s[i] == 'a'){
                nextA[i] = i;
            }else if(s[i] == 'b'){
                nextB[i] = i;
            }else if(s[i] == 'c'){
                nextC[i] = i;
            }
        }

        int validSubstrings = 0;
        for(int i = 0; i < N; ++i){
            int j = max({nextA[i], nextB[i], nextC[i]});
            if(j != INF){
                validSubstrings += (N - j);
            }
        }

        return validSubstrings;
    }
};