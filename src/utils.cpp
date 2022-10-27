#include "utils.h"
#include "trie.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <random>
#include <algorithm> 

/*FALTA FER SUFFIX TREE -> AGAFAR-LO DEL MEU PRIMER COMMIT*/
std::vector<std::string> Utils::findAndRemoveSuffixPrefixMatch(std::string a, std::vector<std::string> s, 
            int error, bool allowInDel) {
    
    std::vector<std::string> waf;
    /*
         * To find the sequences in S that have a suffix that perfectly match a prefix of the
         * adapter, i reverse both strings, that way i only need to create 1 suffixtree. (finding a
         * prefix in reversed "S" that matches the suffix in reverse "a")
    */ 
}

std::vector<std::string> Utils::findAndRemoveSuffixPrefixMatch(std::string a, std::vector<std::string> s) {
    return findAndRemoveSuffixPrefixMatch(a, s, 0, false);
}

std::string Utils::createRandomDNAString(int len) {
    std::vector<char> alphabet = {'A', 'C', 'T', 'G', 'N'};
    
    std::stringstream ss;
    for (int i = 0; i < len; i++)
        ss.put(alphabet[rand() % alphabet.size() + 1]);
    
    return ss.str();
}

void Utils::compare(std::string e, std::string a) {
    std::cout << "Expected: " << e << std::endl;
    std::cout << "Actual: " << a << std::endl;

    int correct = 0;
    int compLen = std::min(e.length(), a.length());

    std::cout << "Matching:" << std::endl;

    for (int i = 0; i < compLen; i++) {
        if (e[i] == a[i]) {
            std::cout << e[i];
            correct++;
        }
        else {
            std::cout << "-";
        }
    }
    std::cout << std::endl;
    double percentageCorrect = 100.0 * (double) correct / compLen;
    std::cout << "Correct: " << percentageCorrect << std::endl;
}

std::string Utils::reverseString(const std::string& s) {
    std::string reversedString = "";
    for (int i = s.size() - 1; i >= 0; --i) reversedString.push_back(s[i]);
    return reversedString;
}

uint Utils::editDistance(const std::string& s, const std::string& a) {
    uint m = s.length() + 1, n = a.length() + 1;
    std::vector<std::vector<uint>> dp = std::vector<std::vector<uint>> (m, std::vector<uint> (n));
    for (uint i = 0; i < m; ++i) {
        for (uint j = 0; j < n; ++j) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (s[i - 1] == a[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
               dp[i][j] = 1 + std::min(dp[i][j - 1], std::min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[m - 1][n - 1];
} 

uint Utils::nuclToInt(char nucleotide) {
    if (nucleotide == 'A') return 0;
    else if (nucleotide == 'C') return 1;
    else if (nucleotide == 'G') return 2;
    else return 3;
}

char Utils::intToNucl(uint i) {
    if (i == 0) return 'A';
    else if (i == 1) return 'C';
    else if (i == 2) return 'G';
    else return 'T';
}