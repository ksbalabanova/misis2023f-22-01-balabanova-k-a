#include<iostream>
#include<vector>
 
 
int main()
{
    int n,t;
    std::vector<int> a(5);
    std::cin>>n;
    int ans;
    while(n--) {
        std::cin >> t;
        a[t]++;
    }
    ans = a[4]+a[3]+(2*a[2]+std::max(a[1]-a[3],0)+3)/4;
    std::cout << ans;
}
