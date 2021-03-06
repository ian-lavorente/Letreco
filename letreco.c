#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho_da_palavra 5
#define nome_do_arquivo "palavras.txt"

/*Grupo 1*/
/*Anderson da Silva*/
/*Gustavo Alves*/
/*Tiago Gabriel*/
/*Gabrielly Cristine*/

int sortear_numero(int min, int max) {
  srand(time(NULL));
  return (rand() % (((max + 1) - min) + min));
}

int contar_quantidade_de_palavras_no_arquivo() {
  int numero_de_palavras = 0;
  char palavra[tamanho_da_palavra];
  FILE *arquivo = fopen(nome_do_arquivo, "r");
  while (fscanf(arquivo, "%s", palavra) != EOF) {
    numero_de_palavras++;
  }
  fclose(arquivo);
  return numero_de_palavras;
}

void gerar_palavra_aleatoria(char *palavra) {
  int quantidade_de_palavras_no_arquivo = contar_quantidade_de_palavras_no_arquivo();
  int numero_aleatorio = sortear_numero(1, quantidade_de_palavras_no_arquivo);
  FILE *arquivo = fopen(nome_do_arquivo, "r");
  rewind(arquivo);
  for (int i = 0; i < numero_aleatorio; i++) {
    fscanf(arquivo, "%s", palavra);
  }
  fclose(arquivo);
}

/*Grupo 2*/
/*Karolyne Muniz*/
/*Maria Luiza Passos*/
/*Luiz Henrique*/
/*Alice Akaki*/

int checar_letra_na_palavra(char *palavra, char letra) {
  int i = 0;
  while (palavra[i]) {
    if (palavra[i] == letra) {
      return 1;
    }
    i++;
  }
  return 0;
}

void preencher_linha(char matriz[][tamanho_da_palavra], char *palavra_do_jogo, char *palavra_do_usuario, int linha) {
  int i = 0;
  while (palavra_do_jogo[i]) {
    if (palavra_do_jogo[i] == palavra_do_usuario[i]) {
      matriz[linha][i] = palavra_do_usuario[i];
    }
    if (palavra_do_jogo[i] != palavra_do_usuario[i]) {
      matriz[linha][i] = '+';
    }
    if (checar_letra_na_palavra(palavra_do_jogo, palavra_do_usuario[i]) == 0) {
      matriz[linha][i] = '#';
    }
    i++;
  }
}

/*Grupo 4*/
/*João Pedro Magalhães*/
/*João Guilherme*/
/*Bruno McPherson*/
/*Thiago Paiva*/

void banner() {
  printf("\n ------------------------------------------------- ");
  printf("\n|         ____ _______  ___   ____  ____  ____    |");
  printf("\n|  |     |        |    |   | |     |     |    |   |");
  printf("\n|  |     |____    |    |___| |____ |     |    |   |");
  printf("\n|  |     |        |    | \\   |     |     |    |   |");
  printf("\n|  |____ |____    |    |  \\  |____ |____ |____|   | ");
  printf("\n|                                                 |  ");
  printf("\n ------------------------------------------------- ");
  printf("\n");
  printf("\nRegras:");
  printf("\n# (cerquilha) representa que a letra não existe na palavra.");
  printf("\n+ (adição) significa que a letra existe na palavra, porém está na posição errada.");
  printf("\nBom jogo!");
}

int checar_tamanho_da_palavra(char *palavra) {
  int i = 0;
  while (palavra[i] != '\0') {
    i++;
  }
  return i;
}

void ver_mascara_da_palavra(char palavra[]) {
  printf("\n ------------------------------------------------ ");
  printf("\n");
  printf("|");
  for (int i = 0; i < tamanho_da_palavra; i++) {
    printf("\t%c ", palavra[i]);
  }
  printf("       |");
  printf("\n ------------------------------------------------ ");
  printf("\n                                                   ");
  printf("\n");
}

/*Grupo 5*/
/*Sandy Campos*/
/*Gabriel Sérgio*/
/*Deivison Lima*/
/*Gustavo Klosinski*/

int comparar_palavra(char *palavra_do_jogo, char *mascara, char *palavra_do_usuario) {
  int cont = 0;
  for (int i = 0; i < tamanho_da_palavra; i++) {
    if (palavra_do_jogo[i] == palavra_do_usuario[i]) {
      mascara[i] = palavra_do_jogo[i];
      cont++;
    }
  }
  return cont;
}

void preencher_mascara_da_matriz(char matriz[][tamanho_da_palavra]) {
  for (int i = 0; i < tamanho_da_palavra; i++) {
    for (int j = 0; j < tamanho_da_palavra; j++) {
      matriz[i][j] = '_';
    }
  }
}

/*Extra*/
/*William Cardoso*/

void ver_mascara_da_matriz(char matriz[][tamanho_da_palavra]) {
  for (int i = 0; i < tamanho_da_palavra; i++) {
    printf("\t");
    for (int j = 0; j < tamanho_da_palavra; j++) {
      printf("[%c] ", matriz[i][j]);
    }
    printf("\n");
  }
}

/*Grupo 3*/
/*Gabriel Barros*/
/*Kauã Reydisson*/
/*Guilherme Alves*/
/*Ian Lavorente*/

int main() {
  int numero_de_tentativas = 5, tentativas_usadas = 1;
  char palavra_do_jogo[tamanho_da_palavra] = "";
  char *palavra_do_jogoP;
  palavra_do_jogoP = palavra_do_jogo;
  char palavra_do_usuario[tamanho_da_palavra] = "";
  char mascara[tamanho_da_palavra] = "_____";
  char *mascaraP;
  mascaraP = mascara;
  char matriz_da_palavra[tamanho_da_palavra][tamanho_da_palavra] = {};
  banner();
  printf("\n");
  gerar_palavra_aleatoria(palavra_do_jogoP);
  preencher_mascara_da_matriz(matriz_de_palavras);
  while (numero_de_tentativas > 0) {
    ver_mascara_da_palavra(mascaraP);
    ver_mascara_da_matriz(matriz_de_palavras);
    printf("\nEscreva uma palavra: ");
    scanf("%s", palavra);
    if (checar_tamanho_da_palavra(palavra) != 5) {
      printf("\nNúmero de letras diferente de cinco!");
      continue;
    } else {
      int cont = comparar_palavra(palavra_do_jogo, mascara, palavra);
      if (cont == tamanho_da_palavra) {
        printf("\nParabéns, você acertou! A palavra era: \"%s\".", palavra_do_jogo);
        printf("\nQuantidade de tentativas: %d", tentativas_usadas);
        printf("\n");
        break;
      }
      preencher_linha(matriz_de_palavras, palavra_do_jogoP, palavra_do_usuario, (tentativas_usadas - 1));
    }
    numero_de_tentativas--;
    tentativas_usadas++;
  }
  return 0;
}
