class Solution {
private:
    using ll = long long;
    
    void back(const string& NUM_STR, const int& TARGET_SUM, int startIdx,  ll prevTerm, ll currentSum,
              vector<ll>& numStack, string& operatorStack, vector<string>& expressions){
        if(startIdx == (int)NUM_STR.length()){
            if(currentSum == TARGET_SUM){
                expressions.push_back(to_string(numStack[0]));
                for(int i = 0; i < (int)operatorStack.length(); ++i){
                    expressions.back() += operatorStack[i];
                    expressions.back() += to_string(numStack[i + 1]);
                }
            }
        }else{
            ll num = 0;
            for(int i = startIdx; i < (int)NUM_STR.length(); ++i){
                num = num * 10 + (NUM_STR[i]- '0');
                if(NUM_STR[startIdx] == '0' && i > startIdx){
                    return;
                }
                
                if(numStack.empty()){
                    numStack.push_back(num);
                    back(NUM_STR, TARGET_SUM, i + 1, num, num, numStack, operatorStack, expressions);
                    numStack.pop_back();
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
                        numStack.push_back(num);
                        operatorStack.push_back(currentOperator);
                        back(NUM_STR, TARGET_SUM, i + 1, nextPrevTerm, nextSum, numStack, operatorStack, expressions);
                        numStack.pop_back();
                        operatorStack.pop_back();
                    }
                }
            }
        }
    }
    
public:
    vector<string> addOperators(string numStr, int target) {
        const int N = numStr.length();
        vector<ll> numStack;
        string operatorStack;
        vector<string> expressions;
        back(numStr, target, 0, 0, 0, numStack, operatorStack, expressions);
        return expressions;
    }
};