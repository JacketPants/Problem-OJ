#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <ctime>
using namespace std;

#define LL long long
const int maxn = 500000 + 100;
int n;
LL ans;
LL num[maxn];
LL lsum[maxn], rsum[maxn];
LL num_rmq[maxn << 2][2];
LL lsum_rmq[maxn << 2][2], rsum_rmq[maxn << 2][2];

void build(int l, int r, int rt) {
    if(l == r) {
        num_rmq[rt][0] = num_rmq[rt][1] = num[l];
        lsum_rmq[rt][0] = lsum_rmq[rt][1] = lsum[l];
        rsum_rmq[rt][0] = rsum_rmq[rt][1] = rsum[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    num_rmq[rt][0] = min(num_rmq[rt << 1][0], num_rmq[rt << 1 | 1][0]);
    num_rmq[rt][1] = max(num_rmq[rt << 1][1], num_rmq[rt << 1 | 1][1]);
    lsum_rmq[rt][0] = min(lsum_rmq[rt << 1][0], lsum_rmq[rt << 1 | 1][0]);
    lsum_rmq[rt][1] = max(lsum_rmq[rt << 1][1], lsum_rmq[rt << 1 | 1][1]);
    rsum_rmq[rt][0] = min(rsum_rmq[rt << 1][0], rsum_rmq[rt << 1 | 1][0]);
    rsum_rmq[rt][1] = max(rsum_rmq[rt << 1][1], rsum_rmq[rt << 1 | 1][1]);
}

LL query_max(LL num[maxn << 2][2], int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return num[rt][1];
    }
    LL ret = (1LL << 63);
//    printf("Min = %I64d\n", ret);
    int m = (l + r) >> 1;
    if(L <= m) {
        ret = max(ret, query_max(num, L, R, l, m, rt << 1));
    }
    if(m < R) {
        ret = max(ret, query_max(num, L, R, m + 1, r, rt << 1 | 1));
    }
    return ret;
}

LL rmq_max(int L, int R, LL num[maxn << 2][2], LL x) {
    if(L > R) {
        return 0;
    }
    return query_max(num, L, R, 1, n, 1) - x;
}

LL query_min(LL num[maxn << 2][2], int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return num[rt][0];
    }
    LL ret =(1LL << 62);
//    printf("Max = %I64d\n", ret);
    int m = (l + r) >> 1;
    if(L <= m) {
        ret = min(ret, query_min(num, L, R, l, m, rt << 1));
    }
    if(m < R) {
        ret = min(ret, query_min(num, L, R, m + 1, r, rt << 1 | 1));
    }
    return ret;
}

LL rmq_min(int L, int R, LL num[maxn << 2][2], LL x) {
    if(L > R) {
        return 0;
    }
    return query_min(num, L, R, 1, n, 1) - x;
}

int read() {
    int f = 1;
    int ret = 0;
    char ch;
    do {
        ch = getchar();
        if(ch == '-') {
            f = -1;
        }
    } while(ch < '0' || ch > '9');
    do {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    } while(ch >= '0' && ch <= '9');
    return ret * f;
}

int get_L(int Index) {
    int high = Index;
    int low = 0;
    int mid;
    while(high - low > 1) {
        mid = (high + low) >> 1;
        if(rmq_min(mid, Index, num_rmq, 0) >= num[Index]) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int get_R(int Index) {
//    printf("int get_R:\n");
    int high = n + 1;
    int low = Index;
    int mid;
    while(high - low > 1) {
        mid = (high + low) >> 1;
//        printf("mid = %d   num = %I64d  rmq_min = %I64d\n", mid, num[Index], rmq_min(Index, mid, num_rmq, 0));
        if(rmq_min(Index, mid, num_rmq, 0) >= num[Index]) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    #ifdef Dmaxiya
    freopen("test.txt", "r", stdin);
    #endif // Dmaxiya

    ans = (1LL << 63);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        num[i] = read();
        lsum[i] = lsum[i - 1] + num[i];
    }
    for(int i = n; i >= 1; --i) {
        rsum[i] = rsum[i + 1] + num[i];
    }
    build(1, n, 1);
    for(int i = 1; i <= n; ++i) {
        int L = get_L(i);
        int R = get_R(i);
        LL tmp;
        if(num[i] > 0) {
            tmp = rmq_max(L, i - 1, rsum_rmq, rsum[i]) + rmq_max(i + 1, R, lsum_rmq, lsum[i]) + num[i];
        } else {
            tmp = rmq_min(L, i - 1, rsum_rmq, rsum[i]) + rmq_min(i + 1, R, lsum_rmq, lsum[i]) + num[i];
        }
        ans = max(ans, tmp * num[i]);
//        printf("Index = %d  L = %d R = %d ans = %I64d\n", i, L, R, tmp * num[i]);
    }
    cout << " \n" << ans << endl;

    return 0;
}

