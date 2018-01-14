/*
CIS 29
Name: Robin Cha
Program Description: Parses through an input file using a dictionary file.
                     A review of introductory concepts.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"
#include "Word.h"

std::ifstream dictionaryFile;
std::ifstream textFile;

int main() {
    std::string dict;
    std::string text;

    std::cout << "Enter dictionary file path: ";
    getline(std::cin, dict);
//    std::cout << "Enter word text file path: ";
//    std::cin >> text;
    dictionaryFile.open(dict);

    while (!dictionaryFile.is_open()) {
        std::cout << "Incorrect file path. Enter dictionary file path: ";
        std::cin >> dict;
        dictionaryFile.open(dict);
    }

    while (dictionaryFile >> text) {
        std::cout << text << std::endl;
    }




    return 0;
}