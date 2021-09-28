class Solution {
private:
    using ll = long long;
    
    void back(const string& NUM_STR, const int& TARGET_SUM, int startIdx,  ll prevTerm, ll currentSum,
              string& currentExpression, vector<string>& expressions){
        if(startIdx == (int)NUM_STR.length()){
            if(currentSum == TARGET_SUM){
                expressions.push_back(currentExpression);
            }
        }else{
            ll num = 0;
            for(int i = startIdx; i < (int)NUM_STR.length(); ++i){
                num = num * 10 + (NUM_STR[i]- '0');
                if(NUM_STR[startIdx] == '0' && i > startIdx){
                    return;
                }
                
                if(currentExpression.empty()){
                    currentExpression += to_string(num);
                    back(NUM_STR, TARGET_SUM, i + 1, num, num, currentExpression, expressions);
                    currentExpression.clear();
                }else{
                    for(char currentOperator: {'+', '-', '*'}){
                        ll nextPrevTerm = 0;
                        ll nextSum = 0;
                        if(currentOperator == '+'){
                            nextPrevTerm = num;
                            nextSum = currentSum + num;
                        }else if(currentOperator == '-'){
                            nextPrevTerm = -num;
                            nextSum = currentSum - num;
                        }else if(currentOperator == '*'){
                            nextPrevTerm = prevTerm * num;
                            nextSum = currentSum + prevTerm * num - prevTerm;
                        }
                        const int EXPRESSION_LENGTH = currentExpression.length();
                        currentExpression += currentOperator;
                        currentExpression += to_string(num);
                        back(NUM_STR, TARGET_SUM, i + 1, nextPrevTerm, nextSum, currentExpression, expressions);
                        currentExpression.resize(EXPRESSION_LENGTH);
                    }
                }
            }
        }
    }
    
public:
    vector<string> addOperators(string numStr, int target) {
        const int N = numStr.length();
        string currentExpression;
        vector<string> expressions;
        back(numStr, target, 0, 0, 0, currentExpression, expressions);
        return expressions;
    }
};