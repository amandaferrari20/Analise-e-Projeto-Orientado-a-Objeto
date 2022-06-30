#pragma once

#include "EquipamentoDAO.h"

bool EquipamentoDAO::criarEquipamento(Equipamento& equipamento){
    if(this->equipamento_count == MAX_Equipamentos)
        return false;
    this->equipamentos[this->equipamento_count++] = &equipamento;
    return true; 
}

bool EquipamentoDAO::removerEquipamento(Equipamento& ){

}