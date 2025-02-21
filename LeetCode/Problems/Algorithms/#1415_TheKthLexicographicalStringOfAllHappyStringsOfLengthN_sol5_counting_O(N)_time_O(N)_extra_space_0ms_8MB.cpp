class Solution {
private:
    char getKthLetterExcludingX(int k, char x){
        char c = 'a' + k - 1;
        if('a' <= x && x <= c){
            c += 1;
        }
        return c;
    }

public:
    string getHappyString(int n, int k) {
        vector<int> pow2(n, 1);
        for(int i = 1; i < n; ++i){
            pow2[i] = pow2[i - 1] * 2;
        }

        if(3 * pow2[n - 1] < k){
            return "";
        }

        string res(n, 'a');
        if(pow2[n - 1] >= k){
            res[0] = getKthLetterExcludingX(1, '$');
        }else if(2 * pow2[n - 1] >= k){
            res[0] = getKthLetterExcludingX(2, '$');
            k -= pow2[n - 1];
        }else{
            res[0] = getKthLetterExcludingX(3, '$');
            k -= 2 * pow2[n - 1];
        }

        for(int i = 1; i < n; ++i){
            if(pow2[n - 1 - i] >= k){
                res[i] = getKthLetterExcludingX(1, res[i - 1]);
            }else if(2 * pow2[n - 1 - i] >= k){
                res[i] = getKthLetterExcludingX(2, res[i - 1]);
                k -= pow2[n - 1 - i];
            }
        }

        return res;
    }
};