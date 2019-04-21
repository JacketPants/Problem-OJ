#include <iostream>
using namespace std;

#define LL long long
int n;

int f(int l, int r) {
    int ret = 0;
    for(int i = l; i <= r; ++i) {
        ret |= (1 << i);
    }
    return ret;
}

int g(int l, int r) {
    int ret = 0;
    for(int i = l; i <= r; ++i) {
        for(int j = i; j <= r; ++j) {
            ret ^= f(i, j);
        }
    }
    return ret;
}

int w(int l, int r) {
    int ret = 0;
    for(int i = l; i <= r; ++i) {
        for(int j = i; j <= r; ++j) {
            ret ^= g(i, j);
        }
    }
    return ret;
}

void Print(int x) {
    for(int i = 0; i < n; ++i) {
        printf("%d", ((x >> i) & 1));
    }
    printf("\n");
}

int main() {
    n = 12;
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            printf("%2d %2d: ", i + 1, j + 1);
            Print(w(i, j));
        }
    }

    return 0;
}
