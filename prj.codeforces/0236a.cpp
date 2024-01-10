#include<iostream>
#include<string>
#include<set>

int main(){
    std::string name;
    std::set<char> ans;
    std::cin >> name;
    int i = 0;
    while(i < name.length()){
        ans.insert(name[i]);
        i++;
    }
    if(ans.size() % 2 == 0){
        std::cout << "CHAT WITH HER!";
    }
    else{
        std::cout << "IGNORE HIM!";
    }
    return 0;
}
