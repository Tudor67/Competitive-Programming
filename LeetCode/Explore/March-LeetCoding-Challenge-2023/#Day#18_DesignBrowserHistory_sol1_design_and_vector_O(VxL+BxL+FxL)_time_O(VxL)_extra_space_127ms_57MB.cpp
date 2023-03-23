class BrowserHistory {
private:
    vector<string> history;
    int index;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        index = 0;
    }
    
    void visit(string url) {
        index += 1;
        history.resize(index + 1);
        history[index] = url;
    }
    
    string back(int steps) {
        index = max(0, index - steps);
        return history[index];
    }
    
    string forward(int steps) {
        index = min(index + steps, (int)history.size() - 1);
        return history[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */