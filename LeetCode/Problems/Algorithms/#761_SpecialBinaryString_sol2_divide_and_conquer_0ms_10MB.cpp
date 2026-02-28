class Solution {
public:
    string makeLargestSpecial(string s) {
        const int N = s.length();

        int balance = 0;
        int startIndex = 0;
        vector<string> v;

        for(int i = 0; i < N; ++i){
            if(s[i] == '0'){
                balance -= 1;
            }else{
                balance += 1;
            }

            if(balance == 0){
                v.push_back("1" + makeLargestSpecial(s.substr(startIndex + 1, i - startIndex - 1)) + "0");
                startIndex = i + 1;
            }
        }

        sort(v.rbegin(), v.rend());

        string res;
        res.reserve(N);
        for(string& ss: v){
            res += ss;
        }

        return res;
    }
};