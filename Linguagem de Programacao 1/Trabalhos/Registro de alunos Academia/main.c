// ARQUIVO:      trabalho2_p2
// T�TULO:       Problema 2
// ENVIADO POR:  Igor Fiedler de Bastos e Matheus Demetrio Vieira
// CURSO:        Linguagem de Programa��o 1
// DATA:         16 de Novembro de 2023
//
// PROP�SITO:
// Este programa gerencia o cadastro de alunos em uma academia. Ele permite que
// os usu�rios realizem opera��es como cadastro, listagem, exclus�o e atualiza��o
// de dados dos alunos. Os dados dos alunos s�o armazenados na estrutura 'CadastroAlunos',
// e as opera��es s�o realizadas por meio de um menu interativo.
//
// FUN��ES:
//
// menu
//
//  Esta fun��o apresenta um menu na tela que permite ao usu�rio escolher entre v�rias
//  opera��es relacionadas ao cadastro de alunos na academia.
//
// cadastrar
//
//  Esta fun��o guia o usu�rio por um processo de cadastro, solicitando informa��es
//  como nome, e-mail, sexo, peso e altura do novo aluno.
//
// listar
//  Esta fun��o lista todos os alunos matriculados.
//
// excluir
//  Esta fun��o exclui a matr�cula do aluno escolhido.
//
// alterar
//  Esta fun��o altera os dados do aluno escolhido.
//
// MostrarAluno
//  Esta fun��o mostra as informa��es de determinado aluno na tela.
//
// verificaMatricula
//  Esta fun��o verifica se tem algum aluno cadastrado.
//
// salvarDados
//  Esta fun��o salva os dados do programa.
//
// carregarDados
//  Esta fun��o carrega os dados do programa.
//
// ARQUIVOS INCLU�DOS:
//  stdio.h
//  stdlib.h
//  string.h
//  locale.h
//
// ARQUIVOS DE DADOS:
//  alunos.txt


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define MAX_ALUNOS 50
#define ARQUIVO_ALUNOS "alunos.txt"


struct CadastroAlunos {
    char nome[50];
    char email[50];
    char sexo;
    int matricula;
    float peso;
    float altura;
    float imc;
    int ativo;

};

struct CadastroAlunos alunos[MAX_ALUNOS];


// nome DA FUN��O: menu
// PROP�SITO:
//  A fun��o apresenta um menu na tela que permite ao usu�rio escolher entre v�rias
//  opera��es relacionadas ao cadastro de alunos na academia. As op��es incluem cadastrar
//  um novo aluno, listar todos os alunos cadastrados, excluir um aluno existente,
//  atualizar dados de um aluno e sair do programa.
//
//  O usu�rio pode fazer a sele��o digitando o n�mero correspondente � op��o desejada.
//  Cada op��o chama uma fun��o espec�fica para realizar a opera��o escolhida.
//
//  A fun��o continua exibindo o menu at� que o usu�rio escolha a op��o de sair (op��o 0).
//  Durante a execu��o, o programa limpa a tela do console para proporcionar uma experi�ncia
//  de usu�rio mais limpa e organizada.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA:
//  cadastrar
//  listar
//  excluir
//  alterar
// M�TODO: A seguir est� o pseudoc�digo que descreve como a fun��o funciona.
//  1. limpa o terminal
//  2. Imprime o menu.
//  3. solicita ao usu�rio a op��o.

void menu(){

    int op;

    do {

        system("cls");

        printf("\n  #--------------------------   CADASTRO DE ALUNOS   --------------------------#");
        printf("\n  |                                                                            |");
        printf("\n  |                                                                            |");
        printf("\n  |                                                                            |");
        printf("\n  |                               MENU PRINCIPAL                               |");
        printf("\n  |                                                                            |");
        printf("\n  |           1 - CADASTRAR                                                    |");
        printf("\n  |           2 - LISTAR                                                       |");
        printf("\n  |           3 - EXCLUIR                                                      |");
        printf("\n  |           4 - ATUALIZAR DADOS                                              |");
        printf("\n  |           0 - SAIR                                                         |");
        printf("\n  |                                                                            |");
        printf("\n  |                                                                            |");
        printf("\n  |       Programador:                                                         |");
        printf("\n  |             Igor de Bastos  &  Matheus Vieira                              |");
        printf("\n  |                                                                            |");
        printf("\n  |                                                                            |");
        printf("\n  #____________________________________________________________________________#");

        printf("\n\n  Escolha uma Op��o: ");
        scanf("%i", &op);

        switch (op){
        case 1:
            cadastrar();
            break;
        case 2:
            listar();
            break;
        case 3:
            excluir();
            break;
        case 4:
            alterar();
            break;
        default:
            op = 0;
            break;
        }
    } while (op != 0);
}


