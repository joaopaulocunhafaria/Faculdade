#include <iostream>
#include "Document.hpp"
#include "DocumentsLine.hpp"

int Document::contID = 0;

string Document::getFileName()
{
    return this->fileName;
}

void Document::setFileName(string filename)
{

    this->fileName = filename;
}

int Document::getPageQuantity()
{
    return this->pageQuantity;
}

void Document::setPageQuantity(int pageQuantity)
{
    this->pageQuantity = pageQuantity;
}

int Document::getPriority()
{
    return priority;
}

void Document::setPriority(int priority)
{
    this->priority = priority;
}

Document *Document::getNext()
{
    return next;
}

bool Document::changeDocument(string name, int quantity, int priority)
{

    bool move = false;

    if (this->priority != priority)
    {
        move = true;
    }

    this->fileName = name;
    this->pageQuantity = quantity;

    this->priority = priority;

    if (move)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Document::setNext(Document *p)
{

    this->next = p;
}

void Document::printFile()
{
    cout << "\n\nID:" << this->id;
    cout << "\nFile name:" << this->fileName;
    cout << "\nQuantidade de paginas:" << this->pageQuantity;
    cout << "\nNivel de prioridades:" << this->priority << "\n";
}

Document::Document(int prioridade, int quantidadePaginas, string nome)
{

    this->priority = prioridade;
    this->pageQuantity = quantidadePaginas;
    this->fileName = nome;
    this->contID++;
    this->id = contID;
}

Document::Document(int prioridade, int quantidadePaginas, string nome, int id)
{

    this->priority = prioridade;
    this->pageQuantity = quantidadePaginas;
    this->fileName = nome;
    this->id = id;

}


int Document::getID()
{

    return id;
}