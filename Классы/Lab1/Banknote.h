#ifndef BANKNOTE_H
#define BANKNOTE_H

class Banknote
{
private:
    int denomination;
    int quantity;
    bool is_valid_denomination(int d);
    
public:
    Banknote(int d, int q);
    int summa() const;
    void printInfo() const;
};

#endif
