#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP
#include <iostream>
#include "Document.hpp"

using namespace std;

class Document
{

private:
    Document *next;
   static int contID;

    string fileName;

    int pageQuantity;

    int id;

public:
    int priority;

    Document();
    Document(int prioridade, int quantidadePaginas, string nome);
    Document(int prioridade, int quantidadePaginas, string nome, int id);

    Document *getNext();

    string getFileName();

    void setFileName(string fileName);
    void setPageQuantity(int pageQuantity);
    void setPriority(int priority);
    void setNext(Document *p);
    void printFile();
    bool changeDocument(string name, int quantity, int priority);
    int getID();

    int getPageQuantity();
    int getPriority();
};
#endif
