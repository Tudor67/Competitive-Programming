class Solution {
private:
    long long eval(const vector<long long>& NUMS, const string& OPERATORS){
        static vector<long long> newNums;
        static string newOperators;
        newNums.clear();
        newOperators.clear();
        
        newNums.push_back(NUMS[0]);
        for(int i = 1; i < (int)NUMS.size(); ++i){
            if(OPERATORS[i - 1] == '*'){
                newNums.back() *= NUMS[i];
            }else{
                newOperators += OPERATORS[i - 1];
                newNums.push_back(NUMS[i]);
            }
        }
        
        long long answer = newNums[0];
        for(int i = 1; i < (int)newNums.size(); ++i){
            if(newOperators[i - 1] == '+'){
                answer += newNums[i];
            }else{
                answer -= newNums[i];
            }
        }
        
        return answer;
    }
    
    void back(int level, vector<long long>& numStack, string& operatorStack,
              const string& NUM, const int& TARGET, vector<string>& expressions,
              const vector<vector<long long>>& STR_TO_NUM){
        const int N = NUM.length();
        if(level == N){
            if(eval(numStack, operatorStack) == (long long)TARGET){
                string expression = to_string(numStack[0]);
                for(int i = 1; i < (int)numStack.size(); ++i){
                    expression += operatorStack[i - 1];
                    expression += to_string(numStack[i]);
                }
                expressions.push_back(expression);
            }
        }else{
            for(int i = level; i < N; ++i){
                int len = i - level + 1;
                long long num = STR_TO_NUM[level][len];
                if(NUM[level] == '0' && len >= 2){
                    continue;
                }
                numStack.push_back(num);
                if(i == N - 1){
                    back(i + 1, numStack, operatorStack, NUM, TARGET, expressions, STR_TO_NUM);
                }else{
                    for(char currentOperator: {'+', '-', '*'}){
                        operatorStack.push_back(currentOperator);
                        back(level + len, numStack, operatorStack, NUM, TARGET, expressions, STR_TO_NUM);
                        operatorStack.pop_back();
                    }
                }
                numStack.pop_back();
            }
        }
    }
    
public:
    vector<string> addOperators(string num, int target) {
        const int N = num.length();
        
        vector<vector<long long>> strToNum(N + 1, vector<long long>(N + 1, 0));
        long long val = 0;
        for(int startPos = 0; startPos < N; ++startPos){
            val = 0;
            for(int len = 1; startPos + len - 1 < N; ++len){
                val = val * 10 + (num[startPos + len - 1] - '0');
                strToNum[startPos][len] = val;
            }            
        }
        
        vector<long long> numStack;
        string operatorStack;
        vector<string> expressions;
        back(0, numStack, operatorStack, num, target, expressions, strToNum);
        
        return expressions;
    }
};