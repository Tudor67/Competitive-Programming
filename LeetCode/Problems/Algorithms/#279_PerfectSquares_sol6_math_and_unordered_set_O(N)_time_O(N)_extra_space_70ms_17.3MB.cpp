class Solution {
public:
    int numSquares(int N) {
        unordered_set<int> set1;        
        unordered_set<int> set2;
        for(int i = 1; i * i <= N; ++i){
            set1.insert(i * i);
            for(int j = 1; i * i + j * j <= N; ++j){
                set2.insert(i * i + j * j);
            }
        }
        
        if(set1.count(N)){
            return 1;
        }
        
        if(set2.count(N)){
            return 2;
        }
        
        for(int i = 1; i * i <= N; ++i){
            if(set2.count(N - i * i)){
                return 3;
            }
        }
        
        return 4;
    }
};