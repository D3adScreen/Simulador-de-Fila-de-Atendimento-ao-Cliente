 # Sistema de Atendimento em C++
 Simulador de um sistema de atendimento ao cliente com gestão de filas prioritárias (VIP e não VIP), desenvolvido em C++.
 
## 📌 Descrição

Este projeto implementa um sistema completo de gestão de filas inspirado num cenário real de atendimento, onde clientes podem ser atendidos com prioridade.

 O sistema permite:

* Gerir filas de clientes VIP e normais;
* Controlar o atendimento por prioridade;
* Manter histórico de clientes atendidos;
* Registar todas as ações realizadas;
* Consultar estatísticas do sistema;

## ⚙️ Funcionalidades
### 👥 Gestão de Clientes
#### Adicionar clientes com:
* ID automático
* Nome
* Idade
* Prioridade (VIP ou Normal)
  
### 🚀 Atendimento Inteligente
* Clientes VIP são atendidos primeiro
* Clientes normais são atendidos quando não há VIPs
### 🔄 Alteração de Prioridade
* Permite mudar um cliente de:
* Normal → VIP
* VIP → Normal
* Feito através do ID
### 📊 Consultas
#### Listar clientes:
* Em espera (VIP e Normal)
* Já atendidos
### 🧠 Histórico de Ações
#### Regista ações como:
* Cliente adicionado
* Cliente atendido
* Mudança de prioridade
### ⏪ Undo (Desfazer)
* Remove a última ação realizada
### 📈 Estatísticas
* Total de clientes atendidos
* Quantidade de VIPs atendidos
* Quantidade de clientes normais atendidos

## 🏗️ Estruturas de Dados Utilizadas

### O projeto utiliza várias Bibliotecas:

* ```queue``` → Filas de atendimento (VIP e Normal) (FIFO)
* ```stack``` → Histórico de ações (LIFO)
* ```list``` → Histórico de clientes atendidos

## 🧾 Menu do Programa
```ruby
1. Adicionar cliente
2. Atender cliente
3. Trocar prioridade
4. Consultar clientes
5. Histórico de ações
6. Apagar última ação
7. Estatísticas
8. Sair
```
## 🧠 Lógica do Sistema
### Cada cliente recebe um ID único automático
### Existem duas filas:
* VIP ```queue```
* Normal ```queue```
### O atendimento segue a regra:
* Atender VIPs primeiro
* Depois clientes normais
* O histórico de ações funciona como uma pilha ```stack```

## 💻 Exemplos de Código

### 🧩 Estruturas e Variáveis Principais
```ruby
struct Atendimento {
    string nome;       // Nome do cliente
    int idade;         // Idade do cliente
    string prioridade; // VIP ou Normal
    int id;            // ID único
};

int valor_id = 1;
int cont_vip = 0;
int cont_naovip = 0;
int trocar_id;

struct Acao {
    string descricao;
    string nome_cliente;
};

queue<Atendimento> fila_atender_clientes_naovip; // Fila Normal
queue<Atendimento> fila_vip;                     // Fila VIP
list<Atendimento> historico_clientes_atendidos;  // Histórico de atendidos
stack<Acao> historico_acoes;                     // Histórico de ações
```
### 👥 Adicionar Cliente às Filas
```ruby
Atendimento Novo_cliente;
Novo_cliente.id = valor_id++;

cout << "Nome: ";
getline(cin, Novo_cliente.nome);

cout << "Idade: ";
cin >> Novo_cliente.idade;

cout << "VIP? (S/N): ";
cin >> Novo_cliente.prioridade;

if (Novo_cliente.prioridade == "S" || Novo_cliente.prioridade == "s") {
    fila_vip.push(Novo_cliente);
    historico_acoes.push({ "Cliente VIP Adicionado", Novo_cliente.nome });
} else {
    fila_atender_clientes_naovip.push(Novo_cliente);
    historico_acoes.push({ "Cliente Normal Adicionado", Novo_cliente.nome });
}
```

### 🚀 Atendimento com Prioridade
```ruby
if (!fila_vip.empty()) {
    historico_clientes_atendidos.push_back(fila_vip.front());
    historico_acoes.push({ "Cliente VIP Atendido", fila_vip.front().nome });
    fila_vip.pop();
}
else if (!fila_atender_clientes_naovip.empty()) {
    historico_clientes_atendidos.push_back(fila_atender_clientes_naovip.front());
    historico_acoes.push({ "Cliente Normal Atendido", fila_atender_clientes_naovip.front().nome });
    fila_atender_clientes_naovip.pop();
}
```
### ⏪ Histórico de Ações (Stack)
```ruby
stack<Acao> pilha_altern = historico_acoes;

while (!pilha_altern.empty()) {
    cout << pilha_altern.top().descricao 
         << " -> " << pilha_altern.top().nome_cliente << endl;
    pilha_altern.pop();
}
```
