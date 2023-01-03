#ifndef TRABALHOAED2_APP_H
#define TRABALHOAED2_APP_H
#include "Gestao.h"


class App {
public:
    void start(); // Starts the application
    bool printUserMenu(); // Prints the User Menu/Interface
private:
    Gestao gestao;
};


#endif //TRABALHOAED2_APP_H
