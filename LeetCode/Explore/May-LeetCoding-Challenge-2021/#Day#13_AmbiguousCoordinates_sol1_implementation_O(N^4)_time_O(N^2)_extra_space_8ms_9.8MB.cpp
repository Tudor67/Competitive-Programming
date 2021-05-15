class Solution {
private:
    vector<string> generateValidStrings(string s){
        const int N = s.length();
        vector<string> validStrings;
        if(s[0] == '0'){
            if(N == 1){
                validStrings = {"0"};
            }else if(s.back() >= '1'){
                validStrings.push_back(string(1, '0') + "." + s.substr(1));
            }
        }else{
            validStrings.push_back(s);
            for(int i = 1; i <= N - 1; ++i){
                if(s.back() >= '1'){
                    validStrings.push_back(s.substr(0, i) + "." + s.substr(i));
                }
            }
        }
        return validStrings;
    }
    
public:
    vector<string> ambiguousCoordinates(string s) {
        const int N = s.length();
        vector<string> answer;
        for(int commaPos = 2; commaPos <= N - 2; ++commaPos){
            vector<string> leftStrings = generateValidStrings(s.substr(1, commaPos - 1));
            vector<string> rightStrings = generateValidStrings(s.substr(commaPos, N - commaPos - 1));
            for(const string& LEFT_STRING: leftStrings){
                for(const string& RIGHT_STRING: rightStrings){
                    answer.push_back("(" + LEFT_STRING + ", " + RIGHT_STRING + ")");
                }
            }
        }
        return answer;
    }
};