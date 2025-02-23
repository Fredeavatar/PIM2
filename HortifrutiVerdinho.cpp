#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "funcoes.h"

int main()
{
    setlocale(LC_ALL, "");
    struct add_produto produtos[100];
    struct add_fornecedor fornecedor[100];
    float caixa = 0.0;
    int opcao, acesso, contador_p = 0, contador_f = 0, contador_v = 0;

    acesso = loginFunc();

    do
    {
        system("cls");
        menuverdinho();

        if (acesso == 1)
        {
            menuAdm();
        }
        else
        {
            menuUsuario();
        }

        printf("Escolha uma opção: ");
        while (scanf("%d", &opcao) != 1)
        {
            fflush(stdin);
            printf("Entrada inválida. Entre com a opção: ");
        }

        // Switch para opções
        switch (opcao)
        {
        case 1:
            if (acesso == 1)
            {
                int op;
                while (1)
                {
                    system("cls");
                    menuverdinho();
                    printf("1. Adicionar Produtos\n2. Exibir Produtos\n3. Editar Produtos\n4. Excluir Produtos\n5. Voltar ao menu\n");
                    printf("Escolha uma opção (1-5): ");
                    if (scanf("%d", &op) == 1 && op >= 1 && op <= 5)
                    {
                        break; // Aceita a entrada se estiver entre 1 e 5
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Entrada inválida. Entre com a opção (1-5)\n\n");
                        system("pause"); // Pausa para o usuário ver a mensagem
                    }
                }
                if (op == 1)
                {
                    cadastrarProduto(produtos, &contador_p);
                }
                else if (op == 2)
                {
                    exibirProdutos(produtos, &contador_p);
                }
                else if (op == 3)
                {
                    editarProduto(produtos, &contador_p);
                }
                else if (op == 4)
                {
                    remover_p(produtos, &contador_p);
                }
                else
                {
                    break;
                }
            }
            else
            {
                exibirProdutos(produtos, &contador_p);
            }
            break;
        case 2:
            if (acesso == 1)
            {
                int op;
                while (1)
                {
                    system("cls");
                    menuverdinho();
                    printf("1. Adicionar Fornecedor\n2. Exibir Fornecedor\n3. Editar Fornecedor\n4. Excluir Fornecedor\n5. Voltar ao menu\n");
                    printf("Escolha uma opção (1-5): ");
                    if (scanf("%d", &op) == 1 && op >= 1 && op <= 5)
                    {
                        break; // Aceita a entrada se estiver entre 1 e 5
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Entrada inválida. Entre com a opção (1-5):\n\n");
                        system("pause");
                    }
                }
                if (op == 1)
                {
                    cadastrarFornecedor(fornecedor, &contador_f);
                }
                else if (op == 2)
                {
                    exibirFornecedores(fornecedor, &contador_f);
                }
                else if (op == 3)
                {
                    editarFornecedor(fornecedor, &contador_f);
                }
                else if (op == 4)
                {
                    remover_f(fornecedor, &contador_f);
                }
                else
                {
                    break;
                }
            }
            else
            {
                exibirFornecedores(fornecedor, &contador_f);
            }
            break;
        case 3:
            if (acesso == 1)
            {
                int op;
                while (1)
                {
                    system("cls");
                    menuverdinho();
                    printf("1. Adicionar Usuário\n2. Exibir Usuário\n3. Editar Usuário\n4. Excluir Usuário\n5. Voltar ao menu\n");
                    printf("Escolha uma opção (1-5): ");
                    if (scanf("%d", &op) == 1 && op >= 1 && op <= 5)
                    {
                        break; // Aceita a entrada se estiver entre 1 e 5
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Entrada inválida. Entre com a opção (1-5):\n\n");
                        system("pause"); // Pausa para o usuário ver a mensagem
                    }
                }
                if (op == 1)
                {
                    cadastrarFunc();
                }
                else if (op == 2)
                {
                    exibirFunc();
                }
                else if (op == 3)
                {
                    editarFunc();
                }
                else if (op == 4)
                {
                    removerFunc();
                }
                else
                {
                    break;
                }
            }
            else
            {
                saldoCaixa(caixa);
            }
            break;
        case 4:
            if (acesso == 1)
            {
                int op;
                while (1)
                {
                    system("cls");
                    menuverdinho();
                    printf("1. Realizar venda\n2. Exibir Venda\n3. Voltar ao menu\n");
                    printf("Escolha uma opção (1-3): ");
                    if (scanf("%d", &op) == 1 && op >= 1 && op <= 3)
                    {
                        break; // Aceita a entrada se estiver entre 1 e 2
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Entrada inválida. Entre com a opção (1-3):\n\n");
                        system("pause");
                    }
                }
                if (op == 1)
                {
                     venderProd(produtos, &contador_p);
                     break;
                }
                else if (op == 2)
                {
                    exibirvendas(produtos, &contador_v);
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                venderProd(produtos, &contador_p);
            }
            break;
        case 5:
            if (acesso == 1)
            {
                int op;
                while (1)
                {
                    system("cls");
                    menuverdinho();
                    printf("1. Exibir Saldo\n2. Editar Saldo\n3. Voltar ao menu\n");
                    printf("Escolha uma opção (1-3): ");
                    if (scanf("%d", &op) == 1 && op >= 1 && op <= 3)
                    {
                        break; // Aceita a entrada se estiver entre 1 e 2
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Entrada inválida. Entre com a opção (1-3):\n\n");
                        system("pause");
                    }
                }
                if (op == 1)
                {
                     saldoCaixa(caixa);
                     break;
                }
                else if (op == 2)
                {
                    editarSaldo();
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                system("cls");
                return (main());
            }
            break;
        case 6:
            if (acesso == 1)
            {
                system("cls");
                return (main());
            }
            else
            {
                printf("Entrada inválida!\n\n");
                system ("pause");
            }
            break;
        case 0:
            {
                int esc;
                printf("Deseja realmente sair? (1) Sim | (2) Não: ");
                scanf ("%d", &esc);
                if (esc == 1){
                    return (0);
                } else {
                    break;
                }
            }
        default:
            puts("Entrada inválida!\n");
            system("pause");
            break;
        }
    } while (1); // Use um loop infinito para continuar ate a opçao de sair
}