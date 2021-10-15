class Solution {
public:
    int numSquares(int N) {
        vector<bool> set1(N + 1, false);        
        vector<bool> set2(N + 1, false);
        for(int i = 1; i * i <= N; ++i){
            set1[i * i] = true;
            for(int j = 1; i * i + j * j <= N; ++j){
                set2[i * i + j * j] = true;
            }
        }
        
        if(set1[N]){
            return 1;
        }
        
        if(set2[N]){
            return 2;
        }
        
        for(int i = 1; i * i <= N; ++i){
            if(set2[N - i * i]){
                return 3;
            }
        }
        
        return 4;
    }
};