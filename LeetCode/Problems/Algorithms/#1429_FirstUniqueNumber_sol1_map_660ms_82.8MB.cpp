class FirstUnique {
private:
    queue<int> q;
    map<int, int> cnt;
    
public:
    FirstUnique(vector<int>& nums) {
        for(int num: nums){
            q.push(num);
            ++cnt[num];
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && cnt[q.front()] >= 2){
            q.pop();
        }
        if(!q.empty()){
            return q.front();
        }
        return -1;
    }
    
    void add(int value) {
        q.push(value);
        ++cnt[value];
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */