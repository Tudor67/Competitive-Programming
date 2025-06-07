class Solution {
public:
    string answerString(string word, int numFriends) {
        const int N = word.length();
        const int LOG_N = log2(N) + 1;
        const int MAX_LEN = N - numFriends + 1;

        if(numFriends == 1){
            return word;
        }

        vector<vector<int>> c(2, vector<int>(N));
        for(int i = 0; i < N; ++i){
            c[0][i] = word[i] - 'a';
        }

        vector<array<int, 3>> v(N);
        for(int k = 1; k <= LOG_N; ++k){
            int len = (1 << k);
            for(int i = 0; i < N; ++i){
                int l = c[(k - 1) % 2][i];
                int r = (i + len / 2 < N ? c[(k - 1) % 2][i + len / 2] : -1);
                v[i] = {l, r, i};
            }

            sort(v.begin(), v.end());

            int classID = 0;
            for(int i = 0; i < N; ++i){
                if(i > 0 && (v[i - 1][0] != v[i][0] || v[i - 1][1] != v[i][1])){
                    classID += 1;
                }
                c[k % 2][v[i][2]] = classID;
            }
        }

        int resStartIndex = max_element(c[LOG_N % 2].begin(), c[LOG_N % 2].end()) - c[LOG_N % 2].begin();

        return word.substr(resStartIndex, MAX_LEN);
    }
};