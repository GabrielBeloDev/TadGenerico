// Gabriel Belo Pereira dos Reis

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "gCofo.h"

#define TRUE 1
#define FALSE 0

gCofo *chamaGCofCreate();
int chamaGCofDestroy(gCofo *CofoOriginal);
void chamaGCofInsert(gCofo *CofoOriginal);
void chamaGCofQuery(gCofo *CofoOriginal);
void chamaGCofRemove(gCofo *CofoOriginal);
void chamaGCofItems(gCofo *CofoOriginal);
void gCofEmpty(gCofo *CofoOriginal);
int cmpId(void *A1, void *B1);
int cmpNome(void *A1, void *B1);

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    gCofo *CofoOriginal;
    int opcao = 0, cofoCriado = FALSE;

    do
    {
        printf("                      OPERACÕES                      \n");
        printf(" 1. Criar o cofo\n");
        printf(" 2. Inserir um jogador no cofo\n");
        printf(" 3. Verificar se um jogador está no cofo\n");
        printf(" 4. Mostrar jogadores no cofo\n");
        printf(" 5. Remover um jogador do cofo\n");
        printf(" 6. Esvaziar o cofo\n");
        printf(" 7. Destruir o cofo\n");
        printf(" 8. Sair\n");
        printf("- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (cofoCriado == FALSE)
            {
                CofoOriginal = chamaGCofCreate();
                if (CofoOriginal != FALSE)
                {
                    cofoCriado = TRUE;
                }
            }
            else
            {
                printf("\nVocê já possui um cofo!");
            }
            break;

        case 2:
            if (cofoCriado)
            {
                chamaGCofInsert(CofoOriginal);
            }
            else
            {
                printf("\nCrie um cofo antes de inserir jogadores!");
            }
            break;

        case 3:
            if (cofoCriado)
            {
                chamaGCofQuery(CofoOriginal);
            }
            else
            {
                printf("\nCrie um cofo antes de verificar se um jogador está nele!");
            }
            break;

        case 4:
            if (cofoCriado)
            {
                chamaGCofItems(CofoOriginal);
            }
            else
            {
                printf("\nCrie um cofo antes de verificar se um jogador está nele!");
            }
            break;

        case 5:
            if (cofoCriado)
            {
                chamaGCofRemove(CofoOriginal);
            }
            else
            {
                printf("\nCrie um cofo antes de remover jogadores!");
            }
            break;

        case 6:
            if (cofoCriado)
            {
                gCofEmpty(CofoOriginal);
            }
            else
            {
                printf("\nCrie um cofo antes de esvaziá-lo!");
            }
            break;

        case 7:
            if (cofoCriado)
            {
                cofoCriado = chamaGCofDestroy(CofoOriginal);
            }
            else
            {
                printf("\nCrie um cofo antes de destruí-lo!");
            }
            break;

        case 8:
            printf("\n\nFinalizado...\n\n");
            break;

        default:
            printf("\n\n Digite algo válido\n\n");
        }

    } while (opcao != 8);

    return 0;
}

gCofo *chamaGCofCreate()
{
    int tamanhoCofo;
    gCofo *c;

    printf("\n\nCriando o cofo...\n");
    printf("\nDigite o tamanho do cofo: ");
    scanf("%d", &tamanhoCofo);
    c = gcofCreate(tamanhoCofo);

    if (c != NULL)
    {
        printf("Cofo criado! ");
        return c;
    }
    else
    {
        printf("\nNão foi possível criar seu cofo");
        return FALSE;
    }
}

int chamaGCofDestroy(gCofo *CofoOriginal)
{
    int sucesso;
    sucesso = gcofDestroy(CofoOriginal);
    if (sucesso)
    {
        printf("\nCofo Destruído");
        return FALSE;
    }
    else
    {
        printf("\nNão foi possível destruir o cofo!");
        return TRUE;
    }
}

void chamaGCofInsert(gCofo *CofoOriginal)
{
    int sucesso;
    Jogador *j = (Jogador *)malloc(sizeof(Jogador));
    if (j != NULL)
    {
        printf("\nDigite o nome do jogador: ");
        scanf("%s", j->nome);
        printf("Digite o ID do jogador: ");
        scanf("%d", &(j->id));
        printf("Digite o salário do jogador: ");
        scanf("%f", &(j->salario));

        sucesso = gcofInsert(CofoOriginal, (void *)j);
        if (sucesso)
        {
            printf("\nJogador inserido! ");
        }
        else
        {
            printf("\nNão foi possível inserir o jogador!");
            free(j);
        }
    }
    else
    {
        printf("\nNão foi possível alocar memória para o jogador!");
    }
}

void chamaGCofQuery(gCofo *CofoOriginal)
{
    int id;
    Jogador *j;
    printf("\nDigite o ID do jogador que deseja buscar: ");
    scanf("%d", &id);
    j = (Jogador *)gcofQuery(CofoOriginal, &id, cmpId);
    if (j != NULL)
    {
        printf("\nJogador encontrado!");
        printf("\nNome: %s", j->nome);
        printf("\nID: %d", j->id);
        printf("\nSalário: %.2f", j->salario);
    }
    else
    {
        printf("\nJogador não encontrado!");
    }
}

void chamaGCofRemove(gCofo *CofoOriginal)
{
    int id;
    Jogador *j;
    printf("\nDigite o ID do jogador que deseja remover: ");
    scanf("%d", &id);
    j = (Jogador *)gcofRemove(CofoOriginal, &id, cmpId);
    if (j != NULL)
    {
        printf("\nJogador removido com SUCESSO!");
        printf("\nNome: %s", j->nome);
        printf("\nID: %d", j->id);
        printf("\nSalário: %.2f", j->salario);
        free(j);
    }
    else
    {
        printf("\nJogador não encontrado!");
    }
}

void chamaGCofItems(gCofo *CofoOriginal)
{
    Jogador *j;
    j = (Jogador *)gcofGetFirst(CofoOriginal);
    if (j != NULL)
    {
        do
        {
            printf("\nNome: %s", j->nome);
            printf("\nID: %d", j->id);
            printf("\nSalário: %.2f", j->salario);
            printf("\n-----------------------------");
            j = (Jogador *)gcofGetNext(CofoOriginal);
        } while (j != NULL);
    }
    else
    {
        printf("\nNão há jogadores no cofo!");
    }
}

void gCofEmpty(gCofo *CofoOriginal)
{
    Jogador *j;
    j = (Jogador *)gcofGetFirst(CofoOriginal);
    while (j != NULL)
    {
        j = (Jogador *)gcofRemove(CofoOriginal, &(j->id), cmpId);
        free(j);
        j = (Jogador *)gcofGetFirst(CofoOriginal);
    }
    printf("\nCofo esvaziado com SUCESSO!");
}

int cmpId(void *A1, void *B1)
{
    Jogador *j = (Jogador *)B1;
    int *id = (int *)A1;
    if (*id == j->id)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int cmpNome(void *A1, void *B1)
{
    Jogador *j = (Jogador *)B1;
    char *nome = (char *)A1;
    if (strcmp(nome, j->nome) == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
