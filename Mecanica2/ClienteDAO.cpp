#pragma once

#include "ClienteDAO.h"

bool ClienteDAO::criarCliente(Cliente& cliente){
    if(this->cliente_count == MAX_Clientes)
        return false;
    this->clientes[this->cliente_count++] = &cliente;
    return true; 
}

bool ClienteDAO::removerCliente(Cliente& ){

}

