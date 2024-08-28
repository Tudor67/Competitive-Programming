class Solution {
public:
    string fractionAddition(string s) {
        const int N = s.length();

        vector<char> signs;
        vector<int> nums;
        
        int num = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '-' || s[i] == '+'){
                signs.push_back(s[i]);
            }else if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }
            if(isdigit(s[i]) && (i + 1 == N || !isdigit(s[i + 1]))){
                nums.push_back(num);
                num = 0;
            }
        }

        if(signs.size() < nums.size() / 2){
            signs.insert(signs.begin(), '+');
        }

        int denominator = 1;
        for(int i = (int)nums.size() - 1; i >= 1; i -= 2){
            denominator = lcm(denominator, nums[i]);
        }

        int numerator = 0;
        for(int i = 0; i < (int)nums.size(); i += 2){
            int num = nums[i] * (denominator / nums[i + 1]);
            if(signs[i / 2] == '-'){
                num = -num;
            }
            numerator += num;
        }

        int g = gcd(numerator, denominator);
        return to_string(numerator / g) + "/" + to_string(denominator / g);
    }
};