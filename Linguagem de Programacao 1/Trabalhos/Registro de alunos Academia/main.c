// ARQUIVO:      trabalho2_p2
// TÍTULO:       Problema 2
// ENVIADO POR:  Igor Fiedler de Bastos e Matheus Demetrio Vieira
// CURSO:        Linguagem de Programação 1
// DATA:         16 de Novembro de 2023
//
// PROPÓSITO:
// Este programa gerencia o cadastro de alunos em uma academia. Ele permite que
// os usuários realizem operações como cadastro, listagem, exclusão e atualização
// de dados dos alunos. Os dados dos alunos são armazenados na estrutura 'CadastroAlunos',
// e as operações são realizadas por meio de um menu interativo.
//
// FUNÇÕES:
//
// menu
//
//  Esta função apresenta um menu na tela que permite ao usuário escolher entre várias
//  operações relacionadas ao cadastro de alunos na academia.
//
// cadastrar
//
//  Esta função guia o usuário por um processo de cadastro, solicitando informações
//  como nome, e-mail, sexo, peso e altura do novo aluno.
//
// listar
//  Esta função lista todos os alunos matriculados.
//
// excluir
//  Esta função exclui a matrícula do aluno escolhido.
//
// alterar
//  Esta função altera os dados do aluno escolhido.
//
// MostrarAluno
//  Esta função mostra as informações de determinado aluno na tela.
//
// verificaMatricula
//  Esta função verifica se tem algum aluno cadastrado.
//
// salvarDados
//  Esta função salva os dados do programa.
//
// carregarDados
//  Esta função carrega os dados do programa.
//
// ARQUIVOS INCLUÍDOS:
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


// nome DA FUNÇÃO: menu
// PROPÓSITO:
//  A função apresenta um menu na tela que permite ao usuário escolher entre várias
//  operações relacionadas ao cadastro de alunos na academia. As opções incluem cadastrar
//  um novo aluno, listar todos os alunos cadastrados, excluir um aluno existente,
//  atualizar dados de um aluno e sair do programa.
//
//  O usuário pode fazer a seleção digitando o número correspondente à opção desejada.
//  Cada opção chama uma função específica para realizar a operação escolhida.
//
//  A função continua exibindo o menu até que o usuário escolha a opção de sair (opção 0).
//  Durante a execução, o programa limpa a tela do console para proporcionar uma experiência
//  de usuário mais limpa e organizada.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA:
//  cadastrar
//  listar
//  excluir
//  alterar
// MÉTODO: A seguir está o pseudocódigo que descreve como a função funciona.
//  1. limpa o terminal
//  2. Imprime o menu.
//  3. solicita ao usuário a opção.

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

        printf("\n\n  Escolha uma Opção: ");
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


// nome DA FUNÇÃO: cadastrar
// PROPÓSITO:
//  Esta função guia o usuário por um processo de cadastro, solicitando informações
//  como nome, e-mail, sexo, peso e altura do novo aluno na academia. O cálculo do
//  Índice de Massa Corporal (IMC) é realizado automaticamente com base no peso e
//  altura fornecidos. O usuário tem a opção de refazer o cadastro ou confirmar
//  os dados inseridos.
//
//  Se o usuário optar por confirmar, a função procura por uma posição disponível no
//  array de alunos e armazena os dados do novo aluno nessa posição. A matrícula do aluno
//  é atribuída automaticamente com base na posição no array.
//
//  O processo de cadastro é repetido enquanto o usuário optar por refazer o cadastro.
//  Após a conclusão, o usuário é redirecionado de volta ao menu principal
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// MÉTODO: A seguir está o pseudocódigo que descreve como a função funciona.
//  1. limpa o terminal e imprime o cabeçalho
//  2. Solicita os dados esperado para o usuário.
//  3. Solicita ao usuário a confirmação dos dados.
//  4. Guarda os dados regitrados pelo usuário no array alunos.

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
            printf("\n Sexo inválido. Digite M para masculino ou F para feminino.\n");
            getch();
            continue;
        }

        printf("\n Peso [kg] (use vírgula como separador decimal): ");
        scanf("%f", &peso);
        fflush(stdin);


        printf("\n Altura [m] (use vírgula como separador decimal): ");
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

