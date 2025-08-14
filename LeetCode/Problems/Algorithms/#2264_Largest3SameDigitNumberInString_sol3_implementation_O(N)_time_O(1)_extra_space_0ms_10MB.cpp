class Solution {
public:
    string largestGoodInteger(string num) {
        const int N = num.length();

        string res;
        for(int i = 0; i + 2 < N; ++i){
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2]){
                res = max(res, num.substr(i, 3));
            }
        }

        return res;
    }
};