#include <iostream>
#include <functional>
#include <vector>
#include <map>
#include <typeinfo>
#include <algorithm>

using namespace std;

// solution 1
// sort and iterate
bool isPerm1(string& s1, string& s2){
    if(s1.length() != s2.length()){
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(size_t i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}

// solution 2
// store information in array of char counts

bool isPerm2(string& s1, string& s2){
    if(s1.length() != s2.length()){
        return false;
    }
    array<int, 256> char_counts {0};

    for(char c: s1){
        char_counts[c] += 1;
    }
    for(char c: s2){
        if(char_counts[c] == 0){
            return false;
        }
        char_counts[c] -= 1;
    }
    for(int i: char_counts){
        if(i != 0){
            return false;
        }
    }
    return true;
}
int main(){
    vector<string> s1vec {"abcdefgh", "adam", "python123", "python234"};
    vector<string> s2vec {"hgfeabcd", "maad", "p1234ython", "pzthon234"};
    vector<bool> expectedvec {true, true, false, false};
    for(size_t i = 0; i < s1vec.size(); i++){
        string s1 {s1vec[i]};
        string s2 {s2vec[i]};
        bool expected {expectedvec[i]};
        string result1 {(isPerm1(s1, s2) == expected) ? "SUCCESS!" : "FAILURE!"};
        string result2 {(isPerm2(s1, s2) == expected) ? "SUCCESS!" : "FAILURE!"};
        cout << "isPerm1 s1: " << s1vec[i] << " s2: " << s2vec[i] << " Result: " << result1 << '\n';
        cout << "isPerm2 s1: " << s1vec[i] << " s2: " << s2vec[i] << " Result: " << result2 << '\n';
    }
    return 1;
}
