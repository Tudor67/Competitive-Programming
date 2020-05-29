class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> answer(num + 1);
        for(int step = 1; step <= num; step *= 2){
            for(int i = step; i <= num; i += 2 * step){
                for(int j = i; j <= min(i + step - 1, num); ++j){
                    ++answer[j];
                }
            }
        }
        return answer;
    }
};