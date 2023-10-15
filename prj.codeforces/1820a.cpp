#include<iostream>
#include<string>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        int ans = 0;
        std::string s;
        std::cin >> s;
        if (s[0] == '_'){
            ans = 1;
        }
         if (s.size() == 1 && s[0] == '^'){
            ans = 1;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '_' && s[i+1] != '^'){
                ans++;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
