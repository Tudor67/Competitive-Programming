class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        const int N = possible.size();

        int b = 0;
        for(int i = 0; i < N; ++i){
            if(possible[i]){
                b += 1;
            }else{
                b -= 1;
            }
        }

        int a = 0;
        for(int i = 0; i < N - 1; ++i){
            if(possible[i]){
                a += 1;
                b -= 1;
            }else{
                a -= 1;
                b += 1;
            }
            if(a > b){
                return i + 1;
            }
        }

        return -1;
    }
};