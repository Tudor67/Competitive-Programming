class Solution {
private:
    int rle(int charCount){
        if(charCount == 0){
            return 0;
        }else if(charCount == 1){
            return 1;
        }else if(charCount <= 9){
            return 2;
        }else if(charCount <= 99){
            return 3;
        }
        return 4;
    }

    int solve(int i, int k, char prevChar, int prevCharCount, string& s, unordered_map<int, int>& memo){
        const int N = s.length();

        if(i >= N - k){
            return 0;
        }

        int state = i | (k << 7) | ((prevChar - 'a') << 14) | (prevCharCount << 20);
        if(memo.count(state)){
            return memo[state];
        }

        int charCount = (prevChar == s[i] ? prevCharCount + 1 : 1);
        int keepCost = rle(charCount) - rle(charCount - 1) + solve(i + 1, k, s[i], charCount, s, memo);
        int removeCost = (k == 0 ? N : solve(i + 1, k - 1, prevChar, prevCharCount, s, memo));

        memo[state] = min(keepCost, removeCost);
        return memo[state];
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        unordered_map<int, int> memo;
        return solve(0, k, 'z' + 1, 0, s, memo);
    }
};