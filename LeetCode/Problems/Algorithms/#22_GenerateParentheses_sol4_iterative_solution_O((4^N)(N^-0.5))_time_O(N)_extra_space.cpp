class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> parentheses(n + 1);
        parentheses[0] = {""};
        for(int k = 1; k <= n; ++k){
            for(int i = 0; i <= k - 1; ++i){
                for(const string& LEFT: parentheses[i]){
                    for(const string& RIGHT: parentheses[k - 1 - i]){
                        parentheses[k].push_back(LEFT + "(" + RIGHT + ")");
                    }
                }
            }
        }
        return parentheses[n];
    }
};