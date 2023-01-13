class Solution {
private:
    int computeMinCost(int a, char currentOperator, int b, int aMinCost, int bMinCost){
        if(a != b){
            return 1;
        }
        if((a == 1 && currentOperator == '&' && b == 1) ||
           (a == 0 && currentOperator == '|' && b == 0)){
            return min(aMinCost, bMinCost);
        }
        return 1 + min(aMinCost, bMinCost);
    }

    int f(int a, char currentOperator, int b){
        if(currentOperator == '&'){
            return (a & b);
        }
        return (a | b);
    }

public:
    int minOperationsToFlip(string s) {
        const int N = s.length();
        const char EMPTY_OPERATOR = '#';

        stack<char> operatorSt;
        stack<int> factorSt;
        stack<int> minCostSt;
        operatorSt.push(EMPTY_OPERATOR);
        factorSt.push(0);
        minCostSt.push(0);

        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                factorSt.push(0);
                minCostSt.push(0);
                if(i >= 1 && s[i - 1] == '('){
                    operatorSt.push(EMPTY_OPERATOR);
                }
            }else if(s[i] == ')'){
                if(operatorSt.top() == EMPTY_OPERATOR){
                    int a = factorSt.top(); factorSt.pop();
                    int aMinCost = minCostSt.top(); minCostSt.pop();
                    factorSt.top() = a;
                    minCostSt.top() = aMinCost;
                }else{
                    int a = factorSt.top(); factorSt.pop();
                    int b = factorSt.top(); factorSt.pop();
                    int aMinCost = minCostSt.top(); minCostSt.pop();
                    int bMinCost = minCostSt.top(); minCostSt.pop();
                    factorSt.push(f(a, operatorSt.top(), b));
                    minCostSt.push(computeMinCost(a, operatorSt.top(), b, aMinCost, bMinCost));
                }
                operatorSt.pop();
            }else if(isdigit(s[i])){
                if(i == 0 || s[i - 1] == '('){
                    factorSt.top() = (s[i] - '0');
                    minCostSt.top() = 1;
                }else{
                    int a = factorSt.top(); factorSt.pop();
                    int b = (s[i] - '0');
                    int aMinCost = minCostSt.top(); minCostSt.pop();
                    int bMinCost = 1;
                    factorSt.push(f(a, operatorSt.top(), b));
                    minCostSt.push(computeMinCost(a, operatorSt.top(), b, aMinCost, bMinCost));
                    operatorSt.pop();
                }
            }else{
                operatorSt.push(s[i]);
            }
        }

        return minCostSt.top();
    }
};