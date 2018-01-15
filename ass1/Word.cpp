#include "Word.h"

Word::Word() {
    word_ = new char[1];
    word_[0] = '\0';
}

Word::Word(const char* text = 0) {
    word_ = new char[strlen(text)+1];
    strcpy(word_, text);
}

Word::~Word() {
    delete[] word_;
}

const char* Word::getWord() const {
    return word_;
}

std::ostream& operator<< (std::ostream& out, const Word& cWord) {
    return out << cWord.getWord();

}

std::istream& operator>> (std::istream& in, Word& cWord) {
    char input[30];
    in.get (input, 30);
    cWord = input;
    return in;
}
