class Solution {
private:
    const int N;
    vector<int> blacklist;
    map<int, int> next_valid_num;
    
public:
    Solution(int N, vector<int>& blacklist_in): N(N) {
        if(!blacklist_in.empty()){
            blacklist = blacklist_in;
            sort(blacklist.begin(), blacklist.end());

            next_valid_num[blacklist.back()] = blacklist.back() + 1;
            for(int i = (int)blacklist.size() - 2; i >= 0; --i){
                if(blacklist[i] + 1 == blacklist[i + 1]){
                    next_valid_num[blacklist[i]] = next_valid_num[blacklist[i + 1]];
                }else{
                    next_valid_num[blacklist[i]] = blacklist[i] + 1;
                }
            }
        }
        
        srand(time(NULL));
    }
    
    int pick() {        
        int valid_rand_num = 0;
        
        if(blacklist.empty()){
            valid_rand_num = rand() % N;
        }else{
            const int VALID_NUMS_CNT = N - (int)blacklist.size();
            const int IGNORED_VALID_NUMS = rand() % VALID_NUMS_CNT;
            
            int l = 0;
            int r = (int)blacklist.size() - 1;
            while(l != r){
                int mid = (l + r) / 2;
                if(blacklist[mid] - mid < IGNORED_VALID_NUMS){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }

            if(IGNORED_VALID_NUMS < blacklist[0]){
                valid_rand_num = IGNORED_VALID_NUMS;
            }else if(IGNORED_VALID_NUMS >= blacklist[r] - r){
                valid_rand_num = next_valid_num[blacklist[r]] + IGNORED_VALID_NUMS - (blacklist[r] - r);
            }else if(IGNORED_VALID_NUMS < blacklist[r] - r){
                valid_rand_num = next_valid_num[blacklist[r - 1]] + IGNORED_VALID_NUMS - (blacklist[r - 1] - (r - 1));
            }
        }
        
        return valid_rand_num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */