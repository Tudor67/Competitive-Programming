class Solution {
private:
    int get_state(const vector<int>& V){
        int state = 0;
        for(int bit: V){
            state = 2 * state + bit;
        }
        return state;
    }
    
    int get_next_state(const int& STATE){
        int next_state = 0;
        for(int j = 1; j < 7; ++j){
            bool l = (STATE & (1 << (j - 1))) > 0;
            bool r = (STATE & (1 << (j + 1))) > 0;
            if(l == r){
                next_state |= (1 << j);
            }
        }
        return next_state;
    }
    
    vector<int> get_vector_from_state(const int& STATE){
        vector<int> v(8, 0);
        for(int j = 0; j < 8; ++j){
            if(STATE & (1 << j)){
                v[j] = 1;
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
    
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {        
        vector<int> vis(1 << 9, -1);
        int state = get_state(cells);
        vis[state] = 0;
        
        for(int i = 1; i <= N; ++i){
            state = get_next_state(state);
            if(vis[state] == -1){
                vis[state] = i;
            }else{
                int cycle_len = i - vis[state];
                int expected_day = vis[state] + (N - vis[state]) % cycle_len;
                for(int j = 0; j < vis.size(); ++j){
                    if(vis[j] == expected_day){
                        state = j;
                        break;
                    }
                }
                break;
            }
        }
        
        vector<int> answer = get_vector_from_state(state);
        answer[0] = 0;
        answer[7] = 0;
        
        return answer;
    }
};