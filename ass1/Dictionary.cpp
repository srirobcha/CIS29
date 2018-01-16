#include "Dictionary.h"

Dictionary::Dictionary() {
    capacity_ = 8;
    numWords_ = 0;
    words_ = NULL;
}

Dictionary::Dictionary(const char* fileName) {
    capacity_ = 8;
    numWords_ = 0;
    words_ = new Word*[capacity_];

    std::ifstream dictionaryFile;
    dictionaryFile.open(fileName);
    if (!dictionaryFile.is_open()) {
        std::cout << "Error opening file.";
    }
    while (dictionaryFile >> *words_[numWords_]) {
        if (getNumWords() == getCapacity()) {
            resize();
            numWords_++;
        }
        else {
            std::cout << std::endl << numWords_ << " " << *words_[numWords_];
            numWords_++;
        }
    }

}

Dictionary::~Dictionary() {
    for (unsigned int i = 0; i < numWords_; i++) {
        delete words_[i];
    }
    delete[] words_;
}

void Dictionary::setCapacity(unsigned int c){
    capacity_ = c;
}

void Dictionary::setNumWords(unsigned int n) {
    numWords_ = n;
}

unsigned int Dictionary::getCapacity() const{
    return capacity_;
}

unsigned int Dictionary::getNumWords() const {
    return numWords_;
}

bool Dictionary::find(Word* word) {
    unsigned int first = 0,
                 last = capacity_ - 1,
                 middle,
                 position = -1;
    bool found = false;
    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (words_[middle] == word) {
            found = true;
            position = middle;
        }
        else if (words_[middle] > word)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return found;
}

void Dictionary::resize() {
    unsigned int newSize = capacity_*2;
    Word** nWords = new Word*[newSize];
    std::memcpy(nWords, words_, capacity_*sizeof(unsigned int));

    setCapacity(newSize);
    delete [] words_;
    words_ = nWords;
    std::cout << "Dictionary resized to capacity: " << newSize << std::endl;
}

void Dictionary::addWord(Word* word) {
    if (getNumWords() == getCapacity()) {
        resize();
        addWord(word);
    }
}
