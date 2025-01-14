class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int N = s.length();

        if(N % 2 == 1){
            return false;
        }

        stack<int> stOpen;
        stack<int> stAny;
        for(int i = 0; i < N; ++i){
            if(locked[i] == '1'){
                if(s[i] == '('){
                    stOpen.push(i);
                }else if(!stOpen.empty()){
                    stOpen.pop();
                }else if(!stAny.empty()){
                    stAny.pop();
                }else{
                    return false;
                }
            }else{
                stAny.push(i);
            }
        }
        
        while(!stOpen.empty() && !stAny.empty() && stOpen.top() < stAny.top()){
            stOpen.pop();
            stAny.pop();
        }

        return stOpen.empty();
    }
};