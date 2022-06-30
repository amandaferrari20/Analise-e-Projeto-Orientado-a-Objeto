#pragma once
#include <string>
#include "EquipamentoDAO.h"


class EquipamentoMgr {

    EquipamentoDAO* equipamentoDao = new EquipamentoDAO();
    public:
    EquipamentoDAO& getEquipamentoDAO();
    bool cadastraEquipamento(int, std::string);//CPF
    EquipamentoDAO verificarEquipamento(int );//CPF

};