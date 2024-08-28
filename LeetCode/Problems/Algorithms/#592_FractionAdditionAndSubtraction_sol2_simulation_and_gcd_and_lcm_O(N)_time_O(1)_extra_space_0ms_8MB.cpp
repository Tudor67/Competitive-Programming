class Solution {
private:
    using Fraction = pair<int, int>;

    int nextNum(const string& S, int& i){
        const int N = S.length();
        int num = 0;
        while(i < N && isdigit(S[i])){
            num = num * 10 + (S[i] - '0');
            i += 1;
        }
        return num;
    }

    Fraction nextFraction(const string& S, int& i){
        const int N = S.length();

        int sign = 1;
        if(S[i] == '-'){
            sign = -1;
            i += 1;
        }else if(S[i] == '+'){
            sign = 1;
            i += 1;
        }

        int numerator = nextNum(S, i);
        i += 1;
        int denominator = nextNum(S, i);
        
        int g = gcd(numerator, denominator);
        return {sign * numerator / g, denominator / g};
    }

public:
    string fractionAddition(string s) {
        const int N = s.length();

        int denominator = 1;
        int i = 0;
        while(i < N){
            Fraction f = nextFraction(s, i);
            denominator = lcm(denominator, f.second);
        }

        int numerator = 0;
        i = 0;
        while(i < N){
            Fraction f = nextFraction(s, i);
            numerator += f.first * (denominator / f.second);
        }

        int g = gcd(numerator, denominator);
        return to_string(numerator / g) + "/" + to_string(denominator / g);
    }
};