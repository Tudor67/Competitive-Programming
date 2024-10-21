class Solution {
private:
    bool isOperator(char c){
        return (c == '!' || c == '&' || c == '|');
    }

    int getInitVal(char currOperator){
        if(currOperator == '!' || currOperator == '&'){
            return 1;
        }
        if(currOperator == '|'){
            return 0;
        }
        assert(false);
        return 0;
    }

    int getVal(char c){
        if(c == 'f'){
            return 0;
        }else if(c == 't'){
            return 1;
        }
        assert(false);
        return 1;
    }

    void applyOp(char levelOperator, int& a, int b){
        if(levelOperator == '!'){
            a = !b;
        }else if(levelOperator == '&'){
            a &= b;
        }else if(levelOperator == '|'){
            a |= b;
        }else{
            assert(false);
        }
    }

    int f(string& s, int& i, char levelOperator){
        int res = getInitVal(levelOperator);

        while(i < (int)s.length()){
            if(isOperator(s[i])){
                i += 2;
                applyOp(levelOperator, res, f(s, i, s[i - 2]));
            }else if(s[i] == '('){
                assert(false);
            }else if(s[i] == ','){
                i += 1;
            }else if(s[i] == ')'){
                i += 1;
                break;
            }else{
                i += 1;
                applyOp(levelOperator, res, getVal(s[i - 1]));
            }
        }

        return res;
    }

public:
    bool parseBoolExpr(string s) {
        if((int)s.length() == 1){
            return getVal(s[0]);
        }

        int i = 2;
        return f(s, i, s[0]);
    }
};