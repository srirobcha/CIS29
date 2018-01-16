#include "Word.h"

Word::Word() {
    length_ = 0;
    word_ = NULL;
}

Word::Word(const char* text = 0) {
    if (text) {
        length_ = strlen(text);
        word_ = new char[length_+1];
        strcpy(word_, text);
    }
    else {
        word_ = NULL;
        length_ = 0;
    }
}

Word::Word(const Word& cWord) {
    length_ = cWord.getLength();
    word_ = new char[length_];
    for (int i = 0; i < length_; i++)
        word_[i] = cWord[i];
}

Word::~Word() {
    if (word_)
        delete[] word_;
}

const char* Word::getWord() const {
    return word_;
}

const int Word::getLength() const {
    return length_;
}

std::ostream& operator<< (std::ostream& out, const Word& cWord) {
    if (cWord.getLength() > 0) {
        for (int i = 0; i < cWord.getLength(); i++)
            out << cWord[i];
    }
    else
        out << "";
    return out;
}

std::istream& operator>> (std::istream& in, Word& cWord) {
    char input[30];
    in >> input;
    cWord = Word(input);
    return in;
}

bool operator== (const Word& lhs, const Word& rhs){
    if (lhs.getLength() != rhs.getLength())
        return false;
    int totalLength = lhs.getLength();
    int i = 0;
    while ( (i < totalLength) && (lhs[i] == rhs[i]))
        i++;
    return i == totalLength;
}

bool operator> (const Word& lhs, const Word& rhs) {
    int totalLength = (lhs.getLength() < rhs.getLength()) ? lhs.getLength() : rhs.getLength();
    int i = 0;
    while ( (i < totalLength) && (lhs[i] == rhs[i]))
        i++;
    if (i == totalLength)
        return lhs.getLength() > rhs.getLength();
    //compare lhs and rhs letters ASCII
    if ( (('A' <= lhs[i] && lhs[i] >= 'Z') || ('a' <= lhs[i] && lhs[i] >= 'z')) &&
            (('A' <= rhs[i] && rhs[i] >= 'Z') || ('a' <= rhs[i] && rhs[i] >= 'z'))) {
        char l = lhs[i];
        char r = rhs[i];
        if (l != r)
            return  l > r;
    }
    return lhs[i] > rhs[i];
}

bool operator< (const Word& lhs, const Word& rhs) {
    return !(lhs == rhs) && !(lhs > rhs);
}

char Word::operator[] (int index) const {
    if (index >= length_) throw 1;
    return word_[index];
}

Word& Word::operator= (const Word& cWord) {
    if (this == &cWord)
        return *this;
    length_ = cWord.getLength();
    word_ = new char[length_];
    for (int i = 0; i < length_; i++)
        word_[i] = cWord[i];
    return *this;
}
