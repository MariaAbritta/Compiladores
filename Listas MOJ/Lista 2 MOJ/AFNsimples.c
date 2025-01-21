#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTADOS 100
#define MAX_SIMBOLOS 100

typedef struct {
    int origem;
    char simbolo;
    int destinos[MAX_ESTADOS];
    int num_destinos;
} Transicao;

int verifica_estado_final(int estado, int* estados_finais, int num_estados_finais) {
    for (int i = 0; i < num_estados_finais; i++) {
        if (estado == estados_finais[i]) {
            return 1; // Retorna 1 se for estado final
        }
    }
    return 0; // Retorna 0 se não for estado final
}

int processa_palavra(int num_estados, int num_simbolos, char* alfabeto, Transicao* transicoes, int estado_inicial, int* estados_finais, int num_estados_finais, char* palavra) {
    int estados_atuais[MAX_ESTADOS];
    int num_estados_atuais = 1;
    estados_atuais[0] = estado_inicial;

    for (int i = 0; palavra[i] != '\0'; i++) {
        char simbolo = palavra[i];
        int novos_estados[MAX_ESTADOS];
        int num_novos_estados = 0;

        for (int j = 0; j < num_estados_atuais; j++) {
            int estado_atual = estados_atuais[j];

            for (int k = 0; k < num_estados * num_simbolos; k++) {
                if (transicoes[k].origem == estado_atual && transicoes[k].simbolo == simbolo) {
                    for (int l = 0; l < transicoes[k].num_destinos; l++) {
                        novos_estados[num_novos_estados++] = transicoes[k].destinos[l];
                    }
                }
            }
        }

        num_estados_atuais = num_novos_estados;
        memcpy(estados_atuais, novos_estados, num_novos_estados * sizeof(int));
    }

    for (int i = 0; i < num_estados_atuais; i++) {
        if (verifica_estado_final(estados_atuais[i], estados_finais, num_estados_finais)) {
            return 1; // Aceita a palavra se pelo menos um estado atual for final
        }
    }

    return 0; // Rejeita a palavra se nenhum estado atual for final
}

int main() {
    int num_estados, num_simbolos, estado_inicial, num_estados_finais;
    char alfabeto[MAX_SIMBOLOS], palavra[MAX_ESTADOS * MAX_SIMBOLOS];
    Transicao transicoes[MAX_ESTADOS * MAX_SIMBOLOS];

    scanf("%d", &num_estados);

    scanf("%d", &num_simbolos);
    for (int i = 0; i < num_simbolos; i++) {
        scanf(" %c", &alfabeto[i]);
    }

    for (int i = 0; i < num_estados * num_simbolos; i++) {
        scanf("%d %c", &transicoes[i].origem, &transicoes[i].simbolo);
        scanf("%d", &transicoes[i].num_destinos);
        for (int j = 0; j < transicoes[i].num_destinos; j++) {
            scanf("%d", &transicoes[i].destinos[j]);
        }
    }

    scanf("%d", &estado_inicial);

    scanf("%d", &num_estados_finais);
    int estados_finais[num_estados_finais];
    for (int i = 0; i < num_estados_finais; i++) {
        scanf("%d", &estados_finais[i]);
    }

    scanf("%s", palavra);

    int resultado = processa_palavra(num_estados, num_simbolos, alfabeto, transicoes, estado_inicial, estados_finais, num_estados_finais, palavra);
    if (resultado) {
        printf("Aceito\n");
    } else {
        printf("Rejeito\n");
    }

    return 0;
}
