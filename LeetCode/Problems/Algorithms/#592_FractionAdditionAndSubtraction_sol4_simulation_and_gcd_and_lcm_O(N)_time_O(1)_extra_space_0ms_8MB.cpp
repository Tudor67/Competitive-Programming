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

    void simplify(Fraction& f){
        int g = gcd(f.first, f.second);
        f.first /= g;
        f.second /= g;
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

        Fraction f;
        f.first = nextNum(S, i);
        i += 1;
        f.second = nextNum(S, i);

        f.first *= sign;
        simplify(f);

        return f;
    }

public:
    string fractionAddition(string s) {
        const int N = s.length();

        int i = 0;
        Fraction resFraction = nextFraction(s, i);
        while(i < N){
            Fraction currFraction = nextFraction(s, i);
            int commonDenominator = lcm(resFraction.second, currFraction.second);
            resFraction.first = resFraction.first * (commonDenominator / resFraction.second) +
                                currFraction.first * (commonDenominator / currFraction.second);
            resFraction.second = commonDenominator;
            simplify(resFraction);
        }

        return to_string(resFraction.first) + "/" + to_string(resFraction.second);
    }
};