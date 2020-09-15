class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0;
        for(int i = 0; i < secret.length(); ++i){
            if(secret[i] == guess[i]){
                a += 1;
            }
        }
        
        int b = 0;
        vector<int> secret_cnt_for_wrong('9' + 1, 0);
        for(int i = 0; i < secret.length(); ++i){
            if(secret[i] != guess[i]){
                secret_cnt_for_wrong[secret[i]] += 1;
            }
        }
        
        for(int i = 0; i < guess.length(); ++i){
            if(guess[i] != secret[i] && secret_cnt_for_wrong[guess[i]] >= 1){
                secret_cnt_for_wrong[guess[i]] -= 1;
                b += 1;
            }
        }
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};