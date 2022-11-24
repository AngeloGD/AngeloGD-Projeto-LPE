#include <stdio.h>


int main(void) {

  int menu = 0, fila = 0, contfila = 0, op = 0, litros = 0, tanque = 200,
      carrosatend = 0, litrosvend = 0;
  float preco, valorvendas = 0;

  printf("\n\tAutor: Angelo Gabriel Debarba\n");
  printf("\nDESCRIÇÃO:\n\nEsse programa tem como base gerenciar as informações "
         "de um posto de gasolina que contém apenas uma bomba e um tipo de "
         "combustível.\n");
  do {
    printf("\nPor gentileza, informe o preço da gasolina:\nATENÇÃO: Utilize um "
           "ponto para definir o valor em centavos!!\n");
    scanf("%f", &preco);
    if (preco <= 0) {
      printf("\nValor fornecido é ivalido.\n");
    }

  } while (preco <= 0);
  do {
    printf(
        "\nNeste momento informe a quantidade de carros que a fila suporta:\n");
    scanf("%d", &fila);
    if (fila <= 0) {
      printf("\nValor fornecido é ivalido.\n");
    }
  } while (fila <= 0);
  system("clear");

  printf("Valor do combustível: R$ %.3f\n", preco);
  printf("Capacidade da fila: %d carros\n", fila);

  while (menu != 5) {
    op = 0;

    printf("\n\t\t\tMENU PRINCIPAL\n\n");
    printf(" Escolha uma opção:\n\n[1] Adicionar um carro na fila.\n\n[2] "
           "Abastecimento.\n\n[3] Exibir carros na fila de espera.\n\n[4] "
           "Relatórios.\n\n[5] Encerrar.\n\n");
    scanf("%d", &menu);

    switch (menu) {
    case (1):
      system("clear");
      if (contfila < fila) {
        printf("[1] Adicionar um carro na fila:\n\n");
        printf("Carro adicionado.\n\n");
        contfila += 1;
      } else {
        printf("Não é possível adicionar mais carros à fila.\n\n");
      }
      printf("%d carros na fila\n\n", contfila);
      break;
    case (2):
      system("clear");
      printf("[2] Abastecimento:\n\n");
      if (tanque != 0) {
        if (contfila > 0) {
          printf("Restam %d litros de combustível.\n\n", tanque);
          printf("\nInforme a quantidade de litros para abastecer:\n");
          scanf("%d", &litros);
          system("clear");
          if ((litros <= 0) || (litros > tanque)) {
            printf("\nValor fornecido é ivalido.\n");
          } else {
            contfila -= 1;
            tanque -= litros;
            litrosvend = 200 - tanque;
            carrosatend += 1;
            printf("Carro abastecido.\n\nReorganizando fila.\n\n");
            printf("Restam %d litros de combustível.\n\n", tanque);
          }
        } else {
          printf("Não há carros disponíveis para abastecer!\n\n");
        }
      } else {
        printf("Não há combustível no tanque!\n\n");
      }
      break;
    case (3):
      system("clear");
      printf("[3] Exibir carros na fila de espera:\n\n");
      printf("%d carros ainda não foram abastecidos.\n\n", contfila);
      break;
    case (4):
      system("clear");

      while (op != 6) {
        printf("\n\t\t\tRelatórios:\n\n");
        printf(
            " Escolha uma opção:\n\n[1] Quantidade de litros vendida.\n\n[2] "
            "Valor total arrecadado com as vendas.\n\n[3] Quantidade de carros "
            "atendidos.\n\n[4] "
            "Quantidade de combustível restante no tanque.\n\n[5] Gerar "
            "arquivo "
            "para impressão (com todas as informações de 1, 2, 3 e 4).\n\n[6] "
            "voltar ao menu anterior.\n\n");
        scanf("%d", &op);
        switch (op) {
        case (1):
          system("clear");
          printf("\n[1] Quantidade de litros vendida:\n\n%d Litros.\n\n",
                 litrosvend);
          break;
        case (2):
          system("clear");
          valorvendas = (preco * litrosvend);
          printf("\n[2] Valor total arrecadado com as vendas:\n\nR$ %.2f\n\n",
                 valorvendas);
          break;
        case (3):
          system("clear");
          printf("\n[3] Quantidade de carros "
                 "atendidos:\n\n%d Carros.\n\n",
                 carrosatend);
          break;
        case (4):
          system("clear");
          printf("\n[4] Quantidade de combustível restante no tanque:\n\n%d "
                 "Litros.\n\n",
                 tanque);
          break;
        case (5):
          system("clear");
          printf("\n[5] Gerar arquivo "
                 "para impressão com todas as informações de 1, 2, 3 e 4:\n\n");
          printf("\n Quantidade de litros vendida: %d Litros.\n", litrosvend);
          valorvendas = (preco * litrosvend);
          printf("\n Valor total arrecadado com as vendas: R$ %.2f\n",
                 valorvendas);
          printf("\n Quantidade de carros "
                 "atendidos: %d Carros.\n",
                 carrosatend);
          printf("\n Quantidade de combustível restante no tanque: %d "
                 "Litros.\n\n",
                 tanque);
          break;
        case (6):
          system("clear");
          printf("\n[6] Voltar ao menu anterior:\n\n");
          break;
        default:
          system("clear");
          printf("\nOpção invalida.\n\n");
          break;
        }
      }
      break;

    case (5):
      system("clear");
      printf("[5] Encerrar...\n\n");
      break;
    default:
      system("clear");
      printf("Opção invalida.\n\n");
      break;
    }
  }
  return 0;
}
