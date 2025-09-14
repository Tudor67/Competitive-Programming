class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a <= n - 1; ++a){
            int b = n - a;
            string aStr = to_string(a);
            string bStr = to_string(b);
            if(aStr.find('0') == string::npos && bStr.find('0') == string::npos){
                return {a, b};
            }
        }
        return {0, 0};
    }
};