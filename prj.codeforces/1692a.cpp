#include<iostream>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int ans = 0;
        if(a < b){
          ans++;
        }
        if(a < c){
          ans++;
        }
        if(a < d){
          ans++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
