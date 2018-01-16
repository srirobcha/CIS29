/*
CIS 29
Name: Robin Cha
Program Description: Parses through an input file using a dictionary file.
                     A review of introductory concepts.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Dictionary.h"
#include "Word.h"

std::ifstream dictionaryFile;
std::ifstream textFile;
const int wordSize = 30;


int main() {
    char dict[50];
//    char getty[50];
    Word text;

    std::cout << "Enter dictionary file path: ";
    std::cin.getline(dict, 50);
//    std::cout << "Enter Gettysburg text file path: ";
//    std::cin >> getty;
//    dictionaryFile.open(dict);
//
//    while (!dictionaryFile.is_open()) {
//        std::cout << "Incorrect file path. Enter dictionary file path: ";
//        std::cin >> dict;
//        dictionaryFile.open(dict);
//    }
//
//    while (dictionaryFile >> text) {
//        std::cout << text << std::endl;
//    }
    Dictionary Websters(dict);

    return 0;
}
