class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> solutions;
        if(n == 0){
            solutions.push_back("");
        }else{
            for(int c = 0; c < n; ++c){
                vector<string> leftSeqAll = generateParenthesis(c);
                for(string leftSeq: leftSeqAll){
                    vector<string> rightSeqAll = generateParenthesis(n - 1 - c);
                    for(string rightSeq: rightSeqAll){
                        solutions.push_back("(" + leftSeq + ")" + rightSeq);
                    }
                }
            }
        }
        return solutions;
    }
};