#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main(){
    string s;
    cout << "Enter your string: ";
    getline(cin,s);

    unordered_map<char,int> m;

    for (int i=0;i<s.size();i++){
        m[s[i]]++;
    }

    for (auto it : m){
        cout << it.first << "->" << it.second << endl;
    }
    return 0;
}