#include "library.h"
#include <iostream>
#include <string>
#include <regex>
#include <cctype>

using namespace std;

string stringToScore(const string& s) {
    string score = "";
 
    if (s.empty()) {
      return "";
    }

    int position = 0;
    for(char c : s) {
      position += 1;
      if (!isalpha(c)) {
        continue;
      }
      char upper_c = toupper(c);
      int value = upper_c - 'A' + position;
      cout << string(1, upper_c) + " "<< value << endl;
      score += to_string(value);
    }
    
    return score;
}
