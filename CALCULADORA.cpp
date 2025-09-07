#include <stdio.h>
#include <locale.h>
int main () {
	setlocale(LC_ALL, "Portuguese_Brazil");
	char Calculadora;
	printf("Lista de calculos para calcular Adição, Subtração, Multiplicação e Divisão (+, -, * ou /): ");
	scanf("%c", &Calculadora);
	switch (Calculadora) {
	case '+': {
		float A, B;
		printf("digitar o primeiro valor:\n ");
		scanf("%f", &A);
		printf("digitar o segundo valor:\n ");
		scanf("%f", &B);
		printf("A adição foi: %.2f", A + B);
		break;
	}
		case '-': {
		float A, B;
		printf("digitar o primeiro valor:\n ");
		scanf("%f", &A);
		printf("digitar o segundo valor:\n ");
		scanf("%f", &B);
		printf("A Substração foi: %.2f", A - B);
		break;
	}
			case '*': {
		float A, B;
		printf("digitar o primeiro valor:\n ");
		scanf("%f", &A);
		printf("digitar o segundo valor:\n ");
		scanf("%f", &B);
		printf("A Multiplição foi: %.2f", A * B);
		break;
	}
			case '/': {
		float A, B;
		printf("digitar o primeiro valor:\n ");
		scanf("%f", &A);
		printf("digitar o segundo valor:\n ");
		scanf("%f", &B);
		printf("A Divisão foi: %.2f", A / B);
		break;
	}
 default: printf("Valor Inválido");

}
	
	return 0;
}