// nome DA FUN��O: cadastrar
// PROP�SITO:
//  Esta fun��o guia o usu�rio por um processo de cadastro, solicitando informa��es
//  como nome, e-mail, sexo, peso e altura do novo aluno na academia. O c�lculo do
//  �ndice de Massa Corporal (IMC) � realizado automaticamente com base no peso e
//  altura fornecidos. O usu�rio tem a op��o de refazer o cadastro ou confirmar
//  os dados inseridos.
//
//  Se o usu�rio optar por confirmar, a fun��o procura por uma posi��o dispon�vel no
//  array de alunos e armazena os dados do novo aluno nessa posi��o. A matr�cula do aluno
//  � atribu�da automaticamente com base na posi��o no array.
//
//  O processo de cadastro � repetido enquanto o usu�rio optar por refazer o cadastro.
//  Ap�s a conclus�o, o usu�rio � redirecionado de volta ao menu principal
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// M�TODO: A seguir est� o pseudoc�digo que descreve como a fun��o funciona.
//  1. limpa o terminal e imprime o cabe�alho
//  2. Solicita os dados esperado para o usu�rio.
//  3. Solicita ao usu�rio a confirma��o dos dados.
//  4. Guarda os dados regitrados pelo usu�rio no array alunos.

void cadastrar(){

    char nome[50];
    char email[50];
    char sexo;
    int matricula;
    float peso;
    float altura;
    float imc;
    int ativo;
    int opt;



    do {

        system("cls");

        printf("\n  #----------------------------------------------------------------------------#");
        printf("\n  |                                   CADASTRO                                 |");
        printf("\n  #----------------------------------------------------------------------------#");
        printf("\n\n Nome: ");
        getchar();
        fgets(nome, sizeof(nome), stdin);
        fflush(stdin);

        printf("\n E-mail: ");
        fgets(email, sizeof(email), stdin);
        fflush(stdin);

        printf("\n Sexo [M|F]: ");
        scanf("%c", &sexo);
        fflush(stdin);

        if (sexo != 'M' && sexo != 'F'){
            printf("\n Sexo inv�lido. Digite M para masculino ou F para feminino.\n");
            getch();
            continue;
        }

        printf("\n Peso [kg] (use v�rgula como separador decimal): ");
        scanf("%f", &peso);
        fflush(stdin);


        printf("\n Altura [m] (use v�rgula como separador decimal): ");
        scanf("%f", &altura);
        fflush(stdin);

        imc = peso / (altura * altura);


        printf("\n  #----------------------------------------#");
        printf("\n  |  1 - Refazer cadastro | 0 - confirmar  |");
        printf("\n  #----------------------------------------#");
        printf("\n\n   -> ");
        scanf("%i", &opt);

        if (opt == 0){
            for (int i = 0; i < MAX_ALUNOS; i++){
                    if (alunos[i].ativo == 0){
                    strcpy(alunos[i].nome, nome);
                    strcpy(alunos[i].email, email);
                    alunos[i].matricula = i;
                    alunos[i].sexo = sexo;
                    alunos[i].peso = peso;
                    alunos[i].altura = altura;
                    alunos[i].imc = imc;
                    alunos[i].ativo = 1;
                    break;
                }
            }
        }


    } while (opt != 0);

}

// nome DA FUN��O: listar
// PROP�SITO:
//  A fun��o verifica se h� alunos cadastrados. Se existirem, ela utiliza a fun��o
//  MostrarAluno para exibir as informa��es detalhadas de cada aluno ativo, incluindo
//  matr�cula, nome, e-mail, peso, altura e �ndice de Massa Corporal (IMC).
//
//  Se n�o houver alunos cadastrados, uma mensagem informando a aus�ncia de alunos �
//  exibida na tela. A fun��o aguarda a intera��o do usu�rio antes de retornar ao menu
//  principal.
//
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA:
//  MostrarAluno
//  verificaMatricula
//
// M�TODO: A seguir est� o pseudoc�digo que descreve como a fun��o funciona.
//  1. limpa o terminal e imprime o cabe�alho
//  2. Verifica se tem algum aluno matriculado.
//  3. Caso exista alunos matriculados imprime uma lista com todos os alunos e suas informa��es.

