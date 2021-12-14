class Solution {
public:
    int maxPower(string s) {
        const int N = s.length();
        
        int maxCons = 0;
        int i = 0;
        while(i < N){
            int j = i + 1;
            while(j < N && s[i] == s[j]){
                j += 1;
            }
            maxCons = max(maxCons, j - i);
            i = j;
        }
        
        return maxCons;
    }
};