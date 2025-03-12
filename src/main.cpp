#include <iostream>                                                                                                                      
#include "library.h"
      
using namespace std;       

int main() {
    string input = "[Chibiki]_THE_iDOLM@STER_-_01_[720p][C83E5732].mkv";
    string s1 = "hello";
    string s2 = "hallo";

    cout << "Score of " << input << ": " << stringToScore(input) << endl;
    cout << "Levenshtein distance of " << s1 << " and " << 
        s2 << " is " << levenDistance(s1, s2) << endl;
    cout << "Jaccard distance of " << s1 << " and " << 
        s2 << " is " << jaccardDist(s1, s2) << endl;
    return 0;
}

