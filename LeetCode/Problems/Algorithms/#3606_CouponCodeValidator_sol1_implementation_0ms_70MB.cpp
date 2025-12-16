class Solution {
private:
    static bool isValidCode(string& code){
        if(code.empty()){
            return false;
        }
        for(char c: code){
            if(!(isalnum(c) || c == '_')){
                return false;
            }
        }
        return true;
    }

    static bool isValidBusinessLine(string& s){
        return (s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant");
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        const int N = code.size();

        map<string, vector<string>> categoryToValidCodes;
        for(int i = 0; i < N; ++i){
            if(isActive[i] && isValidCode(code[i]) && isValidBusinessLine(businessLine[i])){
                categoryToValidCodes[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> res;
        for(auto [category, validCodes]: categoryToValidCodes){
            sort(validCodes.begin(), validCodes.end());
            copy(validCodes.begin(), validCodes.end(), back_inserter(res));
        }

        return res;
    }
};