class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int N = complexity.size();
        const int MODULO = 1'000'000'007;

        long long res = 1;
        for(int i = 1; i < N; ++i){
            if(complexity[0] < complexity[i]){
                res = (res * i) % MODULO;
            }else{
                return 0;
            }
        }

        return res;
    }
};