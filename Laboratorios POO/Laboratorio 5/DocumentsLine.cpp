#include <iostream>
#include "DocumentsLine.hpp"
#include "Document.hpp"

DocumentsLine::DocumentsLine()
{

	head = NULL;
	tail = NULL;
	// tail->setNext(NULL);
}

DocumentsLine::~DocumentsLine()
{

	Document *atual = head;

	while (atual != NULL)
	{
		Document *temp = atual;
		atual = atual->getNext();
		delete temp;
	}
}

bool DocumentsLine::empty()
{

	return (head == NULL);
}

bool DocumentsLine::check(int ID)
{

	Document *no = head;

	if (empty())
	{
		cout << "\n\nA fila esta vazia!!\n\n";
	}
	else
	{

		while (no != NULL)

		{

			if (no->getID() == ID)

			{

				no->printFile();

				return true;
			}

			no = no->getNext();
		}

		cout << "O documento nao existe!!";

		return false;
	}
}

int size()
{

	return 0;
}

void DocumentsLine::insert(int prioridade, int qntPag, string name)
{

	Document *doc = new Document(prioridade, qntPag, name);

	if (empty())

	{
		head = doc;
		tail = doc;
		tail->setNext(NULL);
		cout << "Documento adicionado com sucesso!0";
		return;
	}

	else

	{

		if (head->getNext() == NULL) // se tiver somente um elemento
		{

			if ((head->priority) >= prioridade) // conferir se o elemento que ja existe tem uma prioridade maior
			{

				head->setNext(doc);

				doc->setNext(NULL);
				tail = doc;

				cout << "Documento adicionado com sucesso!1";
				return;
			}

			if ((head->priority) <= prioridade)

			{

				doc->setNext(head);

				head = doc;
                head->getNext()->setNext(NULL);
				cout << "Documento adicionado com sucesso!2";
				return;
			}
		}

		else if (head->getNext()->getNext() == NULL) // se tiver somente dois elementos

		{

			if ((head->priority) <= prioridade)

			{

				doc->setNext(head);

				head = doc;

				cout << "Documento adicionado com sucesso!3";
				return;
			}

			else if ((head->getNext()->priority) <= prioridade)

			{

				doc->setNext(head->getNext());

				head->setNext(doc);

				cout << "Documento adicionado com sucesso!4";
				return;
			}

			else if ((head->getNext()->priority) >= prioridade)

			{

				tail->setNext(doc);

				doc->setNext(NULL);

				tail = doc;

				cout << "Documento adicionado com sucesso!5";
				return;
			}
		}

		else // dois ou mais elementos

		{

			if ((head->priority) <= prioridade)

			{

				doc->setNext(head);

				head = doc;
			}
			else if ((head->getNext()->priority) <= prioridade)
			{

				doc->setNext(head->getNext());
				head->setNext(doc);
			}

			else

			{

				Document *aux = head;

				Document *aux1 = head->getNext();

				Document *aux2 = head->getNext()->getNext();

				while ((aux1->priority) > prioridade)

				{

					Document *ant = aux1;

					aux1 = aux2;

					aux = ant;

					aux2 = aux2->getNext();
				}

				doc->setNext(aux1);
				aux->setNext(doc);

				cout << "Documento adicionado com sucesso!6";
				return;
			}
		}
	}
}

