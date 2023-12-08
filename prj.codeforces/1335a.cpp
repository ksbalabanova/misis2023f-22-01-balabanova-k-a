#include<iostream>

int main(){
    int t;
    int n;
    std::cin >> t;
    while (t--){
        std::cin >> n;
        if(n%2 != 0) {
            std::cout << n / 2 << std::endl;
        }
        else {
            std::cout << (n - 1)/2 << std::endl;
        }

    }
}
