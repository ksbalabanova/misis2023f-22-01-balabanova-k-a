#include<iostream>
#include<vector>

int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<int> a(n+1);
        int m = 0;
        int j;
        for (int i = 1;i <= n; i++){
            std::cin>>a[i];
            if(a[i] == a[1]){
                m++;
            }
            else {
                j = i;
            }
        }
        if(m == 1){
            std::cout << 1 << std::endl;
        }
        else {
            std::cout << j << std::endl;
        }
    }
    return 0;
}
