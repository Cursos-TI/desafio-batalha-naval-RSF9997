#include <stdio.h>

#define TAM 10      
#define NAVIO 3     
#define MAR 0       
#define NAVIO_VAL 3 

// Função para verificar se o navio cabe no tabuleiro
int pode_posicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha + (direcao == 'V' ? i : 0);
        int c = coluna + (direcao == 'H' ? i : 0);

        // Checa limites e sobreposição
        if (l >= TAM || c >= TAM || tabuleiro[l][c] != MAR) {
            return 0; // Não pode posicionar
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar navio no tabuleiro
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha + (direcao == 'V' ? i : 0);
        int c = coluna + (direcao == 'H' ? i : 0);
        tabuleiro[l][c] = NAVIO_VAL;
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = MAR;

    // Coordenadas iniciais definidas direto no código
    int linha_h = 2, coluna_h = 4; // Navio horizontal
    int linha_v = 5, coluna_v = 7; // Navio vertical

    // Valida e posiciona navios
    if (pode_posicionar(tabuleiro, linha_h, coluna_h, NAVIO, 'H')) {
        posicionar_navio(tabuleiro, linha_h, coluna_h, NAVIO, 'H');
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    if (pode_posicionar(tabuleiro, linha_v, coluna_v, NAVIO, 'V')) {
        posicionar_navio(tabuleiro, linha_v, coluna_v, NAVIO, 'V');
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro Final:\n");
    exibir_tabuleiro(tabuleiro);

    return 0;
}
