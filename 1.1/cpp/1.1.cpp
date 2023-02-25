#include <iostream>
#include <functional>
#include <vector>
#include <map>
#include <typeinfo>
#include <algorithm>


// template <typename T, typename ...args> T call_func(std::function<T (args...)> func, args...){
//     return func(args...);
// }

// bool concat_params(int i, char c, std::string s){
//     std::cout << i << c << s << '\n';
//     return true;
// }

// brute force solution
bool isUnique1(std::string& s){
    for(int i = 0; i < s.length(); i++){
        for(int j = i + 1; j < s.length(); j++)
            if(s[i] == s[j]){
                return 0;
            }
    }   
    return 1; 
}

// using an array to store whether we have seen characters or not
bool isUnique2(std::string& s){
    std::array<bool, 256> charset {};

    for(int i = 0; i < s.length(); i++){
        if(charset[s[i]]){
            return false;
        }else{
            charset[s[i]] = true;
        }
    }
    return true;
}

// using a map to store whether we have seen characters or not
bool isUnique3(std::string& s){
    std::unordered_map<char, bool> umap = {};

    for(int i = 0; i < s.length(); i++){
        if(umap.find(s[i]) != umap.end()){
            return false;
        }else{
            umap[s[i]] = true;
        }
    }
    return true;
}

// sort the string first, and then we only need to iterate through it once
bool isUnique4(std::string& s){
    std::sort(s.begin(), s.end());

    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    std::string s1 = "hello world";
    std::string s2 = "abcdefg";
    std::cout << "1)" << s1 << ": " << isUnique1(s1) << "\n";
    std::cout << "1)" << s2 << ": " << isUnique1(s2) << "\n";
    std::cout << "2)" << s1 << ": " << isUnique2(s1) << "\n";
    std::cout << "2)" << s2 << ": " << isUnique2(s2) << "\n";
    std::cout << "3)" << s1 << ": " << isUnique3(s1) << "\n";
    std::cout << "3)" << s2 << ": " << isUnique3(s2) << "\n";
    std::cout << "4)" << s1 << ": " << isUnique4(s1) << "\n";
    std::cout << "4)" << s2 << ": " << isUnique4(s2) << "\n";
    return 1;
}