void listar(){


    system("cls");
    printf("\n  #----------------------------------------------------------------------------#");
    printf("\n  |                             LISTA DE ALUNOS                                |");
    printf("\n  #----------------------------------------------------------------------------#");

    printf("\n\n");

    if (verificaMatricula() == 0){

        system("cls");
        printf("\n  #----------------------------------------#");
        printf("\n  |    N�O EXISTEM ALUNOS MATRICULADOS     |");
        printf("\n  #----------------------------------------# \n\n");
        getch();

    } else {

        for (int i = 0; i < MAX_ALUNOS; i++){
                if (alunos[i].ativo == 1){
                    MostrarAluno(i);
                    printf("--------------------------------------");
                }
        }
        getch();
    }


}

// nome DA FUN��O: excluir
// PROP�SITO:
//  A fun��o verifica se h� alunos cadastrados. Se existirem, exibe uma lista numerada de
//  alunos ativos com suas matr�culas. O usu�rio � solicitado a digitar o n�mero da matr�cula
//  do aluno que deseja excluir.
//
//  Ap�s a escolha, a fun��o exibe as informa��es detalhadas do aluno selecionado e solicita
//  a confirma��o do usu�rio para prosseguir com a exclus�o. Se confirmado, o aluno � marcado
//  como inativo no array de alunos.
//
//  Se n�o houver alunos cadastrados, uma mensagem informando a aus�ncia de alunos � exibida
//  na tela. A fun��o aguarda a intera��o do usu�rio antes de retornar ao menu principal.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA:
//  MostrarAluno
//
// M�TODO: A seguir est� o pseudoc�digo que descreve como a fun��o funciona.
//  1. limpa o terminal
//  2. verificar se tem algum aluno cadastrado
//  3. Caso tenha alunos cadastrados exibir a lista de todos os alunos cadastrados.
//  4. solicitar para o us�ario o n�mero de matr�cula a ser excluido
//  5. confirmar a exclus�o do aluno.
//  6. excluir aluno.


void excluir(){



    if (verificaMatricula() == 0){
        system("cls");
        printf("\n  #----------------------------------------#");
        printf("\n  |    N�O EXISTEM ALUNOS MATRICULADOS     |");
        printf("\n  #----------------------------------------# \n\n");
        getch();
    } else {
        int aldelet, op;

        system("cls");

        printf("\n  #----------------------------------------------------------------------------#");
        printf("\n  |                                EXCLUIR                                     |");
        printf("\n  #----------------------------------------------------------------------------#");

        for (int i = 0; i < MAX_ALUNOS; i++){
            if (alunos[i].ativo == 1){
                MostrarAluno(i);
            }
        }

        printf("\n\n\nDIGITE O N�MERO DE MATR�CULA DO ALUNO QUE VOC� DESEJA EXCLUIR: ");
        scanf("%i",&aldelet);

        system("cls");

        printf("\n  #----------------------------------------------------------------------------#");
        printf("\n  |                                EXCLUIR                                     |");
        printf("\n  #----------------------------------------------------------------------------#");

        MostrarAluno(aldelet);


        printf("\n  #---------------------------------------------#");
        printf("\n  |           1 - VOLTAR | 0 - EXCLUIR          |");
        printf("\n  #---------------------------------------------# \n\n");
        printf("\n\n   -> ");
        scanf("%i", &op);

        if (op == 0){
            alunos[aldelet].ativo = 0;
            system("cls");
            printf("\n  #----------------------------------------#");
            printf("\n  |       ALUNO EXCLU�DO COM SUCESSO       |");
            printf("\n  #----------------------------------------# \n\n");
            getch();


        }


    }


}

// nome DA FUN��O: alterar
// PROP�SITO:
//  A fun��o verifica se h� alunos cadastrados. Se existirem, exibe uma lista numerada de alunos
//  ativos com suas matr�culas. O usu�rio � solicitado a digitar o n�mero da matr�cula do aluno
//  que deseja atualizar.
//
//  Ap�s a escolha, a fun��o exibe as informa��es detalhadas do aluno selecionado e permite ao
//  usu�rio inserir os novos dados. O IMC � recalculado automaticamente com base no peso e altura
//  fornecidos.
//
//  O usu�rio tem a op��o de refazer o processo de atualiza��o ou confirmar as altera��es. Se
//  confirmado, os dados do aluno s�o atualizados no array de alunos.
//
//  Se n�o houver alunos cadastrados, uma mensagem informando a aus�ncia de alunos � exibida
//  na tela. A fun��o aguarda a intera��o do usu�rio antes de retornar ao menu principal.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA:
//  verificaMatricula
//  MostrarAluno
//
// M�TODO: A seguir est� o pseudoc�digo que descreve como a fun��o funciona.
//  1. Declara��o dos par�metros
//  2. verifica se existem alunos cadastrados.
//  3. Caso exista mostra as informa��es de todos alunos cadastrados na tela.
//  4. Solicita ao usu�rio o n�mero de matr�cula que ele deseja atualizar.
//  5. Mostra ao usu�rio o aluno que ele escolheu e pede confirma��o para atualizar.
//  6. Solicita os dados para atualizar o cadastro.
//  7. Solicita a confirma��o dos dados atualizados.
//  8. Atualiza os dados.


