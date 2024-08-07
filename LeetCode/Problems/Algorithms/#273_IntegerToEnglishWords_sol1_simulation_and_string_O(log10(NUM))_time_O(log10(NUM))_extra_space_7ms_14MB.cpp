class Solution {
private:
    vector<string> BLOCK_NAMES = {"Billion", "Million", "Thousand", ""};
    map<char, string> UNIT_NAMES = {{'1', "One"}, {'2', "Two"}, {'3', "Three"}, {'4', "Four"},
                                    {'5', "Five"}, {'6', "Six"}, {'7', "Seven"}, {'8', "Eight"},
                                    {'9', "Nine"}};

    map<char, string> TEN_NAMES = {{'2', "Twenty"}, {'3', "Thirty"}, {'4', "Forty"},
                                   {'5', "Fifty"}, {'6', "Sixty"}, {'7', "Seventy"}, {'8', "Eighty"},
                                   {'9', "Ninety"}};

    map<string, string> SPECIAL_TEN_NAMES = {{"10", "Ten"}, {"11", "Eleven"}, {"12", "Twelve"},
                                             {"13", "Thirteen"}, {"14", "Fourteen"}, {"15", "Fifteen"},
                                             {"16", "Sixteen"}, {"17", "Seventeen"}, {"18", "Eighteen"},
                                             {"19", "Nineteen"}};

    void joinStr(string& res, const string& S){
        if(S.empty() || S == " "){
            return;
        }
        if(!res.empty() && res.back() != ' '){
            res += " ";
        }
        res += S;
    }

    string blockStrToWords(const string S){
        const int LEN = S.length();
        
        string words;
        if(LEN == 1){
            joinStr(words, UNIT_NAMES[S[0]]);
        }else if(LEN == 3 && S[0] >= '1'){
            joinStr(words, UNIT_NAMES[S[0]]);
            joinStr(words, "Hundred");
        }

        if(LEN >= 2){
            string suffix = S.substr(LEN - 2);
            if(suffix == "00"){
                // ignore
            }else if(suffix[0] == '0'){
                joinStr(words, UNIT_NAMES[suffix[1]]);
            }else if(suffix[0] == '1'){
                joinStr(words, SPECIAL_TEN_NAMES[suffix]);
            }else{
                joinStr(words, TEN_NAMES[suffix[0]]);
                joinStr(words, UNIT_NAMES[suffix[1]]);
            }
        }

        return words;
    }

public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }

        string numStr = to_string(num);
        int numLen = numStr.length();

        string res;
        int i = 0;
        int j = (numLen - 1) % 3;
        int blockIndex = (int)BLOCK_NAMES.size() - 1 - (numLen - 1) / 3;
        while(i < numLen){
            joinStr(res, blockStrToWords(numStr.substr(i, j - i + 1)));
            if(stoi(numStr.substr(i, j - i + 1)) != 0){
                joinStr(res, BLOCK_NAMES[blockIndex]);
            }
            blockIndex += 1;
            i = j + 1;
            j = j + 3;
        }

        return res;
    }
};