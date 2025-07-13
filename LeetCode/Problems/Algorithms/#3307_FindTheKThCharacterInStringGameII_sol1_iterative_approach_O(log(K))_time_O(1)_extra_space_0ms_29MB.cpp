class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int i = 0;
        long long len = 2;
        while(len < k){
            i += 1;
            len *= 2;
        }

        int shift = 0;
        while(len > 1){
            if(k > len / 2){
                k -= len / 2;
                shift = (shift + operations[i]) % 26;
            }
            i -= 1;
            len /= 2;
        }

        return char('a' + shift);
    }
};