void alterar(){

    int ataluno, op;
    char nome[50];
    char email[50];
    char sexo;
    float peso;
    float altura;
    float imc;


    if (verificaMatricula() == 0){
        system("cls");
        printf("\n  #----------------------------------------#");
        printf("\n  |    N�O EXISTEM ALUNOS MATR�CULADOS     |");
        printf("\n  #----------------------------------------# \n\n");
        getch();

    } else {
        system("cls");

        printf("\n  #----------------------------------------------------------------------------#");
        printf("\n  |                              ATUALIZAR DADOS                               |");
        printf("\n  #----------------------------------------------------------------------------#");

         for (int i = 0; i < MAX_ALUNOS; i++){
                if (alunos[i].ativo == 1){
                    MostrarAluno(i);
                }
            }

        printf("\n\n\nDIGITE O N�MERO DA MATR�CULA QUE VOC� DESEJA ATUALIZAR: ");
        scanf("%i", &ataluno);


        system("cls");

        printf("\n  #----------------------------------------------------------------------------#");
        printf("\n  |                              ATUALIZAR DADOS                               |");
        printf("\n  #----------------------------------------------------------------------------#");

        MostrarAluno(ataluno);

        printf("\n\n  #---------------------------------------------#");
        printf("\n  |         1 - VOLTAR | 0 - ATUALIZAR          |");
        printf("\n  #---------------------------------------------# \n\n");
        printf("\n\n   -> ");
        scanf("%i", &op);

        if (op == 0){

            do {
                system("cls");

                printf("\n  #----------------------------------------------------------------------------#");
                printf("\n  |                              ATUALIZAR DADOS                               |");
                printf("\n  #----------------------------------------------------------------------------#");

                printf("\n\n Nome: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                fflush(stdin);

                printf("\n E-mail: ");
                fgets(email, sizeof(email), stdin);
                fflush(stdin);

                printf("\n Sexo [M|F]: ");
                scanf("%c", &sexo);
                fflush(stdin);

                if (sexo != 'M' && sexo != 'F'){
                    printf("\n Sexo inv�lido. Digite M para masculino ou F para feminino.\n");
                    getch();
                    continue;
                }

                printf("\n Peso [kg] (use v�rgula como separador decimal): ");
                scanf("%f", &peso);
                fflush(stdin);


                printf("\n Altura [m] (use v�rgula como separador decimal): ");
                scanf("%f", &altura);
                fflush(stdin);

                imc = peso / (altura * altura);

                printf("\n  #----------------------------------------#");
                printf("\n  |       1 - Refazer | 0 - confirmar      |");
                printf("\n  #----------------------------------------#");
                printf("\n\n   -> ");
                scanf("%i", &op);

                if (op == 0){
                    strcpy(alunos[ataluno].nome, nome);
                    strcpy(alunos[ataluno].email, email);
                    alunos[ataluno].peso = peso;
                    alunos[ataluno].altura = altura;
                    alunos[ataluno].imc = imc;
                    system("cls");
                    printf("\n  #----------------------------------------#");
                    printf("\n  |          MATR�CULA ATUALIZADA          |");
                    printf("\n  #----------------------------------------# \n\n");
                    getch();
                }

            } while(op != 0);


        }

    }

}

// nome DA FUN��O: MostrarAluno
// PROP�SITO:
//  A fun��o recebe o �ndice de um aluno no array de alunos e exibe suas informa��es formatadas
//  na tela. As informa��es exibidas incluem a matr�cula, o nome, o e-mail, o peso, a altura e o IMC.
//
// nome         tipo     valor/refer�ncia   descri��o
// ---------------------------------------------------------------------------
// i            int       valor              �ndice do aluno no array
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// M�TODO: A seguir est� o pseudoc�digo que descreve como a fun��o funciona.
//  1. exibe na tela as informa��es que compoem a estrutura CadastroAlunos.


void MostrarAluno(int i){

    printf("\n\n                MATR�CULA: %i \n",alunos[i].matricula);
    printf("\n\n-> NOME: %s",alunos[i].nome);
    printf("\n-> E-MAIL: %s",alunos[i].email);
    printf("\n-> SEXO: %c",alunos[i].sexo);
    printf("\n\n-> PESO: %.2fKg",alunos[i].peso);
    printf("\n\n-> ALTURA: %.2fm",alunos[i].altura);
    printf("\n\n-> IMC: %.2f\n\n",alunos[i].imc);


}

// nome DA FUN��O: verificaMatricula
// PROP�SITO:
//  A fun��o percorre o array de alunos e conta o n�mero de alunos ativos, marcados com o status 1.
//  O resultado � o n�mero total de alunos ativos na academia.
//
// Retorno:
// nome         tipo   descri��o
// -------------------------------------
// ativos       int    n�mero de alunos ativos
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// M�TODO: A seguir est� o pseudoc�digo que descreve como a fun��o funciona.
//  1. Declara��o e inicializa��o da vari�vel ativos
//  2. Loop que passa por todos os alunos matriculados dentro do array alunos e verifica se ele est� ativo
//  3. Caso ele esteja ativo a variav�l ativos � incrementada em um.
//  4. Retorna a vari�vel ativos com o n�mero de cadastros ativos.

int verificaMatricula(){
    int ativos = 0;

    for (int i = 0; i < MAX_ALUNOS; i++){
        if (alunos[i].ativo == 1){
            ativos++;
        }
    }
    return ativos;
}

// Fun��o: salvarDados
// Prop�sito:
//  Esta fun��o salva os dados dos alunos em um arquivo, permitindo a persist�ncia das informa��es
//  entre execu��es do programa. Os dados salvos incluem nome, e-mail, sexo, matr�cula, peso, altura,
//  IMC e status de atividade.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// M�TODO: A seguir est� o pseudoc�digo que descreve como a fun��o funciona.
//  1. Abrir o arquivo "alunos.txt" em modo de escrita
//  2. Se o arquivo n�o puder ser aberto, exibir uma mensagem de erro e encerrar o programa
//  3. Para cada aluno no array de alunos:
//  4. verificar se o aluno est� ativo
//  5. Formatar os dados do aluno (nome, e-mail, sexo, matr�cula, peso, altura, IMC, status) em uma string
//  6. Escrever a string formatada no arquivo, seguida de uma quebra de linha
//  7. Fechar o arquivo

void salvarDados() {

    FILE *arquivo = fopen(ARQUIVO_ALUNOS, "w");


    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ativo == 1) {
            fprintf(arquivo, "%s;%s;%c;%d;%.2f;%.2f;%.2f;%d\n",
                    alunos[i].nome, alunos[i].email, alunos[i].sexo,
                    alunos[i].matricula, alunos[i].peso, alunos[i].altura,
                    alunos[i].imc, alunos[i].ativo);
        }
    }

    fclose(arquivo);
}

