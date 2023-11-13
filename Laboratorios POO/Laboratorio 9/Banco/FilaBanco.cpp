#include "FilaBanco.hpp"
#include <iostream>

using namespace std;

FilaBanco::FilaBanco()
{
	head = NULL;
	tail = NULL;
}

FilaBanco::~FilaBanco()
{
	while (head != NULL)
	{
		ClienteBanco *temp = head;
		head = head->getNext();
		delete temp;
	}
}

bool FilaBanco::empty()
{
	return (head == NULL);
}

void FilaBanco::insert(bool prioridade, string NumeroDaConta, string agencia, string nome, string cpf)
{

	ClienteBanco *doc = new ClienteBanco(prioridade, NumeroDaConta, agencia, nome, cpf);

	if (empty())

	{
		head = doc;
		tail = doc;
		tail->setNext(NULL);
		cout << "Cliente adicionado com sucesso!0";
		return;
	}
	else
	{
		doc->setNext(head);
		head = doc;
		cout << "Cliente adicionado com sucesso!1";
	}
}

void FilaBanco::insertPriority(bool prioridade, string NumeroDaConta, string agencia, string nome, string cpf)
{

	ClienteBanco *c = new ClienteBanco(prioridade, NumeroDaConta, agencia, nome, cpf);

	if (empty())
	{

		head = c;
		tail = c;
		tail->setNext(NULL);

		cout << "Como nao tinha nenhum clinte na fila o cliente com prioridade foi adicionado no começo" << endl;
		return;
	}
	else if (tail->getPrioridade() == false)
	{

		tail->setNext(c);
		tail = c;
		tail->setNext(NULL);
		cout << "Nao tinha nenhum cliente prioritario entao este cliente esta no comeco da fila" << endl;
	}
	else
	{
		ClienteBanco *frente = head;
		ClienteBanco *tras;
		while (frente->getPrioridade() == false)
		{
			tras = frente;
			frente = frente->getNext();
		}

		tras->setNext(c);
		c->setNext(frente);
		cout << "Cliente prioritario adicionado atras de outro cliente prioritario" << endl;
	}
}

void FilaBanco::remove()
{

	if (empty())
	{

		cout << "Não ha clientes na fila." << endl;
		return;
	}
	else if (head->getNext() == NULL)
	{

		ClienteBanco *c = head;
		cout << "Cliente removido:" << endl;
		c->imprimirCliente();
		head = NULL;
		tail = NULL;
		delete c;

		return;
	}

	else
	{

		ClienteBanco *aux = head;
		ClienteBanco *aux1;
		while (aux->getNext() != NULL)
		{
			aux1 = aux;
			aux = aux->getNext();
		}

		cout << "Cliente removido:";
		aux->imprimirCliente();
		cout << endl;
		tail = aux1;
		tail->setNext(NULL);

		delete aux;
	}
}

void FilaBanco::printAllFiles()
{

	if (empty())
	{
		cout << "A fila esta vazia." << endl;
		return;
	}
	else
	{

		ClienteBanco *aux = head;
		while (aux != NULL)
		{

			aux->imprimirCliente();
			cout << "\n\n";
			aux = aux->getNext();
		}
	}
}