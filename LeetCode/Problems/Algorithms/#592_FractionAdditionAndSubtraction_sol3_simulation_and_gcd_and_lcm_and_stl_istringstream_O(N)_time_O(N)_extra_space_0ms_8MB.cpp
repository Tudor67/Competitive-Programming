class Solution {
private:
    using Fraction = pair<int, int>;

    void simplify(Fraction& f){
        int g = gcd(f.first, f.second);
        f.first /= g;
        f.second /= g;
    }

    Fraction nextFraction(istringstream& iss){
        Fraction f;
        char c;
        iss >> f.first >> c >> f.second;
        simplify(f);
        return f;
    }

public:
    string fractionAddition(string s) {
        istringstream iss(s);

        Fraction resFraction = nextFraction(iss);
        while(!iss.eof()){
            Fraction currFraction = nextFraction(iss);
            int commonDenominator = lcm(resFraction.second, currFraction.second);
            resFraction.first = resFraction.first * (commonDenominator / resFraction.second) +
                                currFraction.first * (commonDenominator / currFraction.second);
            resFraction.second = commonDenominator;
            simplify(resFraction);
        }

        return to_string(resFraction.first) + "/" + to_string(resFraction.second);
    }
};