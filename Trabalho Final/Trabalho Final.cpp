// Trabalho Final.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <stdlib.h> //Biblioteca para Fazer o clear da Console
#include <cstdlib> //Biblioteca para Fechar a console
#include <iostream>
#include <stack> //Biblioteca Pilha para ver o historico de clientes atendidos
#include<string>
#include <list> //
#include <queue> //Biblioteca Fila para adicionar os clientes Vips e nao Vips ao Atendimento
#include<algorithm>
using namespace std;

int main()
{
	struct Atendimento
	{
		string nome; //Criar uma string para a variavel "nome" para o nome do Cliente
		int idade; //Criar um int para a variavel "idade" para a idade do Cliente
		string prioridade; //Criar uma string para a variavel "Prioridade" para ver se é VIP ou NAOVIP
		int id; //Criar um id para cada cliente
	};
	int valor_id = 1;
	int cont_vip = 0;
	int cont_naovip = 0;
	int trocar_id;
	struct Acao
	{
		string descricao;
		string nome_cliente;
	};
	queue<Atendimento>fila_atender_clientes_naovip; //Fila de Clientes Normais
	queue<Atendimento>fila_vip; //Fila de Clientes VIPs
	list<Atendimento>historico_clientes_atendidos; //Usar lista para o historico de clientes atendidos
	stack<Acao>historico_acoes; //Usar pilha para historico de todas as açoes
	while (true)
	{
		int opcao;
		cout << "--- Sistema de Atendimento Peixaria ---"<<endl; //Menu de Atendimento com as várias opcoes possiveis
		cout << "1. Adicionar cliente" << endl; //Adicionar Cliente as filas
		cout << "2. Atender cliente" << endl; //Atender cliente por ordem de prioridade e dps de chegada
		cout << "3. Trocar Prioridade" << endl; //Trocar Vip para Normal e vice Versa atraves do id (POR FAZER)
		cout << "4. Consultar Clientes Totais" << endl; //Mostrar Clientes atendidos e por atender
		cout << "5. Historico de Acoes" << endl; //Mostrar (x atendido, x adicioado, x movido para vip, x movido para normal)
		cout << "6. Apagar Ultima Acao" << endl;
		cout << "7. Estatisticas" << endl;
		cout << "8. Sair" << endl;
		cout << "--- Sistema de Atendimento Peixaria ---"<<endl;
		cout << "Escolha uma opcao: ";
		cin >> opcao;
		switch (opcao)
		{
		case(1): //1. Adicionar Cliente
		{
			system("cls");
			Atendimento Novo_cliente;
			Novo_cliente.id = valor_id;
			cout << "ID: " << valor_id << endl;
			valor_id++; //Acrescenta um id automaticamente para cada cliente para não haver iguais
			cout << "Qual o nome do Cliente: ";
			cin.ignore();  //Limpar o Buff
			getline(cin, Novo_cliente.nome); //Deixar que o Nome tenha dois "nomes" ex: Francisco Rodrigues
			cout << "Qual a idade do Cliente: ";
			cin >> Novo_cliente.idade;
			cout << "O cliente e VIP? S/N: ";
			cin >> Novo_cliente.prioridade;
			if ((Novo_cliente.prioridade) == "S"|| (Novo_cliente.prioridade)=="s") //Se a Prioridade for Vip Adiciona na Fila VIPS
			{
				fila_vip.push(Novo_cliente);
				historico_acoes.push({ "Cliente VIP Adicionado", Novo_cliente.nome });
				cout << "Cliente VIP Adicionado..." << endl;
				break;
			}
			else if ((Novo_cliente.prioridade) == "N"||(Novo_cliente.prioridade)=="n") //Se a Prioridade nao for Vip Adiciona na Fila Normal
			{
				historico_acoes.push({ "Cliente Normal Adicionado", Novo_cliente.nome }); //Adicionar o Nome do Cliente Adicionado à pilha
				fila_atender_clientes_naovip.push(Novo_cliente);
				cout << "Cliente Normal Adicionado..." << endl;
				break;
			}
			else
			{
				cout << "Valor Invalido!" << endl;
				break;
			}
		}
		case(2): //2. Atender Cliente
		{
			system("cls");
			if (fila_vip.empty() && fila_atender_clientes_naovip.empty()) //Se ambas as filas estao vazias nao tem clientes para atender
			{
				cout << "As filas estao Vazias!" << endl;
				break;
			}
			else
			{
				if (fila_vip.empty() == false) //A fila Normal está vazia e a Vip nao está ou seja atende o Vip Primeiro
				{
					cont_vip++;
					historico_clientes_atendidos.push_back(fila_vip.front()); //Adiciona o cliente a um historico de clientes atendidos por ordem de chegada(pilha)
					historico_acoes.push({ "Cliente VIP Atendido", fila_vip.front().nome });
					fila_vip.pop(); //Remove o cliente da Fila Vip
					cout << "Cliente VIP Atendido!" << endl;
				}
				else if (fila_vip.empty()&& (fila_atender_clientes_naovip.empty()==false)) //Se nao houver clientes vips serão atendidos os nao vips primeiro ate haver um vip
				{
					cont_naovip++;
					historico_clientes_atendidos.push_back(fila_atender_clientes_naovip.front()); //Adiciona o cliente a um historico de clientes atendidos por ordem de chegada(pilha)
					historico_acoes.push({ "Cliente Normal Atendido", fila_atender_clientes_naovip.front().nome });
					fila_atender_clientes_naovip.pop(); //Remove o cliente da Fila Normal
					cout << "Cliente Nao VIP Atendido!" << endl;
				}
				else //Se ambas as filas têm clientes os Vips sao atendidos primeiro ate ficar vazia
				{
					cont_vip++;
					historico_clientes_atendidos.push_back(fila_vip.front()); //Adiciona o cliente a um historico de clientes atendidos por ordem de chegada(pilha)
					historico_acoes.push({ "Cliente VIP Atendido", fila_vip.front().nome });
					fila_vip.pop(); //Remove o cliente da Fila Vip
					cout << "Cliente VIP Atendido!" << endl;
				}
			}
			break;
		}
		
		case(3):
		{
			system("cls");
			if (fila_vip.empty() && fila_atender_clientes_naovip.empty())
			{
				cout << "As filas estao vazias!" << endl;
				break;
			}
			else
			{
				// Transferir os elementos das filas para listas
				list<Atendimento> lista_atender_clientes_naovip, lista_vip;

				while (!fila_atender_clientes_naovip.empty())
				{
					lista_atender_clientes_naovip.push_back(fila_atender_clientes_naovip.front());
					fila_atender_clientes_naovip.pop();
				}
				while (!fila_vip.empty())
				{
					lista_vip.push_back(fila_vip.front());
					fila_vip.pop();
				}

				system("cls");
				cout << "Qual o ID que quer trocar a prioridade: ";
				cin >> trocar_id;

				// Procurar o cliente na lista de não VIPs
				auto it_naovip = find_if(lista_atender_clientes_naovip.begin(), lista_atender_clientes_naovip.end(), [&trocar_id](const Atendimento& a) {
					return (a.id == trocar_id);
					});
				if (it_naovip != lista_atender_clientes_naovip.end())
				{
					// Transferir cliente de não VIP para VIP
					historico_acoes.push({ "Prioridade Alterada para Vip", it_naovip->nome });
					lista_vip.push_back(*it_naovip);
					lista_atender_clientes_naovip.erase(it_naovip);
					cout << "Cliente movido para a fila VIP!" << endl;
				}
				else
				{
					// Procurar o cliente na lista de VIPs
					auto it_vip = find_if(lista_vip.begin(), lista_vip.end(), [&trocar_id](const Atendimento& b) {
						return (b.id == trocar_id);
						});
					if (it_vip != lista_vip.end())
					{
						// Transferir cliente de VIP para não VIP
						historico_acoes.push({ "Prioridade Alterada para Normal", it_vip->nome });
						lista_atender_clientes_naovip.push_back(*it_vip);
						lista_vip.erase(it_vip);
						cout << "Cliente movido para a fila Normal!" << endl;
					}
					else
					{
						cout << "ID não encontrado em nenhuma lista." << endl;
					}
				}

				// Transferir elementos de volta para as filas originais
				for (const auto& cliente : lista_atender_clientes_naovip) {
					fila_atender_clientes_naovip.push(cliente);
				}
				for (const auto& cliente : lista_vip) {
					fila_vip.push(cliente);
				}

				break;
			}
		}
		case(4): //Consulta de Clientes Totais
		{
			system("cls");
			cout << "\n------------------ CLIENTES NAO ATENDIDOS ------------------"; //Historico de Clientes nao Atendidos
			queue<Atendimento>fila_altern2 = fila_vip; 
			cout << "\n--- Fila de VIPs --- \n";
			for (int i = 0;i < fila_vip.size();i++)
			{
				cout << fila_altern2.front().id << "-> Nome:";
				cout << fila_altern2.front().nome << ", Idade:";
				cout << fila_altern2.front().idade << endl;
				fila_altern2.pop();
			}
			queue<Atendimento>fila_altern = fila_atender_clientes_naovip;
			cout << "\n--- Fila de Nao VIPs ---\n";
			for (int i = 0; i < fila_atender_clientes_naovip.size();i++)
			{
				cout << fila_altern.front().id << "->Nome:";
				cout << fila_altern.front().nome << ", Idade";
				cout << fila_altern.front().idade << endl;
				fila_altern.pop();
			}
			cout << "\n-------------------- CLIENTES ATENDIDOS --------------------" << endl;
			for (auto it = historico_clientes_atendidos.begin();it != historico_clientes_atendidos.end();it++)
			{
				cout << "Id:" << it->id << ", Nome:";
				cout << it->nome << endl;
			}

				break;
		}
		case(5):
		{
			system("cls");
			if (historico_acoes.empty())
			{
				cout << "Não existe um Historico de Acoes!" << endl;
				break;
			}
			else
			{
				cout << "\n-------------------- HISTORICO DE ACOES --------------------"<<endl;
				stack<Acao>pilha_altern2 = historico_acoes; //Criar uma pilha igual ao "historico de acoes porque vou apagando um elemento 1 a 1
				for (int i = 0;i < historico_acoes.size();i++)
				{
					cout << pilha_altern2.top().descricao << " ->Nome Cliente: ";
					cout<< pilha_altern2.top().nome_cliente << endl;
					pilha_altern2.pop();
				}
			}
			break;
		}
		case(6):
		{
			if (historico_acoes.empty() && historico_clientes_atendidos.empty()) //Verificar se o historico esta vazio ou não para nao dar erro de memória ao tentar apagar
			{                                                                   //algo que nao existe.
				cout << "Os Historicos estao vazios!" << endl;
			}
			else if(!historico_acoes.empty()&&!historico_clientes_atendidos.empty())
			{
				historico_acoes.pop();
				historico_clientes_atendidos.pop_back();
			}
			else if (historico_acoes.empty() && !historico_clientes_atendidos.empty())
			{
				historico_clientes_atendidos.pop_back();
			}
			else if (!historico_acoes.empty() && historico_clientes_atendidos.empty())
			{
				historico_acoes.pop();
			}
			break;
		}
		case(7):
		{
			system("cls");
			cout << "Numero de Clientes atendidos: "<<cont_vip+cont_naovip<<endl;
			cout << "Numero de Clientes Vips Atendidos: "<<cont_vip<<endl;
			cout << "Numero de Clientes Normais Atendidos: "<<cont_naovip << endl;
			break;
		}
		case(8):
		{
			system("cls");
			cout << "A fechar Programa!" << endl;
			return 0;
		}
		}
	}
}