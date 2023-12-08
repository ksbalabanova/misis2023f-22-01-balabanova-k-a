#include<iostream>
#include<string>

int main(){
    std::string s;
    std::cin >> s;
int tmp = 0;
    std::string h = "hello";
    for(int i = 0; i < s.size(); i++){
        if(h[0] == s[i] && h[1] != 'x'){
            h[0] = 'x';
            tmp = i;
        }
        if(h[1] == s[i] && h == "xello" && tmp < i){
            h[1] = 'x';
            tmp = i;
        }
        if(h[2] == s[i] && h == "xxllo" && tmp < i){
            h[2] = 'x';
            tmp = i;
        }
        if(h[3] == s[i] && h == "xxxlo" && tmp < i){
            h[3] = 'x';
            tmp = i;
        }
        if(h[4] == s[i] && h == "xxxxo" && tmp < i) {
            h[4] = 'x';
            tmp = i;
        }
    }
    if(h == "xxxxx"){
        std::cout << "YES";
    }
    else{
        std::cout << "NO";
    }
}
