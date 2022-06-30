#pragma once

#include "Equipamento.h"

#define MAX_Equipamentos 600

class EquipamentoDAO{
    Equipamento* equipamentos[MAX_Equipamentos];
    int equipamento_count = 0;
public:
    bool criarEquipamento(Equipamento& );
    bool removerEquipamento(Equipamento& );
    bool updateEquipamento(Equipamento& );
    Equipamento* retrieveEquipamento(int );
    Equipamento* listaNomesEquipamento(std::string);

};