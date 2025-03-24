/*
  Titulo: Lista Estatica
  Autores: João Volta
  Data: 17/03/2025
  Descrição: Implementação das operacoes realizadas na lista_estatica
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica-1.h"

// Inicializa a lista, definindo seu tamanho como 0
void cria(Lista *p_l) {
    p_l->tam = 0;
}

// Verifica se a lista está vazia
int vazia(Lista *p_l) {
    if(p_l->tam == 0) { // Se o tamanho for 0, a lista está vazia
        return 0;
    }
    return 1; // Caso contrário, a lista não está vazia
}

// Insere um elemento no início da lista
void insere_inicio(Lista *p_l, elem_t e) {
    if(p_l->tam < MAX) { // Verifica se há espaço na lista
        for(int i = p_l->tam; i > 0; i--) { // Desloca os elementos para frente
            *(p_l->vet+i) = *(p_l->vet+i-1);
        }
        *(p_l->vet+0) = e; // Insere o novo elemento no índice 0
        p_l->tam++; // Atualiza o tamanho da lista
    } else {
        printf("\nA lista esta cheia..."); // Exibe uma mensagem caso a lista esteja cheia
    }
}

// Insere um elemento no final da lista
void insere_fim(Lista *p_l, elem_t e) {
    if(p_l->tam < MAX) { // Verifica se há espaço disponível
        *(p_l->vet+p_l->tam) = e; // Insere o elemento na última posição livre
        p_l->tam++; // Atualiza o tamanho da lista
    } else {
        printf("\nA lista esta cheia...");
    }
}

// Insere um elemento de forma ordenada na lista
int insere_ordenado(Lista *p_l, elem_t e) {
    if(p_l->tam >= MAX) { // Verifica se há espaço disponível
        return 0;
    }

    // Verifica se o elemento já existe na lista
    for(int i = 0; i < p_l->tam; i++) {
        if(e == *(p_l->vet+i)) {
            return 0; // Se o elemento já existe, não insere
        }
    }

    int achou = 0;

    // Encontra a posição correta para inserir o elemento
    while(achou < p_l->tam && *(p_l->vet+achou) < e)
        achou++; 

    // Desloca os elementos para abrir espaço
    for(int i = p_l->tam; i > achou; i--) {
        *(p_l->vet+i) = *(p_l->vet+i-1);
    }

    *(p_l->vet+achou) = e; // Insere o elemento na posição correta
    p_l->tam++; // Atualiza o tamanho da lista
    return 1;    
}

// Verifica se a lista está ordenada em ordem crescente
int ordenada(Lista *p_l) {
    for(int i = 0; i < p_l->tam-1; i++) {
        if(*(p_l->vet+i) > *(p_l->vet+i+1)) // Se encontrar um elemento fora de ordem
            return 0;
    }
    return 1; // Retorna 1 se a lista estiver ordenada
}

// Ordena a lista usando o algoritmo Bubble Sort
void ordena(Lista *p_l) {
    int temp;

    // Percorre a lista e realiza trocas entre os elementos
    for(int i  = 0; i < p_l->tam-1; i++) {
        for(int j = 0; j < p_l->tam-i-1; j++) {
            if(*(p_l->vet+j) > *(p_l->vet+j+1)) {
                temp = *(p_l->vet+j);
                *(p_l->vet+j) = *(p_l->vet+j+1);
                *(p_l->vet+j+1) = temp;
            }
        }
    }
}

// Remove o primeiro elemento da lista e retorna seu valor
int remove_inicio(Lista *p_l, elem_t *p_e) {
    if(p_l->tam == 0) { // Verifica se a lista está vazia
        return 0;
    }

    *(p_e) = *(p_l->vet+0); // Armazena o elemento removido

    // Desloca os elementos para trás para preencher o espaço removido
    for(int i = 0; i < p_l->tam - 1; i++) {
        *(p_l->vet+i) = *(p_l->vet+i+1);        
    }

    (p_l->tam--); // Atualiza o tamanho da lista
    return *p_e;   
}

// Remove o último elemento da lista e retorna seu valor
int remove_fim(Lista *p_l, elem_t *p_e) { 
    if((p_l->tam) == 0) { // Verifica se a lista está vazia
        return 0;
    }

    *(p_e) = *(p_l->vet+p_l->tam-1); // Armazena o último elemento
    (p_l->tam--); // Atualiza o tamanho da lista

    return *p_e;
}

// Remove um elemento específico da lista
int remove_valor(Lista *p_l, elem_t e) {
    int achou = -1;

    // Procura o elemento na lista
    for(int i = 0; i < p_l->tam; i++) {
        if(e == *(p_l->vet+i)) {
            achou = i; // Armazena o índice do elemento encontrado
            break;
        }
    }

    if(achou == -1) // Se o elemento não foi encontrado, retorna 0
        return 0;

    // Desloca os elementos para preencher o espaço do elemento removido
    for(int i = achou; i < p_l->tam-1; i++) {
        *(p_l->vet+i) = *(p_l->vet+i+1);
    }

    p_l->tam--; // Atualiza o tamanho da lista
    return 1;
}

// Inverte a ordem dos elementos na lista
void inverte(Lista *p_l) {
    int aux; 

    // Troca os elementos da primeira metade com os da segunda metade
    for(int i = 0; i < p_l->tam / 2; i++) {
        aux = *(p_l->vet+i);
        *(p_l->vet+i) = *(p_l->vet+p_l->tam-1-i);
        *(p_l->vet+p_l->tam-1-i) = aux;
    }
}

// Libera todos os elementos da lista (define o tamanho como 0)
void libera(Lista *p_l) {
    p_l->tam = 0;
}

// Exibe todos os elementos da lista
void exibe(Lista *p_l) {
    printf("\nExibindo Lista de numeros: ");
    for(int i = 0; i < p_l->tam; i++) {
        printf("%i - ", *(p_l->vet+i)); // Exibe cada elemento da lista
    }
}