#pragma once

#include "Cliente.h"

#define MAX_Clientes 600

class ClienteDAO{
    Cliente* clientes[MAX_Clientes];
    int cliente_count = 0;
public:
    bool criarCliente(Cliente& );
    bool removerCliente(Cliente& );
    bool updateCliente(Cliente& );
    Cliente* retrieveCliente(int );
    Cliente* listaNomesCliente(std::string);
    Cliente VerificarCadastroCliente(char cpf[14]);
};