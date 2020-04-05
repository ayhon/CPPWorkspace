#include <iostream>
#include <cmath>
using namespace std;
using ll = long long int;

void resuelveCaso()
{
    ll n, t, m, d, i;
    cin >> n >> t >> m >> d >> i;
    ll sol;
    if (n % m != 0) {
        ll desc = n / m;
        ll inc = desc * (desc - 1) / 2;
        sol = n * t + inc * i + desc * d;
    }
    else {
        ll desc = n / m - 1;
        ll inc = (desc) * (desc - 1) / 2;
        sol = n * t + inc * i + desc * d;
    }

    cout << sol << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        resuelveCaso();
    return 0;
}