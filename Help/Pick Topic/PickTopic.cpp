#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize the list of topics
    std::vector<std::string> topics = {
        "combine-tags-by-or", "2-sat", "binary search", "bitmasks", "brute force",
        "chinese remainder theorem", "combinatorics", "constructive algorithms",
        "data structures", "dfs and similar", "divide and conquer", "dp", "dsu",
        "expression parsing", "fft", "flows", "games", "geometry", "graph matchings",
        "graphs", "greedy", "hashing", "implementation", "interactive", "math",
        "matrices", "meet-in-the-middle", "number theory", "probabilities",
        "schedules", "shortest paths", "sortings", "string suffix structures",
        "strings", "ternary search", "trees", "two pointers"
    };

    // Seed random number generator
    std::srand(std::time(nullptr));

    // Generate a random index within the range of the topics vector
    int randomIndex = std::rand() % topics.size();

    // Output the randomly selected topic
    std::cout << "Random topic: " << topics[randomIndex] << std::endl;

    return 0;
}

