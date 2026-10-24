class Solution {
private:
    void generate(string expression, set<string>& res){
        size_t innerPartEnd = expression.find('}');
        if(innerPartEnd == string::npos){
            res.insert(expression);
            return;
        }
        size_t innerPartStart = expression.rfind('{', innerPartEnd);
        for(int i = innerPartStart + 1, j = innerPartStart + 1; j <= innerPartEnd; ++j){
            if(expression[j] == ',' || expression[j] == '}'){
                generate(expression.substr(0, innerPartStart) +
                         expression.substr(i, j - i) +
                         expression.substr(innerPartEnd + 1), res);
                i = j + 1;
            }
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        set<string> res;
        generate(expression, res);
        return vector<string>(res.begin(), res.end());
    }
};