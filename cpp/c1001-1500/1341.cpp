#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// Data structures to represent the database tables
struct User {
    int user_id;
    string name;
};

struct Movie {
    int movie_id;
    string title;
};

struct MovieRating {
    int user_id;
    int movie_id;
    double rating;
    string created_at; // Format: "YYYY-MM-DD"
};

class MovieRatingSystem {
private:
    vector<User> users;
    vector<Movie> movies;
    vector<MovieRating> ratings;

public:
    // Add data to the system
    void addUser(int user_id, const string& name) {
        users.push_back({user_id, name});
    }

    void addMovie(int movie_id, const string& title) {
        movies.push_back({movie_id, title});
    }

    void addRating(int user_id, int movie_id, double rating, const string& created_at) {
        ratings.push_back({user_id, movie_id, rating, created_at});
    }

    // First query: Find user with most movie ratings
    string findUserWithMostRatings() {
        map<pair<int, string>, int> userRatingCount; // key: (user_id, name), value: count
        
        // Count ratings per user
        for (const auto& rating : ratings) {
            // Find user name
            string userName;
            for (const auto& user : users) {
                if (user.user_id == rating.user_id) {
                    userName = user.name;
                    break;
                }
            }
            userRatingCount[{rating.user_id, userName}]++;
        }

        if (userRatingCount.empty()) return "";

        // Find user with maximum ratings
        auto maxUser = userRatingCount.begin();
        for (auto it = userRatingCount.begin(); it != userRatingCount.end(); ++it) {
            if (it->second > maxUser->second || 
                (it->second == maxUser->second && it->first.second < maxUser->first.second)) {
                maxUser = it;
            }
        }

        return maxUser->first.second;
    }

    // Second query: Find highest rated movie in February 2020
    string findHighestRatedMovieFeb2020() {
        map<pair<int, string>, pair<double, int>> movieRatings; // key: (movie_id, title), value: (total_rating, count)
        
        // Calculate average ratings for movies in Feb 2020
        for (const auto& rating : ratings) {
            // Check if rating is in February 2020
            if (rating.created_at >= "2020-02-01" && rating.created_at <= "2020-02-29") {
                // Find movie title
                string movieTitle;
                for (const auto& movie : movies) {
                    if (movie.movie_id == rating.movie_id) {
                        movieTitle = movie.title;
                        break;
                    }
                }
                
                auto& movieData = movieRatings[{rating.movie_id, movieTitle}];
                movieData.first += rating.rating;
                movieData.second++;
            }
        }

        if (movieRatings.empty()) return "";

        // Find movie with highest average rating
        auto bestMovie = movieRatings.begin();
        double bestAvg = bestMovie->second.second > 0 ? bestMovie->second.first / bestMovie->second.second : 0;

        for (auto it = movieRatings.begin(); it != movieRatings.end(); ++it) {
            if (it->second.second > 0) {
                double currentAvg = it->second.first / it->second.second;
                double bestAvg = bestMovie->second.first / bestMovie->second.second;

                if (currentAvg > bestAvg || 
                    (abs(currentAvg - bestAvg) < 1e-9 && it->first.second < bestMovie->first.second)) {
                    bestMovie = it;
                }
            }
        }

        return bestMovie->first.second;
    }

    // Main function that combines both queries (equivalent to UNION ALL)
    vector<string> getResults() {
        vector<string> results;
        
        string userResult = findUserWithMostRatings();
        if (!userResult.empty()) {
            results.push_back(userResult);
        }
        
        string movieResult = findHighestRatedMovieFeb2020();
        if (!movieResult.empty()) {
            results.push_back(movieResult);
        }
        
        return results;
    }
};

// Example usage
int main() {
    MovieRatingSystem system;

    // Add sample data
    system.addUser(1, "Alice");
    system.addUser(2, "Bob");
    system.addUser(3, "Charlie");

    system.addMovie(1, "The Matrix");
    system.addMovie(2, "Inception");
    system.addMovie(3, "Interstellar");

    system.addRating(1, 1, 4.5, "2020-02-15");
    system.addRating(1, 2, 4.0, "2020-02-20");
    system.addRating(2, 1, 5.0, "2020-02-10");
    system.addRating(2, 3, 4.5, "2020-02-25");
    system.addRating(3, 2, 3.5, "2020-02-18");
    system.addRating(1, 3, 4.0, "2020-03-01"); // Not in February

    // Get results
    vector<string> results = system.getResults();
    
    cout << "Results:" << endl;
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}