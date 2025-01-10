#include <iostream>

using namespace std;

// Function to compute the sum of multiples of a given number up to a limit
unsigned long long sum_of_multiples(int multiple, int limit) {
    long long count = (limit - 1) / multiple;
    return (multiple * count * (count + 1)) / 2;
}

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int limit;
        cin >> limit;

        // Calculate the sum of multiples of 3, 5, and subtract the intersection (15)
        unsigned long long sum3 = sum_of_multiples(3, limit);
        unsigned long long sum5 = sum_of_multiples(5, limit);
        unsigned long long sum15 = sum_of_multiples(15, limit);

        // Result is the sum of multiples of 3 and 5, minus the overlap
        cout << (sum3 + sum5 - sum15) << endl;
    }

    return 0;
}
