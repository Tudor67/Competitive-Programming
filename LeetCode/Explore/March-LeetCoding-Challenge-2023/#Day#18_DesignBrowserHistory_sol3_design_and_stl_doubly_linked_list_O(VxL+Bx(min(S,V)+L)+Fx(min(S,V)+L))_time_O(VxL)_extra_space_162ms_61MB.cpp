class BrowserHistory {
private:
    list<string> historyList;
    list<string>::iterator currentIt;

public:
    BrowserHistory(string homepage) {
        historyList.push_back(homepage);
        currentIt = historyList.begin();
    }
    
    void visit(string url) {
        historyList.erase(next(currentIt), historyList.end());
        historyList.push_back(url);
        currentIt = prev(historyList.end());
    }
    
    string back(int steps) {
        while(steps >= 1 && currentIt != historyList.begin()){
            currentIt = prev(currentIt);
            steps -= 1;
        }
        return *currentIt;
    }
    
    string forward(int steps) {
        while(steps >= 1 && next(currentIt) != historyList.end()){
            currentIt = next(currentIt);
            steps -= 1;
        }
        return *currentIt;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */