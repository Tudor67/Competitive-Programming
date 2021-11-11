class Solution {
public:
    int countTriples(int n) {
        vector<int> squares;
        for(int k = 1; k <= n; ++k){
            squares.push_back(k * k);
        }
        
        int triples = 0;
        for(int i = 1; i <= n; ++i){
            int k = 0;
            for(int j = 1; j <= n && k < (int)squares.size(); ++j){
                while(k < (int)squares.size() && i * i + j * j > squares[k]){
                    k += 1;
                }
                if(k < (int)squares.size() && i * i + j * j == squares[k]){
                    triples += 1;
                }
            }
        }
        
        return triples;
    }
};