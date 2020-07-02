class Solution {
public:
    string reverseWords(string s) {
        string answer;
        
        // Step 1
        reverse(s.begin(), s.end());
        s += " ";
        
        // Step 2
        for(int i = 0, start_pos = 0; i < s.length(); ++i){
            if(s[i] == ' '){
                if(!answer.empty() && answer.back() != ' '){
                    reverse(answer.rbegin(), answer.rbegin() + i - start_pos);
                    answer += " ";
                }
                start_pos = i + 1;
            }else{
                answer += s[i];
            }
        }
        
        // Step 3
        if(!answer.empty() && answer.back() == ' '){
            answer.pop_back();
        }
        
        return answer;
    }
};