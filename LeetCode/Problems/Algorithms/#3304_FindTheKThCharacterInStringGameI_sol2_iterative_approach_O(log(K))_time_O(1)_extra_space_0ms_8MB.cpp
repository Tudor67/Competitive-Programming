class Solution {
public:
    char kthCharacter(int k) {
        int len = 1;
        while(len < k){
            len *= 2;
        }

        int shift = 0;
        while(len > 1){
            if(k > len / 2){
                k -= len / 2;
                shift = (shift + 1) % 26;
            }
            len /= 2;
        }

        return char('a' + shift);
    }
};