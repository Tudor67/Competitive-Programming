class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> answer(num + 1);
        for(int i = 1; i <= num; ++i){
            answer[i] = (i % 2) + answer[i / 2];
        }
        return answer;
    }
};