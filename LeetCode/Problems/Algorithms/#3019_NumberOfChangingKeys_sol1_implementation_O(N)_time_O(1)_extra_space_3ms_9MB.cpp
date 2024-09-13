class Solution {
public:
    int countKeyChanges(string s) {
        const int N = s.length();
        
        int keyChanges = 0;
        for(int i = 0; i + 1 < N; ++i){
            keyChanges += (int)(tolower(s[i]) != tolower(s[i + 1]));
        }

        return keyChanges;
    }
};