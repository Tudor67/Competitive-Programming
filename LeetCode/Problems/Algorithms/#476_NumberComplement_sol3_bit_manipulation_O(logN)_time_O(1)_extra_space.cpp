class Solution {
public:
    int findComplement(int num) {
        int numComplement = 0;
        int bit = 0;
        while(num > 0){
            if(num % 2 == 0){
                numComplement |= (1 << bit);
            }
            num /= 2;
            bit += 1;
        }
        return numComplement;
    }
};