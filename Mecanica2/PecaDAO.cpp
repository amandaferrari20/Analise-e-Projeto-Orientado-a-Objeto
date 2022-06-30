#pragma once

#include "PecaDAO.h"

bool PecaDAO::criarPeca(Peca& peca){
    if(this->peca_count == MAX_Pecas)
        return false;
    this->pecas[this->peca_count++] = &peca;
    return true; 
}

bool PecaDAO::removerPeca(Peca& ){

}