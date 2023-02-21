class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;

        int carry = 0;
        int i = (int)num.size() - 1;
        while(i >= 0 || carry >= 1 || k >= 1){
            int sum = (k % 10) + carry;
            if(i >= 0){
                sum += num[i];
            }

            res.push_back(sum % 10);
            carry = sum / 10;
            
            k /= 10;
            i -= 1;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};