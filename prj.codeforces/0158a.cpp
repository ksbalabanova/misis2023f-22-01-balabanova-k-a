#include<iostream>
#include<vector>


int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= a[k - 1] && a[i] > 0){
            ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
