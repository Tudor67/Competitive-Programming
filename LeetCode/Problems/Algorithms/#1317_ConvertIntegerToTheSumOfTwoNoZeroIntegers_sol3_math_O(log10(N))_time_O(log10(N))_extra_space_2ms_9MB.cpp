class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        string nStr = to_string(n);
        string aStr = nStr;

        int carry = 0;
        for(int i = (int)nStr.length() - 1; i >= 0; --i){
            int targetDigit = nStr[i] - '0' - carry;
            if(targetDigit <= 1){
                aStr[i] = '5';
                carry = 1;
            }else{
                aStr[i] = char(targetDigit / 2 + '0');
                carry = 0;
            }
        }

        if(aStr > nStr){
            aStr[0] = '0';
        }

        int a = stoi(aStr);
        int b = n - a;

        return {a, b};
    }
};