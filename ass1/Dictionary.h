#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "Word.h"

class Dictionary {
private:
    Word** words_;
    unsigned int capacity_; //max number of words Dictionary can hold
    unsigned int numWords_;
    void resize();
    void addWord(char* word);
public:
    Dictionary(const char* filename);
    ~Dictionary();
    bool find(const char* word);
};

#endif
