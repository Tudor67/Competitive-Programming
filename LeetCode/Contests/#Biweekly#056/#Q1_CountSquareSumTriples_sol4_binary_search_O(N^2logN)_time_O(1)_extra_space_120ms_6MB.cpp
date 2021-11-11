class Solution {
private:
    int getSquareRoot(int x){
        int l = 1;
        int r = x;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(mid <= x / mid){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
    
public:
    int countTriples(int n) {
        int triples = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                int squareRoot = getSquareRoot(i * i + j * j);
                if(squareRoot <= n && squareRoot * squareRoot == i * i + j * j){
                    triples += 1;
                }
            }
        }
        return triples;
    }
};