// nome DA FUNÇÃO: listar
// PROPÓSITO:
//  A função verifica se há alunos cadastrados. Se existirem, ela utiliza a função
//  MostrarAluno para exibir as informações detalhadas de cada aluno ativo, incluindo
//  matrícula, nome, e-mail, peso, altura e Índice de Massa Corporal (IMC).
//
//  Se não houver alunos cadastrados, uma mensagem informando a ausência de alunos é
//  exibida na tela. A função aguarda a interação do usuário antes de retornar ao menu
//  principal.
//
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA:
//  MostrarAluno
//  verificaMatricula
//
// MÉTODO: A seguir está o pseudocódigo que descreve como a função funciona.
//  1. limpa o terminal e imprime o cabeçalho
//  2. Verifica se tem algum aluno matriculado.
//  3. Caso exista alunos matriculados imprime uma lista com todos os alunos e suas informações.

void listar(){


    system("cls");
    printf("\n  #----------------------------------------------------------------------------#");
    printf("\n  |                             LISTA DE ALUNOS                                |");
    printf("\n  #----------------------------------------------------------------------------#");

    printf("\n\n");

    if (verificaMatricula() == 0){

        system("cls");
        printf("\n  #----------------------------------------#");
        printf("\n  |    NÃO EXISTEM ALUNOS MATRICULADOS     |");
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

// nome DA FUNÇÃO: excluir
// PROPÓSITO:
//  A função verifica se há alunos cadastrados. Se existirem, exibe uma lista numerada de
//  alunos ativos com suas matrículas. O usuário é solicitado a digitar o número da matrícula
//  do aluno que deseja excluir.
//
//  Após a escolha, a função exibe as informações detalhadas do aluno selecionado e solicita
//  a confirmação do usuário para prosseguir com a exclusão. Se confirmado, o aluno é marcado
//  como inativo no array de alunos.
//
//  Se não houver alunos cadastrados, uma mensagem informando a ausência de alunos é exibida
//  na tela. A função aguarda a interação do usuário antes de retornar ao menu principal.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA:
//  MostrarAluno
//
// MÉTODO: A seguir está o pseudocódigo que descreve como a função funciona.
//  1. limpa o terminal
//  2. verificar se tem algum aluno cadastrado
//  3. Caso tenha alunos cadastrados exibir a lista de todos os alunos cadastrados.
//  4. solicitar para o usúario o número de matrícula a ser excluido
//  5. confirmar a exclusão do aluno.
//  6. excluir aluno.


void excluir(){



    if (verificaMatricula() == 0){
        system("cls");
        printf("\n  #----------------------------------------#");
        printf("\n  |    NÃO EXISTEM ALUNOS MATRICULADOS     |");
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

        printf("\n\n\nDIGITE O NÚMERO DE MATRÍCULA DO ALUNO QUE VOCÊ DESEJA EXCLUIR: ");
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
            printf("\n  |       ALUNO EXCLUÍDO COM SUCESSO       |");
            printf("\n  #----------------------------------------# \n\n");
            getch();


        }


    }


}

// nome DA FUNÇÃO: alterar
// PROPÓSITO:
//  A função verifica se há alunos cadastrados. Se existirem, exibe uma lista numerada de alunos
//  ativos com suas matrículas. O usuário é solicitado a digitar o número da matrícula do aluno
//  que deseja atualizar.
//
//  Após a escolha, a função exibe as informações detalhadas do aluno selecionado e permite ao
//  usuário inserir os novos dados. O IMC é recalculado automaticamente com base no peso e altura
//  fornecidos.
//
//  O usuário tem a opção de refazer o processo de atualização ou confirmar as alterações. Se
//  confirmado, os dados do aluno são atualizados no array de alunos.
//
//  Se não houver alunos cadastrados, uma mensagem informando a ausência de alunos é exibida
//  na tela. A função aguarda a interação do usuário antes de retornar ao menu principal.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA:
//  verificaMatricula
//  MostrarAluno
//
// MÉTODO: A seguir está o pseudocódigo que descreve como a função funciona.
//  1. Declaração dos parâmetros
//  2. verifica se existem alunos cadastrados.
//  3. Caso exista mostra as informações de todos alunos cadastrados na tela.
//  4. Solicita ao usuário o número de matrícula que ele deseja atualizar.
//  5. Mostra ao usuário o aluno que ele escolheu e pede confirmação para atualizar.
//  6. Solicita os dados para atualizar o cadastro.
//  7. Solicita a confirmação dos dados atualizados.
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
        printf("\n  |    NÃO EXISTEM ALUNOS MATRÍCULADOS     |");
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

        printf("\n\n\nDIGITE O NÚMERO DA MATRÍCULA QUE VOCÊ DESEJA ATUALIZAR: ");
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
                    printf("\n Sexo inválido. Digite M para masculino ou F para feminino.\n");
                    getch();
                    continue;
                }

                printf("\n Peso [kg] (use vírgula como separador decimal): ");
                scanf("%f", &peso);
                fflush(stdin);


                printf("\n Altura [m] (use vírgula como separador decimal): ");
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
                    printf("\n  |          MATRÍCULA ATUALIZADA          |");
                    printf("\n  #----------------------------------------# \n\n");
                    getch();
                }

            } while(op != 0);


        }

    }

}

