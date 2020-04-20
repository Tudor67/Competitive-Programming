class Solution {
private:
    vector<int> int_to_digits(int x, int expected_size = 0){
        vector<int> digits;
        while(x > 0){
            digits.push_back(x % 10);
            x /= 10;
        }
        while(digits.size() < expected_size){
            digits.push_back(0);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
    
    int digits_to_int(const vector<int>& digits){
        int x = 0;
        for(int digit: digits){
         x = x * 10 + digit;   
        }
        return x;
    }
    
    bool less_or_equal(const vector<int>& lhs, const vector<int>& rhs){
        for(int i = 0; i < lhs.size(); ++i){
            if(lhs[i] != rhs[i]){
                return lhs[i] <= rhs[i];
            }
        }
        return 1;
    }
    
    void back(int k, vector<int>& st, bool has_zero_prefix, const vector<int>& low_digits, const vector<int>& high_digits, vector<int>& ans){
        if(k == st.size()){
            if(less_or_equal(low_digits, st) && less_or_equal(st, high_digits)){
                ans.push_back(digits_to_int(st));
            }
        }else{
            int start_val;
            int end_val;
            if(k == 0){
                start_val = low_digits[k];
                end_val = high_digits[k];
            }else{
                if(has_zero_prefix){
                    start_val = 0;
                    end_val = 9;
                }else{
                    start_val = st[k - 1] + 1;
                    end_val = min(st[k - 1] + 1, 10 - int(st.size()) + k);
                }
            }
            for(int digit = start_val; digit <= end_val; ++digit){
                st[k] = digit;
                back(k + 1, st, has_zero_prefix && st[k] == 0, low_digits, high_digits, ans);
            }
        }
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> high_digits = int_to_digits(high);
        vector<int> low_digits = int_to_digits(low, high_digits.size());
        int n = high_digits.size();
        vector<int> st(n);
        vector<int> ans;
        back(0, st, 1, low_digits, high_digits, ans);
        return ans;
    }
};