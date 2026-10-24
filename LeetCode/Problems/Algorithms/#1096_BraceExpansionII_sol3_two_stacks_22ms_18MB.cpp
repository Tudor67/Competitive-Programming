class Solution {
private:
    const char PRODUCT = '*';
    const char UNION = ',';
    const char OPEN_BRACE = '{';
    const char CLOSE_BRACE = '}';

    void applyTopOperator(stack<char>& operatorsSt, stack<set<string>>& operandsSt){
        char currOperator = operatorsSt.top();
        operatorsSt.pop();

        set<string> set2 = operandsSt.top(); operandsSt.pop();
        set<string> set1 = operandsSt.top(); operandsSt.pop();
        operandsSt.push(set<string>{});

        if(currOperator == PRODUCT){
            productUpdate(set1, set2, operandsSt.top());
        }else{
            unionUpdate(set1, set2, operandsSt.top());
        }
    }

    void productUpdate(set<string>& set1, set<string>& set2, set<string>& res){
        res.clear();
        for(const string& e1: set1){
            for(const string& e2: set2){
                res.insert(e1 + e2);
            }
        }
    }

    void unionUpdate(set<string>& set1, set<string>& set2, set<string>& res){
        res.clear();
        res.insert(set1.begin(), set1.end());
        res.insert(set2.begin(), set2.end());
    }

public:
    vector<string> braceExpansionII(string inExpression) {
        string expression;
        expression += inExpression[0];

        for(int i = 1; i < (int)inExpression.length(); ++i){
            if((inExpression[i - 1] == '}' || isalpha(inExpression[i - 1])) &&
               (inExpression[i] == '{' || isalpha(inExpression[i]))){
                expression += PRODUCT;
            }
            expression += inExpression[i];
        }

        expression = "{" + expression + "}";

        stack<char> operatorsSt;
        stack<set<string>> operandsSt;
        for(char c: expression){
            if(c == OPEN_BRACE){
                operatorsSt.push(OPEN_BRACE);
            }else if(c == CLOSE_BRACE){
                while(operatorsSt.top() != OPEN_BRACE){
                    applyTopOperator(operatorsSt, operandsSt);
                }
                operatorsSt.pop();
            }else if(c == PRODUCT){
                operatorsSt.push(PRODUCT);
            }else if(c == UNION){
                while(!operatorsSt.empty() && operatorsSt.top() == PRODUCT){
                    applyTopOperator(operatorsSt, operandsSt);
                }
                operatorsSt.push(UNION);
            }else{
                operandsSt.push(set<string>{string(1, c)});
            }
        }

        return vector<string>(operandsSt.top().begin(), operandsSt.top().end());
    }
};