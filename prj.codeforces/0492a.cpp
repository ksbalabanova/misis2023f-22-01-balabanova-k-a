#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i=1; i*(i+1)*(i+2)/6 <= n ;i++) {
        ans++;
    }
    std::cout << ans;
}