// nome DA FUNÇÃO: MostrarAluno
// PROPÓSITO:
//  A função recebe o índice de um aluno no array de alunos e exibe suas informações formatadas
//  na tela. As informações exibidas incluem a matrícula, o nome, o e-mail, o peso, a altura e o IMC.
//
// nome         tipo     valor/referência   descrição
// ---------------------------------------------------------------------------
// i            int       valor              índice do aluno no array
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// MÉTODO: A seguir está o pseudocódigo que descreve como a função funciona.
//  1. exibe na tela as informações que compoem a estrutura CadastroAlunos.


void MostrarAluno(int i){

    printf("\n\n                MATRÍCULA: %i \n",alunos[i].matricula);
    printf("\n\n-> NOME: %s",alunos[i].nome);
    printf("\n-> E-MAIL: %s",alunos[i].email);
    printf("\n-> SEXO: %c",alunos[i].sexo);
    printf("\n\n-> PESO: %.2fKg",alunos[i].peso);
    printf("\n\n-> ALTURA: %.2fm",alunos[i].altura);
    printf("\n\n-> IMC: %.2f\n\n",alunos[i].imc);


}

// nome DA FUNÇÃO: verificaMatricula
// PROPÓSITO:
//  A função percorre o array de alunos e conta o número de alunos ativos, marcados com o status 1.
//  O resultado é o número total de alunos ativos na academia.
//
// Retorno:
// nome         tipo   descrição
// -------------------------------------
// ativos       int    número de alunos ativos
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// MÉTODO: A seguir está o pseudocódigo que descreve como a função funciona.
//  1. Declaração e inicialização da variável ativos
//  2. Loop que passa por todos os alunos matriculados dentro do array alunos e verifica se ele está ativo
//  3. Caso ele esteja ativo a variavél ativos é incrementada em um.
//  4. Retorna a variável ativos com o número de cadastros ativos.

int verificaMatricula(){
    int ativos = 0;

    for (int i = 0; i < MAX_ALUNOS; i++){
        if (alunos[i].ativo == 1){
            ativos++;
        }
    }
    return ativos;
}

// Função: salvarDados
// Propósito:
//  Esta função salva os dados dos alunos em um arquivo, permitindo a persistência das informações
//  entre execuções do programa. Os dados salvos incluem nome, e-mail, sexo, matrícula, peso, altura,
//  IMC e status de atividade.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// MÉTODO: A seguir está o pseudocódigo que descreve como a função funciona.
//  1. Abrir o arquivo "alunos.txt" em modo de escrita
//  2. Se o arquivo não puder ser aberto, exibir uma mensagem de erro e encerrar o programa
//  3. Para cada aluno no array de alunos:
//  4. verificar se o aluno está ativo
//  5. Formatar os dados do aluno (nome, e-mail, sexo, matrícula, peso, altura, IMC, status) em uma string
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

// Função: carregarDados
// Propósito:
//    Esta função carrega os dados dos alunos a partir de um arquivo, permitindo a inicialização
//    do programa com informações previamente salvas. Os dados incluem nome, e-mail, sexo, matrícula,
//    peso, altura, IMC e status de atividade.
//
// VALOR DE RETORNO: none
//
// CHAMADAS PARA: none
//
// MÉTODO: A seguir está o pseudocódigo que descreve como a função funciona.
//  1. Função carregarDados:
//  2. Abrir o arquivo "alunos.txt" em modo de leitura
//  3. Se o arquivo não puder ser aberto, exibir uma mensagem de erro e encerrar o programa
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
