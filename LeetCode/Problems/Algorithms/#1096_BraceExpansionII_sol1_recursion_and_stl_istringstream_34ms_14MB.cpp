class Solution {
private:
    void generate(string expression, set<string>& res){
        size_t innerPartEnd = expression.find('}');
        if(innerPartEnd == string::npos){
            res.insert(expression);
            return;
        }

        size_t innerPartStart = expression.rfind('{', innerPartEnd);
        string innerPart = expression.substr(innerPartStart + 1, innerPartEnd - innerPartStart - 1);
        istringstream iss(innerPart);
        string s;

        while(getline(iss, s, ',')){
            generate(expression.substr(0, innerPartStart) + s + expression.substr(innerPartEnd + 1), res);
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        set<string> res;
        generate(expression, res);
        return vector<string>(res.begin(), res.end());
    }
};