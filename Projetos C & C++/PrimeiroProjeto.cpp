#include <iostream>
#include <string>

using namespace std;

// Aspecto Simulado: função para calcular tarifa
void aplicarTarifa(double& saldo, const string& tipoConta) {
    double tarifa = 0.0;
    if (tipoConta == "Poupanca") {
        tarifa = 5.00; // tarifa fixa para poupança
    } else if (tipoConta == "Investimento") {
        tarifa = 10.00; // tarifa fixa para investimento
    }
    saldo -= tarifa;
    cout << "Tarifa de manutenção aplicada: R$" << tarifa << endl;
}

// Classe Cliente
class Cliente {
private:
    string nome;
    string tipoCliente; // PF ou PJ

public:
    Cliente(const string& nome, const string& tipoCliente)
        : nome(nome), tipoCliente(tipoCliente) {}

    void exibirCliente() const {
        cout << "Cliente: " << nome << " (" << tipoCliente << ")" << endl;
    }
};

// Classe Base Conta
class Conta {
protected:
    string tipoConta;
    string dataAbertura;
    double saldo;
    Cliente* cliente;

public:
    Conta(const string& tipoConta, const string& dataAbertura, Cliente* cliente)
        : tipoConta(tipoConta), dataAbertura(dataAbertura), saldo(0.0), cliente(cliente) {}

    virtual void sacar(double valor) {
        aplicarTarifa(saldo, tipoConta); // Aspecto: aplicar tarifa antes da operação
        if (saldo >= valor) {
            saldo -= valor;
            cout << "Saque de R$" << valor << " realizado com sucesso." << endl;
        } else {
            cout << "Saldo insuficiente para saque." << endl;
        }
    }

    virtual void depositar(double valor) {
        aplicarTarifa(saldo, tipoConta); // Aspecto: aplicar tarifa antes da operação
        saldo += valor;
        cout << "Depósito de R$" << valor << " realizado com sucesso." << endl;
    }

    virtual void exibirDados() const {
        cliente->exibirCliente();
        cout << "Tipo de Conta: " << tipoConta << endl;
        cout << "Data de Abertura: " << dataAbertura << endl;
        cout << "Saldo Atual: R$" << saldo << endl;
    }
};

// Conta Poupança
class ContaPoupanca : public Conta {
public:
    ContaPoupanca(const string& dataAbertura, Cliente* cliente)
        : Conta("Poupanca", dataAbertura, cliente) {}
};

// Conta Investimento
class ContaInvestimento : public Conta {
public:
    ContaInvestimento(const string& dataAbertura, Cliente* cliente)
        : Conta("Investimento", dataAbertura, cliente) {}
};

int main() {
    // Criando cliente
    Cliente cliente1("Thiago", "PF");

    // Criando conta poupança
    ContaPoupanca cp("01/01/2024", &cliente1);

    cout << "\n--- Conta Poupança ---" << endl;
    cp.depositar(500.0);
    cp.sacar(100.0);
    cp.exibirDados();

    // Criando conta investimento
    Cliente cliente2("Empresa XYZ", "PJ");
    ContaInvestimento ci("05/01/2024", &cliente2);

    cout << "\n--- Conta Investimento ---" << endl;
    ci.depositar(1000.0);
    ci.sacar(200.0);
    ci.exibirDados();

    return 0;
}
