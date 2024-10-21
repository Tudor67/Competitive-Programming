class Solution {
private:
    bool isOperator(char c){
        return (c == '!' || c == '&' || c == '|');
    }

    int getInitVal(char levelOperator){
        return (levelOperator == '&');
    }

    int getVal(char c){
        return (c == 't');
    }

    void applyOp(char levelOperator, int& a, int b){
        if(levelOperator == '!'){
            a = !b;
        }else if(levelOperator == '&'){
            a &= b;
        }else if(levelOperator == '|'){
            a |= b;
        }
    }

    int f(string& s, int& i, char levelOperator){
        int res = getInitVal(levelOperator);

        while(i < (int)s.length()){
            if(isOperator(s[i])){
                i += 2;
                applyOp(levelOperator, res, f(s, i, s[i - 2]));
            }else if(s[i] == 'f' || s[i] == 't'){
                i += 1;
                applyOp(levelOperator, res, getVal(s[i - 1]));
            }else if(s[i] == ','){
                i += 1;
            }else if(s[i] == ')'){
                i += 1;
                break;
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