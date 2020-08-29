class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<pair<int, string>> v = {{3, "Fizz"}, {5, "Buzz"}};
        vector<string> answer(n);
        for(int i = 1; i <= n; ++i){
            for(const pair<int, string>& P: v){
                if(i % P.first == 0){
                    answer[i - 1] += P.second;
                }
            }
            if(answer[i - 1].empty()){
                answer[i - 1] = to_string(i);
            }
        }
        return answer;
    }
};