//Gabriel Belo Pereira dos Reis

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "gCofo.h"

#define TRUE 1
#define FALSE 0

gCofo *chamaGCofCreate();
int chamaGCofDestroy(gCofo *meuCofo);
void chamaGCofInsert(gCofo *meuCofo);
void chamaGCofQuery(gCofo *meuCofo);
void chamaGCofRemove(gCofo *meuCofo);
void chamaGCofItems(gCofo *meuCofo);
void gCofEmpty(gCofo *meuCofo);
int cmpId(void *a, void *b);
int cmpNome(void *a, void *b);

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    gCofo *meuCofo;
    int opcao = 0, cofoCriado = FALSE;

    do
    {
        printf("\n\n|------------------------------------------------|\n");
        printf("|                      MENU                      |\n");
        printf("|------------------------------------------------|\n");
        printf("|| 1. Criar o cofo\n");
        printf("|| 2. Inserir um jogador no cofo\n");
        printf("|| 3. Verificar se um jogador está no cofo\n");
        printf("|| 4. Mostrar jogadores no cofo\n");
        printf("|| 5. Remover um jogador do cofo\n");
        printf("|| 6. Esvaziar o cofo\n");
        printf("|| 7. Destruir o cofo\n");
        printf("|| 8. Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (cofoCriado == FALSE)
            {
                meuCofo = chamaGCofCreate();
                if (meuCofo != FALSE)
                {
                    cofoCriado = TRUE;
                }
            }
            else
            {
                printf("\nVocê já possui um cofo criado. Divirta-se com as operações do seu cofo!");
            }
            break;

        case 2:
            if (cofoCriado)
            {
                chamaGCofInsert(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
            }
            break;

        case 3:
            if (cofoCriado)
            {
                chamaGCofQuery(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
            }
            break;

        case 4:
            if (cofoCriado)
            {
                chamaGCofItems(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
            }
            break;

        case 5:
            if (cofoCriado)
            {
                chamaGCofRemove(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
            }
            break;

        case 6:
            if (cofoCriado)
            {
                gCofEmpty(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
            }
            break;

        case 7:
            if (cofoCriado)
            {
                cofoCriado = chamaGCofDestroy(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
            }
            break;

        case 8:
            printf("\n\nObrigado por utilizar meu programa :) !!\n\n");
            break;

        default:
            printf("\n\nAtenção: digite um dígito válido!\n\n");
        }

    } while (opcao != 8);

    return 0;
}

gCofo *chamaGCofCreate()
{
    int tamanhoCofo;
    gCofo *c;

    printf("\nVAMOS CRIAR SEU COFO!");
    printf("\nDigite o tamanho do cofo: ");
    scanf("%d", &tamanhoCofo);
    c = gcofCreate(tamanhoCofo);

    if (c != NULL)
    {
        printf("Cofo criado com SUCESSO!");
        return c;
    }
    else
    {
        printf("\nNão foi possível criar seu cofo, tente novamente mais tarde :( !");
        return FALSE;
    }
}

int chamaGCofDestroy(gCofo *meuCofo)
{
    int sucesso;
    sucesso = gcofDestroy(meuCofo);
    if (sucesso)
    {
        printf("\nCofo Destruído!");
        return FALSE;
    }
    else
    {
        printf("\nNão foi possível destruir o cofo!");
        return TRUE;
    }
}

void chamaGCofInsert(gCofo *meuCofo)
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

        sucesso = gcofInsert(meuCofo, (void *)j);
        if (sucesso)
        {
            printf("\nJogador inserido com SUCESSO!");
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

void chamaGCofQuery(gCofo *meuCofo)
{
    int id;
    Jogador *j;
    printf("\nDigite o ID do jogador que deseja buscar: ");
    scanf("%d", &id);
    j = (Jogador *)gcofQuery(meuCofo, &id, cmpId);
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

void chamaGCofRemove(gCofo *meuCofo)
{
    int id;
    Jogador *j;
    printf("\nDigite o ID do jogador que deseja remover: ");
    scanf("%d", &id);
    j = (Jogador *)gcofRemove(meuCofo, &id, cmpId);
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

void chamaGCofItems(gCofo *meuCofo)
{
    Jogador *j;
    j = (Jogador *)gcofGetFirst(meuCofo);
    if (j != NULL)
    {
        do
        {
            printf("\nNome: %s", j->nome);
            printf("\nID: %d", j->id);
            printf("\nSalário: %.2f", j->salario);
            printf("\n-----------------------------");
            j = (Jogador *)gcofGetNext(meuCofo);
        } while (j != NULL);
    }
    else
    {
        printf("\nNão há jogadores no cofo!");
    }
}

void gCofEmpty(gCofo *meuCofo)
{
    Jogador *j;
    j = (Jogador *)gcofGetFirst(meuCofo);
    while (j != NULL)
    {
        j = (Jogador *)gcofRemove(meuCofo, &(j->id), cmpId);
        free(j);
        j = (Jogador *)gcofGetFirst(meuCofo);
    }
    printf("\nCofo esvaziado com SUCESSO!");
}

int cmpId(void *a, void *b)
{
    Jogador *j = (Jogador *)b;
    int *id = (int *)a;
    if (*id == j->id)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int cmpNome(void *a, void *b)
{
    Jogador *j = (Jogador *)b;
    char *nome = (char *)a;
    if (strcmp(nome, j->nome) == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
