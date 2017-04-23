#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
set<LL> dau;
int main(){
    freopen("F:\\input.txt", "r", stdin);
    LL uid;
    while (~scanf("%lld", &uid) && uid){
        dau.insert(uid);
    }
    LL ans = dau.size();
    printf("%lld\n", ans);
    return 0;
}