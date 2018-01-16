#include <iostream>
#include <cstring>
#include <string>

#ifndef WORD_H
#define WORD_H

class Word {
private:
    //Members
    char* word_;
    int length_;
public:
    //Constructors
    Word();
    Word(const char* text);
    Word(const Word& cWord);
    //Destructor
    ~Word();
    //Getter
    const char* getWord() const;
    const int getLength() const;
    //Friend Operators
    friend std::ostream& operator<< (std::ostream& out, const Word& cWord);
    friend std::istream& operator>> (std::istream& in, Word& cWord);
    friend bool operator== (const Word& lhs, const Word& rhs);
    friend bool operator> (const Word& lhs, const Word& rhs);
    friend bool operator< (const Word& lhs, const Word& rhs);
    //Operators
    char operator[] (int index) const;
    Word& operator= (const Word& cWord);

};

#endif
