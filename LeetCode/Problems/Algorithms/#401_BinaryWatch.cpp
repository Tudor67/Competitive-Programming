class Solution {
private:
    string get_hh_string(const int& hh){
        if(hh <= 9){
            return string(1, char(hh + '0'));
        }
        return string(1, char(hh / 10 + '0')) + string(1, char(hh % 10 + '0'));
    }
    
    string get_mm_string(const int& mm){
        return string(1, char(mm / 10 + '0')) + string(1, char(mm % 10 + '0'));
    }
    
public:
    vector<string> readBinaryWatch(int num) {
        // init
        vector<int> bit_cnt(60, 0);
        for(int i = 1; i < bit_cnt.size(); ++i){
            for(int j = 0; (1 << j) <= i; ++j){
                if(i & (1 << j)){
                    ++bit_cnt[i];
                }
            }
        }
        
        // solve
        vector<string> ans;
        for(int hh = 0; hh <= 11; ++hh){
            for(int mm = 0; mm <= 59; ++mm){
                if(bit_cnt[hh] + bit_cnt[mm] == num){
                    ans.push_back(get_hh_string(hh) + ":" + get_mm_string(mm));
                }
            }
        }
        
        return ans;
    }
};