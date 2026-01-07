class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.size());

        int carry = 1;
        for(int i = (int)digits.size() - 1; i >= 0; --i){
            int sum = digits[i] + carry;
            res[i] = sum % 10;
            carry = sum / 10;
        }

        if(carry > 0){
            res.insert(res.begin(), carry);
        }

        return res;
    }
};