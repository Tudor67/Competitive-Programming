class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(count(digits.begin(), digits.end(), 9) == (int)digits.size()){
            vector<int> res(digits.size() + 1);
            res[0] = 1;
            return res;
        }

        int carry = 1;
        vector<int> res(digits.size());
        for(int i = (int)digits.size() - 1; i >= 0; --i){
            int sum = digits[i] + carry;
            res[i] = sum % 10;
            carry = sum / 10;
        }

        return res;
    }
};