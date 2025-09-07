#include <stdio.h>
#include <locale.h> //INCLUINDO CARACTERES DA LINGUA PORTUGUESA, UFT-8 em poucas palavras
int main () {
setlocale(LC_ALL, "Portuguese_Brazil"); 
int selecao;
printf("Lista de repetições!\nWhile:\n");
for (int repetir = 1; repetir <= 15; repetir++) {
	printf("Exercicio %d\n", repetir);
	if (repetir == 5) {
		printf("Do While:\n");
	}
	if (repetir == 10) {
		printf("For:\n");
	}
}
printf("Selecionar o Exercício de acordo com o número: ");
scanf("%i", &selecao);
do {
	do {
		printf("Escolher outro número (1 à 15): \n");
		scanf("%i", &selecao);
	} while (selecao < 1 || selecao > 15);
switch (selecao) {
	case 1: {
	int valor = 0, sete = 7, resultado = 0;
	while (resultado < 70 && valor < 10) {
		valor++;
		resultado = sete * valor;
		printf("%dx%d= %d\n", sete, valor, resultado);
	}
		break;
	}
	case 2: {
		int numero = 1, soma = 0;
	
	while (numero <= 100) {
	   soma = soma + numero;
       numero += 1; 
	}
	printf("Somatoria de [1 a 100] = %d\n", soma);
		break;
	}
	case 3: {
		int NumImpar = 0;
		while (NumImpar <= 20) {
			if (NumImpar%2 != 0) {
				printf("%d\n", NumImpar);
			}
			NumImpar++;
		}
		break;
	}
	case 4: {
		int NumDivisivel = 1;
		while (NumDivisivel < 200) {
			if (NumDivisivel%4 == 0) {
				printf("%d\n", NumDivisivel);
			}
			NumDivisivel++;
		}
		break;
	}
	case 5: {
	int num, maior, menor;
	printf("Digitar numero inteiro: ");
	scanf("%d", &num);
	
    maior = num;
    menor = num;
    
    while (num >= 0) {
    	if (num > maior) {
    		maior = num;
	}
		if (num < menor) {
			menor = num;
	}
	printf("Digitar numero inteiro: ");
	scanf("%d", &num);
	}
	printf("Maior: %d\n", maior);
	printf("Menor: %d\n", menor);
		break;
	}
	case 6: {
		int valor = 0, sete = 7, resultado = 0;
	do {
		valor++;
		resultado = sete * valor;
		printf("%dx%d= %d\n", sete, valor, resultado);
	}
	while (resultado < 70 && valor < 10);
		break;
	}
	case 7: {
	int numero = 1, soma = 0;
	do {
		soma = soma + numero;
       numero += 1;
	}
	while (numero <= 100);
	printf("Somatoria de [1 a 100] = %d\n", soma);
		break;
	}
	case 8: {
	int NumImpar = 0;
	do {
		if (NumImpar%2 != 0) {
		printf("%d\n", NumImpar);
		}
		NumImpar++;
		}
		while (NumImpar <= 20);
		break;
	}
	case 9: {
	int NumDivisivel = 1;
	do { 
	if (NumDivisivel%4 == 0) {
	printf("%d\n", NumDivisivel);
		}
		NumDivisivel++;
	}
		while (NumDivisivel < 200);
		break;
	}
	case 10: {
	int num, maior, menor;
	printf("Digitar numero inteiro: ");
	scanf("%d", &num);
	
    maior = num;
    menor = num;
    
    do {
    	if (num > maior) {
    	maior = num;
	}
		if (num < menor) {
		menor = num;
	}
		
	printf("Digitar numero inteiro: ");
	scanf("%d", &num);
	
	}
	
    while (num >= 0);

	printf("Maior: %d\n", maior);
	printf("Menor: %d\n", menor);
		break;
	}
	case 11: {
	int valor, sete = 7, resultado = 0;
	for (valor = 0, resultado = 0; resultado <= 70 && valor <= 10; valor++, resultado = sete * valor) {
		printf("%dx%d= %d\n", sete, valor, resultado);
	}
		break;
	}
	case 12: {
	int numero = 1, soma = 0;
	
	for (numero = 1; numero <= 100; soma = soma + numero, numero += 1) {
	}
	printf("Somatoria de [1 a 100] = %d\n", soma);
		break;
	}
	case 13: {
		int NumImpar = 0;
		for (NumImpar = 0; NumImpar <= 20; NumImpar++) {
			if (NumImpar%2 != 0) {
				printf("%d\n", NumImpar);
			}
		}
		break;
	}
	case 14: {
		int NumDivisivel = 1;
		for (NumDivisivel = 1; NumDivisivel < 200; NumDivisivel++) {
			if (NumDivisivel%4 == 0) {
				printf("%d\n", NumDivisivel);
			}
		}
		break;
	}
	case 15: {
	int num, maior, menor;
	printf("Digitar numero inteiro: ");
	scanf("%d", &num);
	
    maior = num;
    menor = num;
    
    for (num; num >= 0;) {
    	if (num > maior) {
    	maior = num;
	}
		if (num < menor) {
		menor = num;
	}
	printf("Digitar numero inteiro: ");
	scanf("%d", &num);
	}
	printf("Maior: %d\n", maior);
	printf("Menor: %d\n", menor);
		break;
	}

}

}
while (selecao >= 1 && selecao <= 15);
return 0;
}

