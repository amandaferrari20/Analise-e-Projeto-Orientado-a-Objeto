#pragma once

#include "Reparo.h"

#define MAX_Reparo 600

class ReparoDAO{
    Reparo* reparo[MAX_Reparo];
    int reparo_count = 0;
public:
    bool criarReparo(Reparo& );
    bool removerReparo(Reparo& );
    bool updateReparo(Reparo& );
    Reparo* retrieveReparo(int );
    Reparo* listaNomesReparo(std::string);
    void VerificarReparoAserFeito(){};
};