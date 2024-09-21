class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for(int i = 0; i < (int)expression.length(); ++i){
            if(!isdigit(expression[i])){
                vector<int> lRes = diffWaysToCompute(expression.substr(0, i));
                vector<int> rRes = diffWaysToCompute(expression.substr(i + 1));
                for(int l: lRes){
                    for(int r: rRes){
                        if(expression[i] == '*'){
                            res.push_back(l * r);
                        }else if(expression[i] == '+'){
                            res.push_back(l + r);
                        }else{
                            res.push_back(l - r);
                        }
                    }
                }
            }
        }

        if(res.empty()){
            res.push_back(stoi(expression));
        }

        return res;
    }
};