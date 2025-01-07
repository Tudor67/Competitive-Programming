class Solution {
private:
    int getRangeCount(vector<int>& prefixCount, int l, int r){
        if(l > r) return 0;
        if(l == 0) return prefixCount[r];
        return (prefixCount[r] - prefixCount[l - 1]);
    }

public:
    int countPalindromicSubsequence(string s) {
        const int N = s.length();
        const int A = 26;

        vector<vector<int>> prefixCount(A, vector<int>(N));
        prefixCount[s[0] - 'a'][0] = 1;
        for(int i = 1; i < N; ++i){
            for(char c = 'a'; c <= 'z'; ++c){
                prefixCount[c - 'a'][i] = prefixCount[c - 'a'][i - 1];
            }
            prefixCount[s[i] - 'a'][i] += 1;
        }

        unordered_set<int> palindromeCodes;
        for(int i = 1; i + 1 < N; ++i){
            for(char c = 'a'; c <= 'z'; ++c){
                if(getRangeCount(prefixCount[c - 'a'], 0, i - 1) >= 1 &&
                   getRangeCount(prefixCount[c - 'a'], i + 1, N - 1) >= 1){
                    palindromeCodes.insert((c - 'a') * A + s[i] - 'a');
                }
            }
        }

        return palindromeCodes.size();
    }
};