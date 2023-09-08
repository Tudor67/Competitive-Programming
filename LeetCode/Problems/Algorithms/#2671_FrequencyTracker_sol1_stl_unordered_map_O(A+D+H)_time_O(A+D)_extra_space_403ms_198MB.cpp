class FrequencyTracker {
private:
    unordered_map<int, int> f;
    unordered_map<int, int> ff;
    
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        ff[f[number]] -= 1;
        f[number] += 1;
        ff[f[number]] += 1;
    }
    
    void deleteOne(int number) {
        if(f[number] > 0){
            ff[f[number]] -= 1;
            f[number] -= 1;
            ff[f[number]] += 1;
        }
    }
    
    bool hasFrequency(int frequency) {
        return (ff.count(frequency) && ff[frequency] > 0);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */