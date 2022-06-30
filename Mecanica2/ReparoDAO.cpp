#pragma once

#include "ReparoDAO.h"

bool ReparoDAO::criarReparo(Reparo& Reparo){
    if(this->reparo_count == MAX_Reparo)
        return false;
    this->reparo[this->reparo_count++] = &Reparo;
    return true; 
}

bool ReparoDAO::removerReparo(Reparo& ){

}

