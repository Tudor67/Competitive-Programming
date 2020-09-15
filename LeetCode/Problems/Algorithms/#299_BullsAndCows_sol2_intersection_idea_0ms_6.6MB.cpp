class Solution {
public:
    string getHint(string secret, string guess) {
        const int MAX_CHAR = '9';
        vector<int> secret_cnt(MAX_CHAR + 1, 0);
        vector<int> guess_cnt(MAX_CHAR + 1, 0);
        vector<int> match_cnt(MAX_CHAR + 1, 0);
        
        for(int i = 0; i < secret.length(); ++i){
            secret_cnt[secret[i]] += 1;
            guess_cnt[guess[i]] += 1;
            if(secret[i] == guess[i]){
                match_cnt[secret[i]] += 1;
            }
        }
        
        int a = 0;
        int b = 0;
        for(char c = '0'; c <= MAX_CHAR; ++c){
            a += match_cnt[c];
            b += min(secret_cnt[c], guess_cnt[c]) - match_cnt[c];
        }
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};