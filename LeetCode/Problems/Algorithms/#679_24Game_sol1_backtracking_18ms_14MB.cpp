class Solution {
private:
    unordered_map<char, function<double(double, double)>> f = {
        {'+', [](double a, double b) -> double { return a + b; }},
        {'-', [](double a, double b) -> double { return a - b; }},
        {'*', [](double a, double b) -> double { return a * b; }},
        {'/', [](double a, double b) -> double { return a / b; }}
    };

    bool isPossible(vector<double>& v){
        if((int)v.size() == 1){
            return (abs(v[0] - 24) < 1e-5);
        }

        for(int i = 0; i < (int)v.size(); ++i){
            for(int j = 0; j < (int)v.size(); ++j){
                if(i == j){
                    continue;
                }
                double a = v[i];
                double b = v[j];
                vector<double> nextV = v;
                nextV.erase(nextV.begin() + max(i, j));
                nextV.erase(nextV.begin() + min(i, j));
                for(char operation: {'+', '-', '*', '/'}){
                    nextV.push_back(f[operation](a, b));
                    if(isPossible(nextV)){
                        return true;
                    }
                    nextV.pop_back();
                }
            }
        }

        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> v(cards.size());
        for(int i = 0; i < (int)v.size(); ++i){
            v[i] = cards[i];
        }
        return isPossible(v);
    }
};