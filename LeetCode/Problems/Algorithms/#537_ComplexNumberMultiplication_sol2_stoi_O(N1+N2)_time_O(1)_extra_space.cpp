class Solution {
private:
    int stoi(const string& S, const int& START_POS = 0){
        int num = 0;
        for(int i = START_POS + (!isdigit(S[START_POS])); i < (int)S.length() && isdigit(S[i]); ++i){
            num = 10 * num + (S[i] - '0');
        }
        if(S[START_POS] == '-'){
            num *= -1;
        }
        return num;
    }
    
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1 = stoi(num1);
        int i1 = stoi(num1, num1.find('+') + 1);
        int r2 = stoi(num2);
        int i2 = stoi(num2, num2.find('+') + 1);
        int r3 = r1 * r2 - i1 * i2;
        int i3 = r1 * i2 + r2 * i1;
        return to_string(r3) + "+" + to_string(i3) + "i";
    }
};