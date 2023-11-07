#include<iostream>

int main(){
    int k, n, w;
    std::cin >> k >> n >> w;
    while (w > 0){
        n -= w * k;
        w--;
    }
    if(n > 0){
        std::cout << 0;
    }else{
        std::cout << std::abs(n);
    }
}
