class Solution {
private:
    vector<int> v;

    void generateSeqDigits(){
        if(!v.empty()){
            return;
        }

        for(int startDigit = 1; startDigit <= 9; ++startDigit){
            v.push_back(startDigit);
        }

        int startIndex = 0;
        for(int len = 2; len <= 9; ++len){
            int prevSize = v.size();
            for(int i = startIndex; i < prevSize; ++i){
                int lastDigit = v[i] % 10;
                if(lastDigit < 9){
                    v.push_back(v[i] * 10 + lastDigit + 1);
                }
            }
            startIndex = prevSize;
        }
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        generateSeqDigits();

        auto itStart = lower_bound(v.begin(), v.end(), low);
        auto itEnd = upper_bound(itStart, v.end(), high);

        return vector<int>(itStart, itEnd);
    }
};