#ifndef WORD_H
#define WORD_H

class Word {
private:
    char* word;
public:
    Word(const char* text = 0);
    ~Word();

    const char* word() const;

};

#endif
