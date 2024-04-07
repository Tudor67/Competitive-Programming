class Solution {
public:
    bool checkValidString(string s) {
        const int N = s.length();

        stack<int> openParSt;
        stack<int> wildcardsSt;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                openParSt.push(i);
            }else if(s[i] == '*'){
                wildcardsSt.push(i);
            }else{
                if(!openParSt.empty()){
                    openParSt.pop();
                }else if(!wildcardsSt.empty()){
                    wildcardsSt.pop();
                }else{
                    return false;
                }
            }
        }

        while(!openParSt.empty() && !wildcardsSt.empty()){
            if(openParSt.top() > wildcardsSt.top()){
                return false;
            }
            openParSt.pop();
            wildcardsSt.pop();
        }

        return openParSt.empty();
    }
};