// Fun��o: carregarDados
// Prop�sito:
//    Esta fun��o carrega os dados dos alunos a partir de um arquivo, permitindo a inicializa��o
//    do programa com informa��es previamente salvas. Os dados incluem nome, e-mail, sexo, matr�cula,
//    peso, altura, IMC e status de atividade.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// M�TODO: A seguir est� o pseudoc�digo que descreve como a fun��o funciona.
//  1. Fun��o carregarDados:
//  2. Abrir o arquivo "alunos.txt" em modo de leitura
//  3. Se o arquivo n�o puder ser aberto, exibir uma mensagem de erro e encerrar o programa
//  4. Ler e atribuir os dados da linha aos campos correspondentes do aluno no array de alunos
//  5. Fechar o arquivo

void carregarDados() {

    FILE *arquivo = fopen(ARQUIVO_ALUNOS, "r");
    if (arquivo == NULL) {
        FILE *arquivo = fopen(ARQUIVO_ALUNOS, "w");
    }

    for (int i = 0; i < MAX_ALUNOS; i++) {

        fscanf(arquivo, "%49[^;];", alunos[i].nome);
        fscanf(arquivo, "%49[^;];", alunos[i].email);
        fscanf(arquivo, "%c;", &alunos[i].sexo);
        fscanf(arquivo, "%d;", &alunos[i].matricula);
        fscanf(arquivo, "%f;", &alunos[i].peso);
        fscanf(arquivo, "%f;", &alunos[i].altura);
        fscanf(arquivo, "%f;", &alunos[i].imc);
        fscanf(arquivo, "%d\n", &alunos[i].ativo);
    }

    fclose(arquivo);
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    carregarDados();

    menu();

    salvarDados();

    return 0;

}
