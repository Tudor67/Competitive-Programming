class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> mars(num + 2);
        for(int step = 1; step <= num; step *= 2){
            for(int i = step; i <= num; i += 2 * step){
                mars[i] += 1;
                mars[min(i + step, num + 1)] -= 1;
            }
        }
        
        vector<int> answer(num + 1);
        int bit_cnt = 0;
        for(int i = 0; i <= num; ++i){
            bit_cnt += mars[i];
            answer[i] = bit_cnt;
        }
        
        return answer;
    }
};