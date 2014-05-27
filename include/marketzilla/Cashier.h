#ifndef _Cashier_h_
#define _Cashier_h_

#include <string>

#include "dataStructures/Queue.h"

#include "Client.h"

using dataStructures::Queue;

namespace marketzilla {

class Cashier {
public:

/**
 * @brief Constroi o caixa com seu nome, salario e eficiencia
 *
 * @param name Nome do caixa
 * @param salary salario do caixa
 * @param eficiency eficiencia do caixa
*/
    Cashier(const std::string& name, double salary, int eficiency);

    Cashier();

/**
 * @brief Retorna o nome do caixa
 *
 * @return O nome do caixa
 */
    std::string attendantName() const;

/**
 * @brief Retorna salario do caixa
 *
 * @return Salario caixa
 */
    double attendantSalary() const;

/**
 * @brief Retorna eficiencia do caixa
 *
 * @return Eficiencia do caixa
 */
     int attendantEficiency() const;

/**
 * @brief Retorna numero de clientes atendidos
 *
 * @return Clientes servidos
 */
    int clientsServed() const;

/**
 * @brief Retorna total de tempo de espera dividido pelo numero de clientes atendidos
 *
 * @return Média de tempo de espera
 */
    double averageWaitingTime() const;

/**
 * @brief Retorna o faturamento do caixa
 *
 * @return Faturamento total
 */
    double totalProfit() const;

/**
 * @brief Retorna o faturamento do cliente divido pelo numero de clientes atendidos
 *
 * @return Faturamento médio
 */
    double averageProfit() const;

/**
 * @brief Retorna total de itens na fila do caixa
 */
     int queueItems() const;

/**
 * @brief Retorna comprimento da fila do caixa
 */
    int queueLength() const;

/**
 * @brief Adiciona um cliente na fila
 *
 * @details Adiciona um cliente na fila e define seu tempo de saída a partir da eficiencia do caixa e a forma de pagamento
 *
 * @param client Recebe a referencia de um cliente para adiciona-lo na fila
 */
    void enterQueue(Client& client);

/**
 * @brief Atualiza o caixa e sua fila
 *
 * @details Se fila estiver vazia nao faz nada, senao ve se o tempo de saida do cliente é o tempo atual 
 *aumenta e diminui os atributos necessarios e retira o cliente da fila
 *
 * @param currentTime Recebe o tempo atual da simulação
 */
    void update(int currentTime);

private:
    std::string _name;
    double _salary;
    int _eficiency;

    Queue<Client> _queue;
    int _queueItems;
    int _servedClients;
    double _totalProfit;
    int totalWaitingTime;
};

}

#endif