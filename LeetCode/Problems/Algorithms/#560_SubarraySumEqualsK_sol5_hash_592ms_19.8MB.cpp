class HashMap{
private:
    static const int MODULO = 367013;
    vector<pair<int, int>> hash[MODULO];
    
public:
    void insert(const int& key){
        int bucket_id = abs(key) % MODULO;
        bool found = false;
        for(pair<int, int>& p: hash[bucket_id]){
            if(p.first == key){
                p.second += 1;
                found = true;
                break;
            }
        }
        if(!found){
            hash[bucket_id].push_back({key, 1});
        }
    }
    
    int get_freq(const int& key){
        int bucket_id = abs(key) % MODULO;
        for(pair<int, int>& p: hash[bucket_id]){
            if(p.first == key){
                return p.second;
            }
        }
        return 0;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        int prefix_sum = 0;
        HashMap cnt;
        cnt.insert(0);
        for(int num: nums){
            prefix_sum += num;
            answer += cnt.get_freq(prefix_sum - k);
            cnt.insert(prefix_sum);
        }
        return answer;
    }
};