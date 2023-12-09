class Solution {
public:
    string largestGoodInteger(string num) {
        const int N = num.length();
        
        string res;
        for(int i = 0; i + 2 < N; ++i){
            string candidate = num.substr(i, 3);
            if(count(candidate.begin(), candidate.end(), candidate[0]) == candidate.length()){
                if(res < candidate){
                    res = candidate;
                }
            }
        }

        return res;
    }
};