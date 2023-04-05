class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        const int N = word.length();
        
        vector<int> answer(N);
        
        long long rem = 0;
        for(int i = 0; i < N; ++i){
            rem = (rem * 10 + (word[i] - '0')) % m;
            if(rem == 0){
                answer[i] = 1;
            }
        }
        
        return answer;
    }
};