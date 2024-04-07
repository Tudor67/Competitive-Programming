class Solution {
public:
    int maxDepth(string s) {
        const int N = s.length();

        int vpsMaxDepth = 0;
        int vpsDepth = 0;
        for(char c: s){
            if(c == '('){
                vpsDepth += 1;
                vpsMaxDepth = max(vpsMaxDepth, vpsDepth);
            }else if(c == ')'){
                vpsDepth -= 1;
            }
        }

        return vpsMaxDepth;
    }
};