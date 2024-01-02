#include "Curso.hpp"
#include "Disciplina.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Metodos.hpp"

int main()
{
    Metodos m;
    string nomeCurso;
    cout << "Nome do Curso:";
    getline(cin, nomeCurso);
    Curso curso(nomeCurso);

    while (true)
    {

        string aux;

        cout << "1 Cadastrar Professor" << endl;
        cout << "2 Cadastrar Aluno" << endl;
        cout << "3 Cadastrar Discplina" << endl;
        cout << "4 Imprimir lista de professores" << endl;
        cout << "5 Imprimir lista de alunos" << endl;
        cout << "6 Imprimir lista de Disciplinas" << endl;
        cout << "7 Sair" << endl;

        getline(cin, aux);
        char opcao = aux[0];
        switch (opcao)
        {
        case '1':
        {
            string nome = m.PedirNome();
            string endereco = m.PedirEndereco();
            string titulacao = m.PedirTitulacao();
            string cursoProfessor = m.PedirCurso();

            Professor p(titulacao, cursoProfessor, nome, endereco);

            curso.CadastrarProfessor(p);
        }
        break;

        case '2':
        {

            string nome = m.PedirNome();
            string endereco = m.PedirEndereco();
            int matricula = m.PedirMatricula();

            Aluno a(matricula, nome, endereco);
            curso.CadastrarAluno(a);
        }
        break;
        case '3':
        {

            string op;
            string nomeDisciplina = m.PedirNome();
            int ch = m.PedirCh();
            cout << "Professro da disciplina" << endl;
            cout << "Vincular Professor existente(S?/N)" << endl;

            char aux = getchar();

            if (aux == 'S')
            {
                getchar();
                string nomeProfesso = m.PedirNome();
                if (curso.vincularProfessor(nomeProfesso))
                {
                }
                else
                {
                    cout << "Nao ha nenhum professor cadastrado com este nome!" << endl;
                    break;
                }

                Professor P = curso.getProfessores(nomeProfesso);

                Disciplina D(nomeDisciplina, ch, P);
                curso.CadastrarDisciplina(D);
                break;
            }
            else if (aux == 'N')
            {
                getchar();
                string nomeProfessor = m.PedirNome();
                string endereco = m.PedirEndereco();
                string titulacao = m.PedirTitulacao();
                string cursoProfessor = m.PedirCurso();

                Professor p(titulacao, cursoProfessor, nomeProfessor, endereco);
                curso.CadastrarProfessor(p);
                Disciplina d(nomeDisciplina, ch, p);
                curso.CadastrarDisciplina(d);
                break;
            }
        }

        break;
        case '4':
        {

            curso.ImprimirListaDeProfessor();
        }
        break;

        case '5':
        {
            curso.ImprimirListaDeAlunos();
        }
        break;
        case '6':
        {

            curso.ImprimirListaDeDisciplina();
        }

        break;
        case '7':

        { 
            curso.~Curso();
            cout << "Saindo" << endl;

            return 0;
        }
        break;

        default:
            cout << "Opçao invalida! " << endl;
            break;
        }
    }

    return 0;
}