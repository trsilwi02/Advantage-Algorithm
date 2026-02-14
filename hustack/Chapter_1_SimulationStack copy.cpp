#include <iostream>
#include <vector>
#include <string>
#include <set>

// Function to process the queries
void processQueries(std::set<int>& s) {
    std::string command;
    int k;

    // Loop until '#' is encountered
    while (std::cin >> command && command != "#") {
        std::cin >> k;
        
        // Find the first element greater than k
        auto it = s.upper_bound(k);
        
        // Check if an element was found
        if (it != s.end()) {
            std::cout << *it << std::endl;
        } else {
            // No element greater than k found
            std::cout << -1 << std::endl;
        }
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::set<int> unique_elements;
    int value;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        unique_elements.insert(value);
    }

    processQueries(unique_elements);

    return 0;
}
