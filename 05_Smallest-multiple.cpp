#include <iostream>
#include <vector>

using namespace std;

bool IsPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, result = 1;
        cin >> n;

        for (long long i = 2; i <= n; i += (i == 2 ? 1 : 2)) {
            if (IsPrime(i)) {
                long long power = i;
                while (power * i <= n) {
                    power *= i;
                }
                result *= power;
            }
        }
        cout << result << endl;
    }
    
    return 0;
}
