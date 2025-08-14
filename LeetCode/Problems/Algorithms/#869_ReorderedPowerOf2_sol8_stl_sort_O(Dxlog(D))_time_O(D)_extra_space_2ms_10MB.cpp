class Solution {
private:
    string sortDigits(int num){
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }

public:
    bool reorderedPowerOf2(int n) {
        string s = sortDigits(n);

        for(int i = 1; i < 1'000'000'000; i *= 2){
            if(s == sortDigits(i)){
                return true;
            }
        }

        return false;
    }
};