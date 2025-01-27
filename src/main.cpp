#include <iostream>                                                                                                                      
#include "library.h"
      
using namespace std;       

int main() {
    string input = "[Chibiki]_THE_iDOLM@STER_-_01_[720p][C83E5732].mkv";
    cout << "Score of " << input << ": " << stringToScore(input) << endl;
    return 0;
}

