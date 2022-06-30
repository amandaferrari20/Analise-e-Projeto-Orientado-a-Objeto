#pragma once
#include <string>
#include "ReparoDAO.h"
#include "Equipamento.h"

class ReparoMgr {

    ReparoDAO* reparoDao = new ReparoDAO();
    public:
    ReparoDAO& getReparoDAO();
    bool cadastraReparo(int, std::string);//CPF
    ReparoDAO verificarReparo(int );//CPF
    void FinalizarReparo(Equipamento equipamento, char dataFinalizacao[10], int IdMecanico){};
    void AtualizarDataReparo(Equipamento equipamento, char dataFinalizacao[10], int IdMecanico){};
};