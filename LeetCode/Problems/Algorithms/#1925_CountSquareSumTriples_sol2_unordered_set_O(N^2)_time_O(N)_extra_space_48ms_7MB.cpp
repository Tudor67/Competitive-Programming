class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> sqSet;
        for(int k = 1; k <= n; ++k){
            sqSet.insert(k * k);
        }
        
        int triples = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(sqSet.count(i * i + j * j)){
                    triples += 1;
                }
            }
        }
        
        return triples;
    }
};