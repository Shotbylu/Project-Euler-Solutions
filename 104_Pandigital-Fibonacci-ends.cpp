#include <bits/stdc++.h>
using namespace std;

void GetSum(vector<int> &a, vector<int> &b, vector<int> &c, bool left, int &size) {
    int carry = 0;
    int i, j;
    
    for (i = 19, j = 19; i >= 0; i--, j--) {
        if (a[i] == -1 && b[i] == -1) break;

        int sum = carry + (a[i] != -1 ? a[i] : 0) + (b[j] != -1 ? b[j] : 0);
        carry = sum / 10;

        if (c[i] == -1) size++;
        c[i] = sum % 10;
    }

    if (carry) {
        if (i < 0) {
            size++;
            if (left) {
                rotate(c.begin(), c.begin() + 19, c.end());
                rotate(b.begin(), b.begin() + 19, b.end());
                c[0] = carry;
                b[0] = 0;
            }
        } else if (c[i] == -1) {
            c[i] = 1;
            size++;
        } else {
            c[i]++;
        }
    }
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> a_l(20, -1), a_r(20, -1);
    vector<int> b_l(20, -1), b_r(20, -1);
    vector<int> c_l(20, -1), c_r(20, -1);

    a_l[19] = a_r[19] = a;
    b_l[19] = b_r[19] = b;
    c_l[19] = c_r[19] = 0;

    int size = 1;

    for (int i = 3; i <= 2'000'000; i++) {
        GetSum(a_l, b_l, c_l, true, size);
        GetSum(a_r, b_r, c_r, false, size);

        if (size >= k) {
            vector<bool> l_digits(10, false), r_digits(10, false);
            int L = find(c_l.begin(), c_l.end(), -1) - c_l.begin();
            int R = 19;

            bool valid = true;
            for (int count = 1; count <= k; L++, R--, count++) {
                if (l_digits[c_l[L]] || r_digits[c_r[R]]) {
                    valid = false;
                    break;
                }
                l_digits[c_l[L]] = true;
                r_digits[c_r[R]] = true;
            }

            if (valid && all_of(l_digits.begin() + 1, l_digits.begin() + k + 1, [](bool v) { return v; }) &&
                all_of(r_digits.begin() + 1, r_digits.begin() + k + 1, [](bool v) { return v; })) {
                cout << i;
                return 0;
            }
        }

        copy(b_l.begin(), b_l.end(), a_l.begin());
        copy(b_r.begin(), b_r.end(), a_r.begin());
        copy(c_l.begin(), c_l.end(), b_l.begin());
        copy(c_r.begin(), c_r.end(), b_r.begin());
    }

    cout << "no solution";
    return 0;
}
