#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 10
struct projeto_produto
{
    char nome[777];
    int quantidade;
    float preco;
};
int addProduto(struct projeto_produto *produto)
{
    int i, quantidade=0, j = tam;

    printf("Adicionar ate %i produtos\n", j);
    printf("Quantidade para adicionar: ");
    scanf("%i", &quantidade);
    if (quantidade <= tam)
    {
        for (i = 0; i < quantidade; i++)
        {
            printf("Nome do produto %i: ",  i+ 1);
            scanf("%s", &produto[i].nome);
            printf("Quantidade do produto: ");
            scanf("%i", &produto[i].quantidade);
            printf("Preco do produto RS:");
            scanf("%f", &produto[i].preco);
        }
    }
    else
    {
        printf("Quantidade invalida\n");
    }
    return quantidade;
}

char* Escolha(struct projeto_produto *produto, char *produtoAcomparar, int quantidade){
    int i, comparacao;
for ( i = 0; i < quantidade; i++)
{
 comparacao = strcmp(produto[i].nome, produtoAcomparar);
 if (comparacao == 0)
 {
    return produto[i].nome;
 }
}
printf("Produto Nao Encontrado\n");
}

int main()
{
    char produtoAcomparar[777];
    struct projeto_produto produto[tam];
    int i, opcao, quantidade, qntdeproduto=0;
    do
    {

        printf("\nMenu:\n");
        printf("1. Adicionar Produtos\n");
        printf("2. Listar os Produtos\n");
        printf("3. Escolher produto para compra\n");
        printf("4. Efetuar Compra\n");
        printf("5. Sair do Progama\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 1:
        quantidade = addProduto(produto);
            break;
        case 2:
        for ( i = 0; i < quantidade; i++)
        {
            printf("\nLista de Podutos\n");
            printf("Nome do produto: %s\n",produto[i].nome);         
            printf("Quantidade do produto: %i\n",produto[i].quantidade);          
            printf("Preco do produto RS:%f\n",produto[i].preco);
        }
        
            break;
         case 3:
         printf("Digite um produto da lista: ");
         scanf("%s",&produtoAcomparar);
         printf("Produto Escolhido: %s",Escolha(produto, produtoAcomparar, quantidade));
         qntdeproduto++;
         break;
         case 4:
         if (qntdeproduto > 0)
         {
           printf("Compra Efetuada com o total %i produtos", qntdeproduto);

         }else{
            printf("Nenhum Produto Adicionado");
         }         
         break;
        default:
            break;
        }

    } while (opcao != 5);
    return 0;
}
