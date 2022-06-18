#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cadastro
{
    char nomeDoDev[50];
    int codigoAluno;
};

struct Cadastro armazenamento[5];
int quantidadeAluno = 0;


void menu()
{	
	printf("----------------------------\n");
    printf("------------MENU------------\n");
    printf("----------------------------\n\n");
    printf("Selecione a opcao desejada:\n\n[1] ---> Adicionar \n[2] ---> Alterar \n[3] ---> Buscar\n[4] ---> Listar \n[5] ---> Excluir\n[6] ---> Sair\n\nDigite a opcao desejada: ");
}

void adicionar()
{
    printf("\n----------Incluir Desenvolvedores---------\n\n");
    if (quantidadeAluno >= 5)
    {
        printf("Vagas preenchidas.\n\n");
    }
    else
    {
        printf("Digite o nome do Desenvolvedor: ");
        fflush(stdin);
        gets(armazenamento[quantidadeAluno].nomeDoDev);
        printf("Digite o codigo do Desenvolvedor: ");
        scanf("%d",&armazenamento[quantidadeAluno].codigoAluno);
        quantidadeAluno++;

    }
}
void listar()
{
    printf("----------Lista de Desenvolvedor---------\n\n");
    int i;
    for(i = 0; i < quantidadeAluno; i++)
    {
        printf("%d)%s - %d\n",i + 1,armazenamento[i].nomeDoDev,armazenamento[i].codigoAluno);
    }
    if (quantidadeAluno == 0)
    {
        printf("Não exite programadorees cadastrados.\n\n");
    }

}

void buscar()
{
    printf("--------Busca de desenvolvedores por nome----------\n\n");
    printf("Digite o nome do Desenvolvedor: ");
    char buscaDoUsuario[50];
    fflush(stdin);
    gets(buscaDoUsuario);
    int i;
    int Desenvolvedor_nao_encontrado = 0;
    for(i = 0; i < quantidadeAluno; i++)
    {
        if(strcasecmp(buscaDoUsuario,armazenamento[i].nomeDoDev) == 0)
        {
            Desenvolvedor_nao_encontrado = 1;
            printf("%d)%s - %d\n",i + 1,armazenamento[i].nomeDoDev,armazenamento[i].codigoAluno);
        }
    }

    if (Desenvolvedor_nao_encontrado == 0)
    {
        printf("\nNão achei o programador, tente outro nome.\n\n");
    }

}

void excluir()
{
    printf("\n\n---------------Excluir Desenvolvedor--------------\n\n\n");
    printf("Digite o nome do Desenvolvedor que deseja excluir: ");
    char buscaDoUsuario[50];
    fflush(stdin);
    gets(buscaDoUsuario);
    int i,j;
    int Desenvolvedor_nao_encontrado;
    for(i = 0; i < quantidadeAluno; i++)
    {
        if(strcasecmp(buscaDoUsuario,armazenamento[i].nomeDoDev) == 0)
        {
            Desenvolvedor_nao_encontrado = 1;
            if(i == quantidadeAluno -1)  //excluindo o ultimo ou o unico elemento.
            {
                quantidadeAluno--;
                printf("\nDesenvolvedor Excluido.\n\n");
            }
            else
            {
                for(j = i; j < quantidadeAluno; j++)
                {
                    armazenamento[j] = armazenamento[j+1];
                }
                quantidadeAluno--;
                printf("\nDesenvolvedor Excluido.\n\n");
            }
        }
    }

    if(quantidadeAluno == 0)
    {
        printf("\nNao esta mais aqui.\n\n");
    }

}

void alterar()
{
    printf("\n\n---------------Alterar Desenvolvedor--------------\n\n\n");
    printf("Digite o nome do Desenvolvedor que deseja alterar: ");
    char buscaDoUsuario[50];
    fflush(stdin);
    gets(buscaDoUsuario);
    int i;
    int Desenvolvedor_nao_encontrado = 0;
    for(i = 0; i < quantidadeAluno; i++)
    {
        if(strcasecmp(buscaDoUsuario,armazenamento[i].nomeDoDev) == 0)
        {
            Desenvolvedor_nao_encontrado = 1;

            printf("Digite o nome do novo Desenvolvedor: ");
            fflush(stdin);
            gets(armazenamento[i].nomeDoDev);
            printf("Digite o codigo do novo Desenvolvedor: ");
            scanf("%d",&armazenamento[i].codigoAluno);

            printf("\nDesenvolvedor alterado com sucesso.\n\n");

        }
    }

    if(Desenvolvedor_nao_encontrado == 0)
    {
        printf("\nProgramador nao encontrado.\n\n");
    }

}


int main()
{
    int opcao;
    while(1)
    {
        system("cls");
        menu();
        scanf("%d",&opcao);
        switch(opcao)
        {
        case 1:
            system("cls");
            adicionar();
            break;
        case 2:
            system("cls");
            alterar();
            break;
        case 3:
            system("cls");
            buscar();
            break;
        case 4:
            system("cls");
            listar();
            break;
        case 5:
            system("cls");
            excluir();
            break;
        case 6:
            system("cls");
            printf("\n\n\n----------Programa finalizado.----------\n\n\n");
            exit(0);
            break;
        default:
            system("cls");
            printf("\n\n\=======================================  Comando Invalido, tente novamente!  =========================================\n\n\n");


        }
        system("pause");
    }

}


