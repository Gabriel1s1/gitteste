#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 3

struct dado{
	int chave;
	char nome[30];
	struct dado* prox;
};

typedef struct dado Dados;
typedef Dados* Hash[m];

struct hashTableStruct{
	int TABLE_SIZE;
	int TABLE_OCUPACAO;
	Hash table;
};
typedef struct hashTableStruct hashTableType;
typedef hashTableType* HashTable;
 
HashTable inicializarHash(int size){
	HashTable hashTable ;
	hashTable = malloc(sizeof(hashTableType));
	hashTable->TABLE_SIZE = size;
	hashTable->TABLE_OCUPACAO = 0;
	int i;
	for( i=0; i < size; i++){
		hashTable->table[i] = NULL;
	}
	return hashTable;
}

int calculaHash(int chave){
	return chave % m;
}

int inserirChave(HashTable hashtable,Dados* dado){
	if (hashtable == NULL || dado == NULL || hashtable->TABLE_OCUPACAO == hashtable->TABLE_SIZE) 
		return 0;
	
	int chave = calculaHash(dado->chave);
	while (hashtable->TABLE_OCUPACAO != hashtable->TABLE_SIZE){
		
		if(hashtable->table[chave] == NULL){
			hashtable->table[chave] = dado;
			
			return 1;
		}
		else{
			chave = calculaHash(chave+=1 % m);
		}
		printf ("Nao e possivel inserir mais valores");
	}
}

Dados* buscaChave(HashTable hashtable, int key){
	int chave = calculaHash(key);	
	while(1){
		if(	hashtable->table[chave] != NULL &&
			hashtable->table[chave]->chave == key){ 
			return hashtable->table[chave];
		}else{
			chave = calculaHash(chave+=1 % m);
		}
	}
}

int removerChave(HashTable hashtable,int key){ //remove valor
	Dados* dado = buscaChave(hashtable, key);
	if(dado == NULL) {
		return 0;
	}
	int chave = calculaHash(key);
	while (1){
		if(hashtable->table[chave] != NULL && hashtable->table[chave]->chave == dado->chave){ 
			free(hashtable->table[chave]) ;
			hashtable->table[chave]=NULL;
			hashtable->TABLE_OCUPACAO--;
			return 1;
		}else{
			chave = calculaHash(chave+=1 % m);
		}
	}
}

main ()
{
    int opMenu, x, n, valor;
    char tipoValor;
    
    HashTable hashtable;
	
    do{    // Menu Principal
		system ("cls");
		printf("\n   TABELA HASHING    \n1 - Inserir\n2 - Buscar\n3 - Remover\n4 - Sair");
		printf("\nDigite sua opcao:");
		scanf ("%d",&opMenu);	

	    printf("\n");
	    
	    switch (opMenu){
			case 1:
				printf ("\n***** Inserir na Tabela *****\n");
				printf ("\n 1. Inserir valor numerico? [S / N] *****\n");
				getchar();
				scanf ("%c", &tipoValor);
				
				if (tipoValor == 'S'){
					printf ("\n Inserir valor numerico \n");
					printf ("\nInsira o tamanho da tabela (M): ");
					scanf("%d", &x);
					Dados Hash[x];
					hashtable = inicializarHash(x);
					printf ("\nInsira a quantidade de elementos da tabela (N): ");
					scanf("%d", &n);
					if (n>m)
					   printf ("\nA quantidade de elementos nao pode exceder o tamanho da tabela\n");
				    else
				    	printf ("\nDigite o valor que deseja inserir na tabela:");
				    	scanf ("%d", &valor);
				    	
				        inserirChave (hashTable, valor);
                }	
				else{
					printf ("\n Inserir valor nao numerico \n");
					printf ("\nInsira o tamanho da tabela (M): ");
					scanf("%d", &x);
					// n não pode exceder o m
				}
				system("Pause");
				break;
			case 2:
				printf ("\n***** Buscar *****\n");
				
				system("Pause");
				break;
			case 3:
				printf ("\n***** Remover *****\n");
				
				system("Pause");
				break;
		}
	}while (opMenu!=4);
}
