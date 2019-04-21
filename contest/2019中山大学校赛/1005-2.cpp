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
const int maxn = 300000 + 100;
char str[maxn];

int main() {
    #ifdef Dmaxiya
    freopen("test.txt", "r", stdin);
    #endif // Dmaxiya

    while(scanf("%s", str) != EOF) {
        int len = strlen(str);
        for(int i = 0; i < len; i += 3) {
        
            int x = 0;
            x |= int(str[i]);
            x |= int(str[i + 1]) << 8;
            x |= int(str[i + 2]) << 16;
            int xx = 0;
            for(int j = 0; j < 24; ++j) {
                xx = (xx << 1) | ((x >> j) & 1);
            }
            if(i!=len-3)
            printf("%d %d %d %d ", (xx >> 18) & 63, (xx >> 12) & 63, (xx >> 6) & 63, xx & 63);
            else printf("%d %d %d %d", (xx >> 18) & 63, (xx >> 12) & 63, (xx >> 6) & 63, xx & 63);
            
        }
        
    }

    return 0;
}
