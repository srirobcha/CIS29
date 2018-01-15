#include <iostream>
#include <cstring>
#include <string>

#ifndef WORD_H
#define WORD_H

class Word {
private:
    //Members
    char* word_;
public:
    //Constructors
    Word();
    Word(const char* text);
    //Destructor
    ~Word();
    //Getter
    const char* getWord() const;
    //Stream Operator
    friend std::ostream& operator<< (std::ostream& out, const Word& cWord);
    friend std::istream& operator>> (std::istream& in, Word& cWord);
};

#endif
