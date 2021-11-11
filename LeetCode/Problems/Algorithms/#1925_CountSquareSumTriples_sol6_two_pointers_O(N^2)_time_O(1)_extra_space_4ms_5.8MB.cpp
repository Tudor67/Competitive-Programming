class Solution {
public:
    int countTriples(int n) {
        int triples = 0;
        for(int i = 1; i <= n; ++i){
            int k = 1;
            for(int j = 1; j <= n && k <= n; ++j){
                while(k <= n && i * i + j * j > k * k){
                    k += 1;
                }
                if(k <= n && i * i + j * j == k * k){
                    triples += 1;
                }
            }
        }
        return triples;
    }
};