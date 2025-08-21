class Solution {
private:
    bool isPossible(vector<double>& v){
        if((int)v.size() == 1){
            return (abs(v[0] - 24) < 1e-5);
        }

        for(int i = 0; i < (int)v.size(); ++i){
            for(int j = i + 1; j < (int)v.size(); ++j){
                double a = v[i];
                double b = v[j];
                vector<double> nextV = v;
                nextV.erase(nextV.begin() + j);
                nextV.erase(nextV.begin() + i);
                for(double opRes: {a + b, a - b, b - a, a * b, a / b, b / a}){
                    nextV.push_back(opRes);
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