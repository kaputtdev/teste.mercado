Claro! Aqui está o código sem as anotações:

```c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    float vt = 0.0;
    float op, vp, vd, valorp, parcela;
    char resposta;
    int produtosAdicionados = 0;
    char nomesProdutos[100][100];
    int quantidades[100];
    float precosUnitarios[100];

    printf("Bem-vindo ao nosso programa de compras!\n");

    while (1) {
        char produto[100];
        int quantidade;
        float preco;

        printf("Digite o nome do produto: ");
        scanf("%s", produto);

        printf("Digite a quantidade do produto: ");
        scanf("%d", &quantidade);

        printf("Digite o preço do produto: ");
        scanf("%f", &preco);
        system("cls");
        
        vt += preco * quantidade;

        strcpy(nomesProdutos[produtosAdicionados], produto);
        quantidades[produtosAdicionados] = quantidade;
        precosUnitarios[produtosAdicionados] = preco;

        produtosAdicionados++;

        printf("Deseja adicionar mais um produto? (S/N): ");
        scanf(" %c", &resposta);

        if (resposta != 'S' && resposta != 's') {
            break;
        }
    }

    printf("Você adicionou %d produtos ao carrinho:\n \n", produtosAdicionados);

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
            break;
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
                    break;
                } else {
                    printf("Número de parcelas inválido. Digite entre 2 e 10.\n");
                }
            }
            break;
        } else {
            printf("Opção inválida. Digite 1 ou 2.\n \n");
        }
    }

    return 0;
}
```
