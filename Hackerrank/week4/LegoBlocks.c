#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define MAX_W 1001

long long int power[MAX_W]; 
long long int total[MAX_W]; 
long long int solid[MAX_W]; 


void computePower() {
    power[0] = 1;
    for (int i = 1; i < MAX_W; i++) {
        power[i] = 0;
        if (i - 1 >= 0) power[i] = (power[i] + power[i - 1]) % MOD;
        if (i - 2 >= 0) power[i] = (power[i] + power[i - 2]) % MOD;
        if (i - 3 >= 0) power[i] = (power[i] + power[i - 3]) % MOD;
        if (i - 4 >= 0) power[i] = (power[i] + power[i - 4]) % MOD;
    }
}

long long int modPow(long long int a, long long int b) {
    long long int result = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

void solve(int n, int m) {
    for (int i = 1; i <= m; i++) {
        total[i] = modPow(power[i], n);  
        solid[i] = total[i];
        for (int j = 1; j < i; j++) {
            solid[i] = (solid[i] - (solid[j] * total[i - j]) % MOD + MOD) % MOD;
        }
    }

    printf("%lld\n", solid[m]);
}

int main() {
    computePower(); 
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        solve(n, m);
    }

    return 0;
}
