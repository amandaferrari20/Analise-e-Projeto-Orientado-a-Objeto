#pragma once

#include "Estoque.h"

#define MAX_Estoques 600

class EstoqueDAO{
    Estoque* estoques[MAX_Estoques];
    int estoque_count = 0;
public:
    bool criarEstoque(Estoque& );
    bool removerEstoque(Estoque& );
    bool updateEstoque(Estoque& );
    Estoque* retrieveEstoque(int );
    Estoque* listaNomesEstoque(std::string);

};