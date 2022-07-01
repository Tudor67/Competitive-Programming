class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> v = {a, b, c};
        
        int score = 0;
        while(true){
            sort(v.begin(), v.end());
            if(v[1] >= 1){
                v[1] -= 1;
                v[2] -= 1;
                score += 1;
            }else{
                break;
            }
        }
        
        return score;
    }
};