void DocumentsLine::insertWithID(int prioridade, int qntPag, string name, int ID)
{

	Document *doc = new Document(prioridade, qntPag, name, ID);

	if (empty())

	{
		head = doc;
		tail = doc;
		tail->setNext(NULL);
		cout << "Documento adicionado com sucesso!0";
		return;
	}

	else

	{

		if (head->getNext() == NULL) // se tiver somente um elemento
		{

			if ((head->priority) >= prioridade) // conferir se o elemento que ja existe tem uma prioridade maior
			{

				head->setNext(doc);

				doc->setNext(NULL);
				tail = doc;

				cout << "Documento adicionado com sucesso!1";
				return;
			}

			if ((head->priority) <= prioridade)

			{

				doc->setNext(head);

				head = doc;

				cout << "Documento adicionado com sucesso!2";
				return;
			}
		}

		else if (head->getNext()->getNext() == NULL) // se tiver somente dois elementos

		{

			if ((head->priority) <= prioridade)

			{

				doc->setNext(head);

				head = doc;

				cout << "Documento adicionado com sucesso!3";
				return;
			}

			else if ((head->getNext()->priority) <= prioridade)

			{

				doc->setNext(head->getNext());

				head->setNext(doc);

				cout << "Documento adicionado com sucesso!4";
				return;
			}

			else if ((head->getNext()->priority) >= prioridade)

			{

				tail->setNext(doc);

				doc->setNext(NULL);

				tail = doc;

				cout << "Documento adicionado com sucesso!5";
				return;
			}
		}

		else // dois ou mais elementos

		{

			if ((head->priority) <= prioridade)

			{

				doc->setNext(head);

				head = doc;
			}
			else if ((head->getNext()->priority) <= prioridade)
			{

				doc->setNext(head->getNext());
				head->setNext(doc);
			}

			else

			{

				Document *aux = head;

				Document *aux1 = head->getNext();

				Document *aux2 = head->getNext()->getNext();

				while ((aux1->priority) > prioridade)

				{

					Document *ant = aux1;

					aux1 = aux2;

					aux = ant;

					aux2 = aux2->getNext();
				}

				doc->setNext(aux1);
				aux->setNext(doc);

				cout << "Documento adicionado com sucesso!6";
				return;
			}
		}
	}
}

void DocumentsLine::alterar(int ID)
{

	if (!empty())
	{

		if (check(ID))
		{

			string Nome;
			int qntPag;
			int prioridade;
			cout << "\nDigite o nome do arquivo:\n";
			cin >> Nome;
			cout << "\nQuantidade de paginas:\n";
			cin >> qntPag;
			do
			{
				cout << "\nPrioridade na fila(1-Maior prioridade, 3-Menor prioridade):\n";

				cin >> prioridade;
			} while (prioridade < 0 || prioridade > 3);

			remove(ID);
			insertWithID(prioridade, qntPag, Nome, ID);
		}
		else
		{

			cout << "\nNao existe nenhum documento com o este ID! \n";
		}
	}
	else
	{

		cout << "\nA lista esta vazia!\n";
	}
}

void DocumentsLine::remove(int ID)
{

	if (!empty())
	{
		if (check(ID))
		{

			if (head->getNext() == NULL) // 1 elemento
			{
				delete head; // Libera memória
				head = NULL;
				tail = NULL; // A cauda também deve ser atualizada
				//tail->setNext(NULL);
			}
			else if (head->getNext()->getNext() == NULL) // 2 elementos
			{
				if (head->getID() == ID)
				{

					delete head;
					head = tail;
				}
				else if (head->getNext()->getID() == ID)
				{

					delete tail;
					head->setNext(NULL);
					tail = head;
				}
			}
			else
			{

				if (head->getID() == ID)
				{
					Document *aux = head->getNext();
					delete head;
					head = aux;
				}
				else
				{

					Document *ant;
					Document *ant_ant = head;

					while (ant_ant->getID() != ID)
					{

						ant = ant_ant;
						ant_ant = ant_ant->getNext();
					}

					if (ant_ant->getNext() == NULL)
					{ // para quando o item a ser excluido for o primeiro da fila

						ant->setNext(nullptr);
						tail = ant;
						delete ant_ant;
					}
					else
					{

						ant->setNext(ant_ant->getNext());
						delete ant_ant;
					}
				}
			}
		}
		else
		{
			cout << "\n\nNao existe nenhum documento com o ID informado!\n\n";
		}
	}
	else
	{
		cout << " \n\nA lista esta vazia!!\n\n";
	}
}

void DocumentsLine::printAllFiles()
{

	Document *no = head;

	if (empty())

	{

		cout << "A lista esta vazia!!\n";
	}

	else

	{

		while (no != NULL)

		{

			no->printFile();

			no = no->getNext();
		}
	}
}
