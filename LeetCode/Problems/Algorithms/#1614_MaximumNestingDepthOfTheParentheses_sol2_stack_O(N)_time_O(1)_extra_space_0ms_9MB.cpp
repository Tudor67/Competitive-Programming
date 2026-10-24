class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int currDepth = 0;
        
        for(char c: s){
            if(c == '('){
                currDepth += 1;
            }else if(c == ')'){
                currDepth -= 1;
            }
            res = max(res, currDepth);
        }

        return res;
    }
};