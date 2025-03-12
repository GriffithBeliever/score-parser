#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>

std::string stringToScore(const std::string& s);
int levenDistance(const std::string& s1, const std::string& s2);
double jaccardDist(const std::string& s1, const std::string& s2);

#endif // !LIBRARY_H
