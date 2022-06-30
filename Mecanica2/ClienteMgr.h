#pragma once
#include <string>
#include "ClienteDAO.h"


class ClienteMgr {

    ClienteDAO* clienteDao = new ClienteDAO();
    public:
    ClienteDAO& getClienteDAO();
    bool cadastraCliente(int, std::string);//CPF
    ClienteDAO verificarCliente(int );//CPF
    Cliente RealizarCadastroCliente(char cpf[14], char nome[100], char tel[13], char endereco[300]);
};