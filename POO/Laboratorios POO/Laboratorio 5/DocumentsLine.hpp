#ifndef DOCUMENTSLINE_HPP
#define DOCUMENTSLINE_HPP
#include <iostream>
#include "Document.hpp"

class DocumentsLine
{

private:
    Document *tail;

    Document *head;

public:

    DocumentsLine();
    virtual ~DocumentsLine();
    bool empty();

    bool check(int ID);

    int size();

    void insert(int prioriade, int qntPag, string name);
    void insertWithID(int prioriade, int qntPag, string name, int ID);
    

    void insertPriority();

    void moveDocument(int ID);

    void remove(int ID);

    void printAllFiles();


    void alterar(int ID);
};

#endif
