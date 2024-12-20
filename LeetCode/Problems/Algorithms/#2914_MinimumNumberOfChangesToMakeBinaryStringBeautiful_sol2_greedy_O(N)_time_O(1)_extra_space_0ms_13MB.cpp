class Solution {
public:
    int minChanges(string s) {
        const int N = s.length();

        int changes = 0;
        for(int i = 0; i + 1 < N; i += 2){
            if(s[i] != s[i + 1]){
                changes += 1;
            }
        }

        return changes;
    }
};