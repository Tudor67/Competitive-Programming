class Solution {
private:
    void back(string& xStr, string& nStr, bool equalPrefix, int& count){
        if(xStr.length() == nStr.length()){
            count += 1;
        }else{
            string validDigits = "0";
            if(!equalPrefix || nStr[xStr.size()] == '1'){
                if(xStr.empty() || xStr.back() != '1'){
                    validDigits = "01";
                }
            }
            for(char validDigit: validDigits){
                xStr.push_back(validDigit);
                back(xStr, nStr, (equalPrefix && xStr.back() == nStr[(int)xStr.size() - 1]), count);
                xStr.pop_back();
            }
        }
    }
    
public:
    int findIntegers(int n) {
        string xStr;
        string nStr = bitset<30>(n).to_string();
        int count = 0;
        back(xStr, nStr, true, count);
        return count;
    }
};