#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string s;
    cout << "Enter your string: ";
    cin.ignore();
    getline(cin,s);

    for (char &c : s){
        c = tolower(c);
    }
    int vowel=0;

    for (int i=0;i<s.size();i++){
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            vowel++;
        }
    }

    cout << "No of vowels in the string is " << vowel << endl;

    return 0;
}