#include <iostream>
#include <vector>
using namespace std;

vector<int> memo = {2};  // Memoized prime numbers

int Primes(int n) {
    int last_index = memo.size();
    int last_prime = memo.back();
    
    if (last_index >= n) return memo[n - 1];

    vector<bool> sieve(2 * n * log(n) + 100, true); // Approximate upper bound
    sieve[0] = sieve[1] = false; // 0 and 1 are not prime

    // Mark non-prime numbers
    for (int p : memo) {  
        for (int j = p * p; j < sieve.size(); j += p) {
            sieve[j] = false;
        }
    }

    for (int i = last_prime + 1; memo.size() < n; ++i) {
        if (sieve[i]) {
            memo.push_back(i);
            for (int j = i * i; j < sieve.size(); j += i) {
                sieve[j] = false;
            }
        }
    }

    return memo[n - 1];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << Primes(n) << endl;
    }

    return 0;
}
