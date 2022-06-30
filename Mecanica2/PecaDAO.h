#pragma once

#include "Peca.h"

#define MAX_Pecas 600

class PecaDAO{
    Peca* pecas[MAX_Pecas];
    int peca_count = 0;
public:
    bool criarPeca(Peca& );
    bool removerPeca(Peca& );
    bool updatePeca(Peca& );
    Peca* retrievePeca(int );
    Peca* listaNomesPeca(std::string);
    Peca RealizarConsultaPecas(int idPeca);
};