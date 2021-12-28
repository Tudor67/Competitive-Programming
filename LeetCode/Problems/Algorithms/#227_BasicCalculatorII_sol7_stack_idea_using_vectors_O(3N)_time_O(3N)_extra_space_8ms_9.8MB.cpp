class Solution {
public:
    int calculate(string originalS) {
        // remove redundant spaces from originalS
        string s;
        for(char c: originalS){
            if(c != ' '){
                s += c;
            }
        }
        
        // parse the string s
        const int N = s.length();
        vector<int> nums;
        vector<char> operators;
        
        // '*' and '/' operators
        int num = 0;
        for(int i = 0; i < N; ++i){
            if(isdigit(s[i])){
                num = 10 * num + (s[i] - '0');
            }
            if(!isdigit(s[i]) || i == N - 1){
                if(!operators.empty() && operators.back() == '*'){
                    nums.back() *= num;
                    operators.pop_back();
                }else if (!operators.empty() && operators.back() == '/'){
                    nums.back() /= num;
                    operators.pop_back();
                }else{
                    nums.push_back(num);
                }
                num = 0;
            }
            if(!isdigit(s[i])){
                operators.push_back(s[i]);
            }
        }
        
        // '+' and '-' operators
        int result = nums[0];
        for(int i = 0; i < (int)operators.size(); ++i){
            if(operators[i] == '+'){
                result += nums[i + 1];
            }else if(operators[i] == '-'){
                result -= nums[i + 1];
            }
        }
        
        return result;
    }
};