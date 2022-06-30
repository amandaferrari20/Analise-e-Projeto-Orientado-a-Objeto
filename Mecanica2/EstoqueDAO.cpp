#pragma once

#include "EstoqueDAO.h"

bool EstoqueDAO::criarEstoque(Estoque& estoque){
    if(this->estoque_count == MAX_Estoques)
        return false;
    this->estoques[this->estoque_count++] = &estoque;
    return true; 
}

bool EstoqueDAO::removerEstoque(Estoque& ){

}