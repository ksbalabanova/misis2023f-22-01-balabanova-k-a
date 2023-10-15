#include<iostream>

int main(){
    int a, b, ans = 0;
    std::cin >> a >> b;
    while(a <= b){
        a *= 3;
        b *= 2;
        ans++;
    }
    std::cout << ans;
    return 0;
}
