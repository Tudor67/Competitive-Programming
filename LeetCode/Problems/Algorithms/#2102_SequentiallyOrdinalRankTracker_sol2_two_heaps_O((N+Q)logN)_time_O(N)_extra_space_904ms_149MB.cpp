class SORTracker {
private:
    using PIS = pair<int, string>;
    priority_queue<PIS, vector<PIS>, less<PIS>> leftMax;
    priority_queue<PIS, vector<PIS>, greater<PIS>> rightMin;
    int q;
    
public:
    SORTracker() {
        q = 0;
    }
    
    void add(string name, int score) {
        leftMax.push({-score, name});
        rightMin.push(leftMax.top());
        leftMax.pop();
    }
    
    string get() {
        q += 1;
        while((int)leftMax.size() < q){
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
        return leftMax.top().second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */