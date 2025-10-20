#include <stdio.h>
#include <locale.h>
int main() {
    int select;
    setlocale(LC_ALL, "");
    do {
    printf("Lista de Exercícios - Vetores - 9 questões - ISMAEL HENRIQUE VIEIRA TABORDA\nDigite de 1 á 9 para os Exercícios (0 para sair): ");
    scanf("%i", &select);
   
    switch (select) {
      case 1: {  //1.Faça um programa que leia 10 valores reais e os apresente na ordem inversa entrada.
       float vetor[10];
       printf("\n");
       for (int i=0; i < 10; i++) {
       printf("vetor [%i] = ", i);
       scanf("%f", &vetor[i]);
      }
       for (int i=0; i < 10; i++) {
       printf("%.2f |", vetor[9-i]);
       }
        break;
      }
      case 2: { //2.Faça um programa que leia 5 valores inteiros, armazeno-os em um vetor, calcule e apresente a soma destes valores.
          int vet[5];
          int soma=0;
          printf("\n");
          for (int i=0; i<5;i++){
              printf("\nDigita um valor: ");
              scanf("%i", &vet[i]);
          }
          for (int i=0; i < 5; i++) {
              soma = soma + vet[i];
              printf("%i |", vet[i]);
          }
          printf(" = %i", soma);
          break;
      }
      case 3: { //3. Faça um algoritmo que leia um vetor N[20]. A seguir, encontre o menor elemento do vetor N e a sua posição dentro do vetor, mostrando: “O menor elemento de N é”, M, “e sua posição dentro do vetor é:”, P. 
          int N[20], Maior, Menor, i, p1, p2;
          printf("\n");
          for (i = 0; i < 20; i++) {
              printf("%i. Digitar valor: ", i);
              scanf("%i", &N[i]);
          }
          
          Menor = N[0];
          Maior = N[0];
          p1 = 0;
          p2 = 0;
          
          for (i = 0; i < 20; i++) {
          if (N[i] < Menor) {
          	Menor = N[i];
          	p1 = i;
		  }
		  if (N[i] > Maior) {
          	Maior = N[i];
          	p2 = i;
		  }
	      }
		  printf("\nO Menor Valor: %i | Sua Posição: %i\nO Maior Valor: %i | Sua Posição: %i\n\n", Menor, p1, Maior, p2);
          break;
      }
      case 4: { //4. Escreva um algoritmo que leia dois vetores de 10 posições e faça a multiplicação dos elementos de mesmo índice, colocando o resultado em um terceiro vetor. Mostre o vetor resultante.
	float vet1[10], vet2[10], vet3[10];
	int i, j, k;
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("Guarda um valor no Vetor1 [%i]: ", i);
		scanf("%f", &vet1[i]);
	}
	printf("\n");
	for (j = 0; j < 10; j++) {
		printf("Guarda um valor no Vetor2 [%i]: ", j);
		scanf("%f", &vet2[j]);
	}
	printf("\n");
	for (k = 0; k < 10; k++) {
		vet3[k] = vet1[k] * vet2[k];
		printf("Vetor 1 e 2 multiplicados e mostrando no vetor3 [%i]: %.2f\n", k, vet3[k]);
	}
		break;
	  }
	  case 5: { //5. Faça um algoritmo que leia um vetor S[20] e uma variável A. A seguir, mostre o produto da variável A pelo vetor.
	  	float S[20], A, Produto;
	  	int i, j;
	  	printf("\n");
	  	for (i = 0; i < 20; i++) {
		  printf("Ler os valores dos 20 vetores [%i]: ", i);
		  scanf("%f", &S[i]);
		  }
		printf("\nAgora ler valor de A para fazer o produto de cada vetor do S:");
		scanf("%f", &A);
		printf("\n");
		for (j = 0; j < 20; j++) {
			Produto = S[j] * A;
			printf("O valor dos seguintes vetores [%i]: %.2f\n", j, Produto);
		}
		printf("\n");
		break;
	  }
	  case 6: { //6. Escreva um algoritmo que leia e mostre um vetor de 20 números. A seguir, conte quantos valores pares existem no vetor.
	    int vet[20], i, j, k, par;
	    printf("\n");
	    for (i = 0; i < 20; i++) {
	    	printf("Ler 20 numeros de um vetor [%i]: ", i);
	    	scanf("%i", &vet[i]);
		}
		printf("\n");
		for (j = 0; j < 20; j++) {
			printf("O Valor do vetor [%i]: %i\n", j, vet[j]);
		}
		printf("\n");
        for (k = 0; k < 20; k++) {
        	if (vet[k]%2 == 0) {
        		par = par + 1;
			}
		}
		printf("tem %i Par(es) no vetor", par);
		break;
		}
	   case 7: { //Escreva um algoritmo que leia um vetor de 20 posições e mostre-o. Em seguida, troque o primeiro elemento com o último, o segundo com o penúltimo, o terceiro com o antepenúltimo, e assim sucessivamente. Mostre o novo vetor depois da troca.
	   	int vet[20], i, j, k;
	   	printf("\n");
	   	for (i = 0; i < 20; i++) {
	   		printf("Ler o Vetor [%i]: ", i);
	   		scanf("%i", &vet[i]);
		   }
		printf("\n");
		for (j = 0; j < 20; j++) {
		printf("Vetor Normal [%i]: %i\n", j, vet[j]);
		}
		/*for (j = 0; j < 20; j++) {
		printf("Vetor Normal [%i]: %i\n", j, vet[19-j]);
		}*/
		printf("\n");
		for (k = 19; k >= 0; k--) {
		printf("Vetor Invertido [%i]: %i\n", k, vet[k]);
		}
		break;
	   }
	   case 8: { /*Faça um programa que leia 10 números inteiros, armazene-os em um vetor, solicite um valor de referência inteiro e:
	    a. Imprima os números do vetor que são maiores que o valor referência.
		b. Retorne quantos números armazenados no vetor são menores que o valor de referência.
		c.Retorne quantas vezes o valor de referência aparece no vetor.*/
	   	int vet[10], REFERENCE, i, j, k, MENOR = 0, IGUAL = 0;
	   	printf("\n");
	   	for (i = 0; i < 10; i++) {
	   		printf("Ler valor inteiro [%i]: ", i);
	   		scanf("%i", &vet[i]);
		   }
		printf("\nLer o valor de referência: ");
		scanf("%i", &REFERENCE);
	   	for (j = 0; j < 10; j++) {
	   		if (vet[j] < REFERENCE) {
	   			MENOR = MENOR + 1;
			   }
			if (vet[j] == REFERENCE) {
				IGUAL = IGUAL + 1;
			}
		   }
		printf("\n");
		for (k = 0; k < 10; k++) {
			if (vet[k] > REFERENCE) {
				printf("Numero maior que a referência no vetor [%i]: %i\n", k, vet[k]);
			}
		}
		printf("\nQuantidade de Números menores que a Referência no vetor: %i\nQuantidade de Números iguais à Referência no vetor: %i\n", MENOR, IGUAL);
		break;
	   }
	   case 9: { //Faça um programa que leia e armazene dois vetores a e b com 5 elementos cada e apresente o resultado de: somatoria de 5 elementos A[i] + B[4-i]
	   	int A[5], B[5], i, j, k, Somatoria;
	   	printf("\n");
	   	for (k = 0; k < 5; k++) {
	   		printf("Ler Valor de A [%i]: ", k);
	   		scanf("%i", &A[k]);
		   }
		printf("\n");
		for (j = 0; j < 5; j++) {
			printf("Ler Valor de B [%i]: ", j);
	   		scanf("%i", &B[j]);
		}
		for (i = 0; i < 5; i++) {
			Somatoria = A[i] + B[4-i];
		}
		printf("\nResultado: %i\n\n", Somatoria);
		break;
	   }
	  }
}
	  while (select != 0);
	  return 0;
    }
