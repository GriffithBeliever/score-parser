#include "library.h"
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>
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
//     cout << string(1, upper_c) + " "<< value << endl;
      score += to_string(value);
    }
    
    return score;
}

int levenDistance(const string& s1, const string& s2) {
    const int s1Count = s1.size();
    const int s2Count = s2.size();

    if (s1Count < 0) {
        return s2Count;
    }
    if (s2Count < 0) {
        return s1Count;
    }

    int matrix[s1Count+1][s2Count+1];

    for (int i=0; i<s1Count; i++) {
        matrix[i][0] = i;
    }

    for (int j=0; j<s2Count; j++) {
        matrix[0][j] = j;
    }

    vector<char> s1Array(s1.begin(), s1.end());
    vector<char> s2Array(s2.begin(), s2.end());

    for (int i=1; i<=s1Count; i++) {
        for (int j=1; j<=s2Count; j++) {
            if (s1Array[i-1] == s2Array[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                int ins = matrix[i][j-1] + 1;
                int del = matrix[i-1][j] + 1;
                int rep = matrix[i-1][j-1] + 1;
                
                matrix[i][j] = std::min(std::min(ins, del), rep);
            }
        }

    }

    return matrix[s1Count][s2Count];
}

double jaccardDist(const string& s1, const string& s2) {
    set<char> s1Set(s1.begin(), s1.end());
    set<char> s2Set(s2.begin(), s2.end());

    set<char> intersection; 
    set<char> unionSet;

    set_intersection(s1Set.begin(), s1Set.end(), s2Set.begin(), s2Set.end(),
            inserter(intersection, intersection.begin()));

    set_union(s1Set.begin(), s1Set.end(),
            s2Set.begin(), s2Set.end(),
            inserter(unionSet, unionSet.begin()));
    
    int n_intersections = intersection.size();
    int n_unions = unionSet.size();

    return double(n_intersections) / double(n_unions);
}
