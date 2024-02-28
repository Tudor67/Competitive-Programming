class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        
        for(int i = low; i <= high; ++i){
            string s = to_string(i);
            const int L = s.length();

            int balance = 0;
            for(int l = 0, r = L - 1; l < r; ++l, --r){
                balance += (s[l] - s[r]);
            }

            if(L % 2 == 0 && balance == 0){
                res += 1;
            }
        }

        return res;
    }
};