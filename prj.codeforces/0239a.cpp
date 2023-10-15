#include<iostream>

int main(){
    int y, k, n;
    std::cin >> y >> k >> n;
    int res = (y / k + 1) * k;
    bool flag = false;
    while(res <= n){
        std::cout << res - y << ' ';
        flag = true;
        res += k;
    }
    if (flag == false){
        std::cout << -1;
    }
    return 0;
}
