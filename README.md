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
```
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
