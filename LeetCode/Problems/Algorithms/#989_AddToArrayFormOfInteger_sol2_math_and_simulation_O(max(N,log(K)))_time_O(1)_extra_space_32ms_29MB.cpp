class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;

        int carry = k;
        int i = (int)num.size() - 1;
        while(i >= 0 || carry >= 1){
            int sum = carry;
            if(i >= 0){
                sum += num[i];
            }

            res.push_back(sum % 10);
            carry = sum / 10;
            i -= 1;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};