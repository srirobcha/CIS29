#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "Word.h"
#include <fstream>

class Dictionary {
private:
    Word** words_;
    unsigned int capacity_; //max number of words Dictionary can hold
    unsigned int numWords_;
public:
    //Constructors
    Dictionary();
    Dictionary(const char* fileName);
    //Destructors
    ~Dictionary();
    //Setters
    void setCapacity(unsigned int c);
    void setNumWords(unsigned int n);
    //Getters
    unsigned int getCapacity() const;
    unsigned int getNumWords() const;
    //Functions
    bool find(Word* word);
    void resize();
    void addWord(Word* word);

};

#endif
