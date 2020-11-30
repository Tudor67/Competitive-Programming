class Solution {
public:
    int calculate(string s) {
        int num = 0;
        vector<int> nums;
        vector<char> ops;
        for(int i = 0; i < s.length(); ++i){
            if(isdigit(s[i])){
                num = 10 * num + (s[i] - '0');
            }else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                nums.push_back(num);
                ops.push_back(s[i]);
                num = 0;
            }
        }
        
        nums.push_back(num);
        
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i] == '*'){
                nums[i + 1] = nums[i] * nums[i + 1];
            }else if(ops[i] == '/'){
                nums[i + 1] = nums[i] / nums[i + 1];
            }
            if(ops[i] == '+' || ops[i] == '-' || i == (int)ops.size() - 1){
                int numPos = (ops[i] == '+' || ops[i] == '-' ? i : i + 1);
                int opPos = (ops[i] == '+' || ops[i] == '-' ? i - 1 : i);
                for(int k = opPos; k >= 0 && (ops[k] == '*' || ops[k] == '/'); --k){
                    nums[k] = nums[numPos];
                }
            }
        }
        
        int answer = nums[0];
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i] == '+'){
                answer += nums[i + 1];
            }else if(ops[i] == '-'){
                answer -= nums[i + 1];
            }
        }
        
        return answer;
    }
};