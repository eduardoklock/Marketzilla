#ifndef _Client_h_
#define _Client_h_

#include "dataStructures/CircularList.h"

#include "Payment.h"
#include "CashierPreference.h"

using dataStructures::CircularList;

namespace marketzilla{

class Client {
public:
    /**
 * @brief Constroi o cliente com uma forma de pagamento, tipo de fila que escolherá, nuemro de itens, valor dos itens e tempo que chega do mercado
 *
 * @param payment forma de pagamento
 *@param preference qual tipo de fila prefere
 *@param _totalItems totais de itens comprados 
 *@param _totalItemsValue valor total da compra
 *@param _arrivalTime tempo que cliente entra no mercado
 */
    Client(Payment* payment, CashierPreference* preference, int _totalItems, double _totalItemsValue, int _arrivalTime);
    ~Client();

/**
 * @brief Retorna verdadeiro caso ele entre em alguma fila que o agrada, falso caso não entre em nenhuma.
 *
 * @param cashiers Lista de caixa para cliente ter acesso as filas
 *
 * @return Se o cliente entrou ou não na fila
 */
    bool chooseCashier(CircularList<Cashier>& cashiers);

/**
 * @brief Calcula o tempo de saída do cliente recebido
 *
 * @details Esta é a implementação do caixa com processamento bom
 *
 * @param Cliente que terá seu tempo de saída calculado
 *
 * @return O horário que esse cliente sairá do supermercado
 */
    Payment* makePayment() const;

/**
 * @brief Retorna o numero de itens do cliente
 *
 * @return Numero de itens
 */
    int totalItems() const;

/**
 * @brief Retorna o valor da compra do cliente
 *
 * @return Valor da compra
 */
    double totalItemsValue() const;

/**
 * @brief Retorna o tempo de saida do cliente
 *
 * @return Tempo de saida
 */
    int exitTime() const;

/**
 * @brief Atribui um valor para o tempo de saida
 *
 * @param exitTime tempo de saida
 */
    void setExitTime(int exitTime);

/**
 * @brief Retorna o tempo de chegada do cliente
 *
 * @return Tempo de chegada
 */
    int arrivalTime()const;

private:
    Payment* payment;
    CashierPreference* preference;
    int _totalItems;
    double _totalItemsValue;
    int _exitTime;
    int _arrivalTime;
};
}
#endif
