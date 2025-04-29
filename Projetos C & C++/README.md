📋 Projeto em C++: Gerenciamento de Contas Bancárias
Base principal:

Paradigma Orientado a Objetos (classes Conta, ContaPoupanca, ContaInvestimento, Cliente).

Aspecto transversal:

Tarifa de manutenção automática:
Toda vez que ocorrer saque ou depósito, calcular e aplicar uma tarifa específica para cada tipo de conta (sem misturar esse cálculo na lógica de saque/depósito diretamente, simulando a Programação Orientada a Aspectos).

✏️ Estrutura planejada:
Classes:

Cliente

Nome

Tipo de Cliente (PF/PJ)

Conta (classe base)

Tipo de Conta

Data de abertura

Saldo

Cliente (associação)

ContaPoupanca (herda de Conta)

Tarifa de manutenção diferente

ContaInvestimento (herda de Conta)

Tarifa de manutenção diferente

Operações:

sacar(double valor)

depositar(double valor)

Aspecto (simulado):

Antes de cada operação (sacar ou depositar), aplicar tarifa de manutenção proporcional ao tipo de conta.

🧩 Resumo do que aplicamos:
POO: usamos herança (Conta → ContaPoupanca e ContaInvestimento).

Aspecto transversal: o cálculo da tarifa de manutenção é externo à lógica principal de saque e depósito. Usamos a função aplicarTarifa, que age como um aspecto aplicado automaticamente antes das operações.

