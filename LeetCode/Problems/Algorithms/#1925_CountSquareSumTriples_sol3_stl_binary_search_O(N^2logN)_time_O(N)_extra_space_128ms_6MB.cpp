class Solution {
public:
    int countTriples(int n) {
        vector<int> squares;
        for(int k = 1; k <= n; ++k){
            squares.push_back(k * k);
        }
        
        int triples = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(binary_search(squares.begin(), squares.end(), i * i + j * j)){
                    triples += 1;
                }
            }
        }
        
        return triples;
    }
};