struct Movie{
    int movieID;
    int price;
    int shop;

    Movie(int movieID, int price, int shop): movieID(movieID), price(price), shop(shop){

    }

    bool operator<(const Movie& other) const {
        return (tuple<int, int, int>{price, shop, movieID} <
                tuple<int, int, int>{other.price, other.shop, other.movieID});
    }
};

class MovieRentingSystem {
private:
    unordered_map<int, set<Movie>> unrentedMoviesSetOf;
    set<Movie> rentedMoviesSet;
    map<pair<int, int>, int> priceOf;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(vector<int>& entry: entries){
            Movie movie(entry[1], entry[2], entry[0]);
            unrentedMoviesSetOf[movie.movieID].insert(movie);
            priceOf[{movie.movieID, movie.shop}] = movie.price;
        }
    }
    
    vector<int> search(int movieID) {
        if(!unrentedMoviesSetOf.count(movieID)){
            return {};
        }
        vector<int> cheapestShops;
        for(auto it = unrentedMoviesSetOf[movieID].begin(); it != unrentedMoviesSetOf[movieID].end() && (int)cheapestShops.size() < 5; it = next(it)){
            cheapestShops.push_back(it->shop);
        }
        return cheapestShops;
    }
    
    void rent(int shop, int movieID) {
        int price = priceOf[{movieID, shop}];
        Movie movie(movieID, price, shop);
        unrentedMoviesSetOf[movie.movieID].erase(movie);
        rentedMoviesSet.insert(movie);
    }
    
    void drop(int shop, int movieID) {
        int price = priceOf[{movieID, shop}];
        Movie movie(movieID, price, shop);
        unrentedMoviesSetOf[movie.movieID].insert(movie);
        rentedMoviesSet.erase(movie);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> cheapestRentedMovies;
        for(auto it = rentedMoviesSet.begin(); it != rentedMoviesSet.end() && (int)cheapestRentedMovies.size() < 5; it = next(it)){
            cheapestRentedMovies.push_back({it->shop, it->movieID});
        }
        return cheapestRentedMovies;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */