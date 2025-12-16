class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> squaresSet;
        for(int c = 1; c <= n; ++c){
            squaresSet.insert(c * c);
        }

        int validTriples = 0;
        for(int a = 1; a <= n; ++a){
            for(int b = 1; b <= n; ++b){
                if(squaresSet.count(a * a + b * b)){
                    validTriples += 1;
                }
            }
        }
        
        return validTriples;
    }
};