#include <stdio.h>
#include <stdlib.h> // Para a função system
#include <locale.h>
#include <string.h> // Para manipulação de strings

int main() {
    setlocale(LC_ALL, "");

    float vt = 0.0; // Inicialize o total (vt) como 0
    float op, vp, vd, valorp, parcela;
    char resposta;
    int produtosAdicionados = 0;
    char nomesProdutos[100][100]; // Array para armazenar os nomes dos produtos
    int quantidades[100]; // Array para armazenar as quantidades de produtos
    float precosUnitarios[100]; // Array para armazenar os preços unitários de cada produto

    printf("Bem-vindo ao nosso programa de compras!\n");

    while (1) { // Loop infinito para continuar até que o usuário decida parar
        char produto[100]; // Variável para armazenar o nome do produto
        int quantidade;
        float preco;

        printf("Digite o nome do produto: ");
        scanf("%s", produto);

        printf("Digite a quantidade do produto: ");
        scanf("%d", &quantidade);

        printf("Digite o preço do produto: ");
        scanf("%f", &preco);
        system("cls");
vt += preco * quantidade; // Acumule o preço total do produto no total

        // Armazena o nome do produto, quantidade e preço unitário na lista
        strcpy(nomesProdutos[produtosAdicionados], produto);
        quantidades[produtosAdicionados] = quantidade;
        precosUnitarios[produtosAdicionados] = preco;

        produtosAdicionados++;

        printf("Deseja adicionar mais um produto? (S/N): ");
        scanf(" %c", &resposta); // Note o espaço antes de %c para evitar problemas com a entrada do Enter

        if (resposta != 'S' && resposta != 's') {
            break; // Sai do loop se a resposta não for 'S' ou 's'
        }
    }

    printf("Você adicionou %d produtos ao carrinho:\n \n", produtosAdicionados);

    // Exibe a lista de produtos adicionados com nome, quantidade e preço unitário
    for (int i = 0; i < produtosAdicionados; i++) {
        printf("%d. %s Quantidade:%d Preço unitário:R$ %.2f\n \n", i + 1, nomesProdutos[i], quantidades[i], precosUnitarios[i]);
    }

    printf("O total a pagar é: R$ %.2f\n", vt);

    while (1) {
        printf("\nDigite 1 para pagar à vista com 10 por cento de desconto.\nDigite 2 para parcelar em até 10 vezes, sem desconto.\n\nEscolha uma opção: ");
        scanf("%f", &op);
        system("cls");

        if (op == 1) {
            vd = (vt * 10) / 100;
            vp = vt - vd;

            printf("\nValor total da compra: R$ %.2f\n", vt);
            printf("Valor de desconto: R$ %.2f\n", vd);
            printf("Total a pagar: R$ %.2f\n", vp);
            break; // Sai do loop se uma opção válida foi escolhida
        } else if (op == 2) {
            while (1) {
                printf("\nDigite quantas parcelas (2 a 10): ");
                scanf("%f", &parcela);
                system("cls");

                if (parcela >= 2 && parcela <= 10) {
                    valorp = vt / parcela;

                    printf("\nQuantidade de parcelas: %.f\n", parcela);
                    printf("Valor total da compra: R$ %.2f\n", vt);
                    printf("Valor das parcelas: R$ %.2f\n", valorp);
                    break; // Sai do loop interno se uma opção válida foi escolhida
                } else {
                    printf("Número de parcelas inválido. Digite entre 2 e 10.\n");
                }
            }
            break; // Sai do loop externo após a conclusão do loop interno
        } else {
            printf("Opção inválida. Digite 1 ou 2.\n \n");
        }
    }

    return 0;
}
