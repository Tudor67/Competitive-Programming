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
        // split into nums and operators vectors
        const int N = s.length();
        vector<int> nums;
        vector<char> operators;
        int num = 0;
        for(int i = 0; i < N; ++i){
            if(isdigit(s[i])){
                num = 10 * num + (s[i] - '0');
            }
            if(!isdigit(s[i]) || i == N - 1){
                nums.push_back(num);
                num = 0;
            }
            if(!isdigit(s[i])){
                operators.push_back(s[i]);
            }
        }
        
        // '*' and '/' operators
        const int T = operators.size();
        for(int i = 0; i < T; ++i){
            char c = operators[i];
            if(c == '*'){
                nums[i + 1] = nums[i] * nums[i + 1];
            }else if(c == '/'){
                nums[i + 1] = nums[i] / nums[i + 1];
            }
        }
        
        for(int i = T - 1; i >= 0; --i){
            char c = operators[i];
            if(c == '*' || c == '/'){
                nums[i] = nums[i + 1];
            }
        }
        
        // '+' and '-' operators
        int result = nums[0];
        for(int i = 0; i < T; ++i){
            char c = operators[i];
            if(c == '+'){
                result += nums[i + 1];
            }else if(c == '-'){
                result -= nums[i + 1];
            }
        }
        
        return result;
    }
};