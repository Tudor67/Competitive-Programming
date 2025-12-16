class Solution {
private:
    int countPairs(int c){
        int validPairs = 0;
        for(int a = 1, b = c; a <= c; ++a){
            while(b >= 1 && a * a + b * b > c * c){
                b -= 1;
            }
            if(b >= 1 && a * a + b * b == c * c){
                validPairs += 1;
            }
        }
        return validPairs;
    }

public:
    int countTriples(int n) {
        int validTriples = 0;
        for(int c = 1; c <= n; ++c){
            validTriples += countPairs(c);
        }
        return validTriples;
    }
};