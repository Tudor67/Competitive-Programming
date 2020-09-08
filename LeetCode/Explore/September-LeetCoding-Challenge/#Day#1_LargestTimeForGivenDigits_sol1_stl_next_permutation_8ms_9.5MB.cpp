class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string answer;
        vector<int> digits = A;
        sort(digits.begin(), digits.end());
        
        do{
            string t = to_string(digits[0]) + to_string(digits[1]) +
                       ":" +
                       to_string(digits[2]) + to_string(digits[3]);
            if(t.substr(0, 2) <= "23" && t.substr(3, 2) <= "59"){
                if(answer.empty() || t > answer){
                    answer = t;
                }
            }
        }while(next_permutation(digits.begin(), digits.end()));
        
        return answer;
    }
};