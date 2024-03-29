class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        const int N = s.length();
        const int LOG_N = floor(log2(N)) + 1;

        // Step 1: suffix arrays
        vector<vector<int>> c(2, vector<int>(N));
        for(int i = 0; i < N; ++i){
            c[0][i] = (s[i] - '0');
        }

        vector<pair<pair<int, int>, int>> v(N);
        for(int j = 1; j <= LOG_N; ++j){
            int len = (1 << j);
            for(int i = 0; i < N; ++i){
                int l = c[(j - 1) % 2][i];
                int r = (i + len / 2 < N ? c[(j - 1) % 2][i + len / 2] : -1);
                v[i].first = {l, r};
                v[i].second = i;
            }

            sort(v.begin(), v.end());

            int classID = 0;
            for(int i = 0; i < N; ++i){
                if(i > 0 && v[i - 1].first != v[i].first){
                    classID += 1;
                }
                int index = v[i].second;
                c[j % 2][index] = classID;
            }
        }

        // Step 2: sliding window (+ suffix arrays from step 1)
        int minLen = N + 1;
        int startIdx = -1;

        int ones = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            ones += (s[r] - '0');
            while(l <= r && (s[l] == '0' || ones > k)){
                ones -= (s[l] - '0');
                l += 1;
            }

            if(ones == k){
                int len = r - l + 1;
                if(minLen > len || (minLen == len && c[LOG_N % 2][startIdx] > c[LOG_N % 2][l])){
                    minLen = len;
                    startIdx = l;
                }
            }
        }

        if(startIdx < 0){
            return "";
        }
        return s.substr(startIdx, minLen);
    }
};