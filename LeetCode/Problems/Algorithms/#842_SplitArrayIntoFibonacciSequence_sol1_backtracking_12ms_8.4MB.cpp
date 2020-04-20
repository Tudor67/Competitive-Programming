class Solution {
private:
    vector<int> get_sum(vector<int>& a, vector<int>& b){
        vector<int> sum;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int carry = 0;
        for(int i = 0; i < max(a.size(), b.size()); ++i){
            int cur_a = (i < a.size() ? a[i] : 0);
            int cur_b = (i < b.size() ? b[i] : 0);
            int cur_sum = (carry + cur_a + cur_b);
            sum.push_back(cur_sum % 10);
            carry = cur_sum / 10;
        }
        
        if(carry > 0){
            sum.push_back(carry);
        }
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
    
    int vector_to_int(const vector<int>& digits){
        int num = 0;
        for(int digit: digits){
            num = num * 10 + digit;
        }
        return num;
    }
    
    bool match(const vector<int>& lhs, const vector<int>& rhs, const int& rhs_start_idx){
        bool ok = rhs_start_idx + int(lhs.size()) - 1 <= int(rhs.size()) - 1;        
        if(ok){
            for(int i = 0; i < lhs.size(); ++i){
                ok = ok & (lhs[i] == rhs[i + rhs_start_idx]);
            }
        }
        return ok;
    }
    
    bool is_32_bit_int(const vector<int>& v){
        static const vector<int> max_32_bit_int = {2,1,4,7,4,8,3,6,4,7};
        if(v.size() == max_32_bit_int.size()){
            return v <= max_32_bit_int;
        }
        return v.size() < max_32_bit_int.size();
    }
    
    bool has_leading_zeros(const vector<int>& v){
        return (v.size() > 1 && v[0] == 0);
    }
    
    void back(int k, vector<int>& st, const vector<int>& seq, vector<int>& ans){
        if(ans.empty()){
            if(st[k - 1] == seq.size()){
                // save ans
                if(k - 1 >= 3){
                    for(int i = 1; i <= k - 1; ++i){
                        ans.push_back(vector_to_int(vector<int>{seq.begin() + st[i - 1], seq.begin() + st[i]}));
                    }
                }
            }else{
                // search ans
                if(k <= 2){
                    for(int i = st[k - 1] + 1; i <= min(st[k - 1] + 10, int(seq.size()) - 1); ++i){
                        st[k] = i;
                        vector<int> cur_num(seq.begin() + st[k - 1], seq.begin() + st[k]);
                        if(is_32_bit_int(cur_num) && !has_leading_zeros(cur_num)){
                            back(k + 1, st, seq, ans);
                        }
                    }
                }else{
                    vector<int> a(seq.begin() + st[k - 3], seq.begin() + st[k - 2]);
                    vector<int> b(seq.begin() + st[k - 2], seq.begin() + st[k - 1]);
                    vector<int> c(get_sum(a, b));
                    
                    if(match(c, seq, st[k - 1]) && is_32_bit_int(c)){
                        st[k] = st[k - 1] + c.size();
                        back(k + 1, st, seq, ans);
                    }
                }
            }
        }
    }
    
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        
        if(S.length() >= 3){
            vector<int> seq(S.length());
            for(int i = 0; i < seq.size(); ++i){
                seq[i] = S[i] - '0';
            }
            
            vector<int> st(seq.size() + 1, 0);
            back(1, st, seq, ans);
        }
        
        return ans;
    }
};