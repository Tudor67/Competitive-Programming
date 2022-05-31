class Solution {
private:
    long long nCk(int n, int k){
        long long res = 1;
        for(int i = 1; i <= k; ++i){
            res *= (n + 1 - i);
            res /= i;
        }
        return res;
    }
    
public:
    int countVowelStrings(int N) {
        return nCk(N + 4, 4);
    }
};