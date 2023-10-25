#include<iostream>
int main(){
    int n, a, b, c, ans = 0;
    std::cin >> n;
    while(n--){
        std::cin>>a>>b>>c;
        int k = a + b + c;
        if (k >= 2){
            ans += 1;
        }
    }
    std::cout << ans;
}
