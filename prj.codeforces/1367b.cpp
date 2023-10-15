#include<iostream>
#include<vector>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }
        int c = 0, d = 0; 
        for(int i = 0; i < n; i++){
            if (a[i] % 2 == 1 && i % 2 == 0){
                c += 1;
            }
            if (a[i] % 2 == 0 && i % 2 == 1){
                d += 1;
            }
        }
        if (c == d){
            std::cout << c << std::endl;
        }
        else{
            std::cout << -1 << std::endl;
        }
    }
    return 0;
}
