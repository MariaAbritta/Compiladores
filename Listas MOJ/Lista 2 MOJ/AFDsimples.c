#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estado {
    int **transicoes;
    char tipo; // 'i' para inicial, 'f' para final, 'n' para normal
} Estado;

int main() {
    int numEstados, numSimbolos;
    
    // Lendo o número de estados
    scanf("%d", &numEstados);
    
    // Lendo o número de símbolos e os símbolos
    scanf("%d", &numSimbolos);
    char **alfabeto = (char **)malloc(numSimbolos * sizeof(char *));
    for (int i = 0; i < numSimbolos; i++) {
        alfabeto[i] = (char *)malloc(2 * sizeof(char));
        scanf("%s", alfabeto[i]);
    }
    
    // Criando e inicializando os estados
    Estado *estados = (Estado *)malloc(numEstados * sizeof(Estado));
    for (int i = 0; i < numEstados; i++) {
        estados[i].transicoes = (int **)malloc(numSimbolos * sizeof(int *));
        for (int j = 0; j < numSimbolos; j++) {
            estados[i].transicoes[j] = NULL;
        }
        estados[i].tipo = 'n'; // Inicializar todos os estados como normais
    }

    // Lendo a tabela de transição
    for (int i = 0; i < numEstados * numSimbolos; i++) {
        int origem, destino;
        char simbolo[2];
        scanf("%d %s %d", &origem, simbolo, &destino);
        
        // Encontrando o índice do símbolo no alfabeto
        int indiceSimbolo = -1;
        for (int j = 0; j < numSimbolos; j++) {
            if (strcmp(simbolo, alfabeto[j]) == 0) {
                indiceSimbolo = j;
                break;
            }
        }
        
        // Definindo a transição
        estados[origem].transicoes[indiceSimbolo] = (int *)malloc(sizeof(int));
        *(estados[origem].transicoes[indiceSimbolo]) = destino;
    }
    
    // Lendo o estado inicial
    int estadoInicial;
    scanf("%d", &estadoInicial);
    estados[estadoInicial].tipo = 'i';
    
    // Lendo os estados finais
    int numEstadosFinais;
    scanf("%d", &numEstadosFinais);
    for (int i = 0; i < numEstadosFinais; i++) {
        int estadoFinal;
        scanf("%d", &estadoFinal);
        estados[estadoFinal].tipo = 'f';
    }
    
    // Lendo a string de entrada
    char entrada[100];
    scanf("%s", entrada);
    
    // Simulando o AFD
    int estadoAtual = estadoInicial;
    for (int i = 0; i < strlen(entrada); i++) { // Corrigido para percorrer toda a entrada
        int indiceSimbolo = -1;
        for (int j = 0; j < numSimbolos; j++) {
            if (entrada[i] == *alfabeto[j]) { // Corrigido para comparar caracteres em vez de strings
                indiceSimbolo = j;
                break;
            }
        }
        if (indiceSimbolo == -1) {
            printf("Rejeito\n");
            return 0;
        }
        if (estados[estadoAtual].transicoes[indiceSimbolo] == NULL) {
            printf("Rejeito\n");
            return 0;
        }
        estadoAtual = *(estados[estadoAtual].transicoes[indiceSimbolo]);
    }
    
    // Verificar se o estado final é um estado final
    if (estados[estadoAtual].tipo == 'f') {
        printf("Aceito\n");
    } else {
        printf("Rejeito\n");
    }
    
    // Liberar memória alocada
    for (int i = 0; i < numSimbolos; i++) {
        free(alfabeto[i]);
    }
    free(alfabeto);
    for (int i = 0; i < numEstados; i++) {
        for (int j = 0; j < numSimbolos; j++) {
            if (estados[i].transicoes[j] != NULL) {
                free(estados[i].transicoes[j]);
            }
        }
        free(estados[i].transicoes);
    }
    free(estados);
    
    return 0;
}
