#pragma once
#include <string>
#include "PecaDAO.h"


class PecaMgr {

    PecaDAO* pecaDao = new PecaDAO();
    public:
    PecaDAO& getPecaDAO();
    bool cadastraPeca(int, std::string);//CPF
    PecaDAO verificarPeca(int );//CPF

};