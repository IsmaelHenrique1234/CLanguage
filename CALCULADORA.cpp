#include <stdio.h>
#include <locale.h>
int main () {
	setlocale(LC_ALL, "Portuguese_Brazil");
	char Calculadora;
	printf("Lista de calculos para calcular Adi��o, Subtra��o, Multiplica��o e Divis�o (+, -, * ou /): ");
	scanf("%c", &Calculadora);
	switch (Calculadora) {
	case '+': {
		float A, B;
		printf("digitar o primeiro valor:\n ");
		scanf("%f", &A);
		printf("digitar o segundo valor:\n ");
		scanf("%f", &B);
		printf("A adi��o foi: %.2f", A + B);
		break;
	}
		case '-': {
		float A, B;
		printf("digitar o primeiro valor:\n ");
		scanf("%f", &A);
		printf("digitar o segundo valor:\n ");
		scanf("%f", &B);
		printf("A Substra��o foi: %.2f", A - B);
		break;
	}
			case '*': {
		float A, B;
		printf("digitar o primeiro valor:\n ");
		scanf("%f", &A);
		printf("digitar o segundo valor:\n ");
		scanf("%f", &B);
		printf("A Multipli��o foi: %.2f", A * B);
		break;
	}
			case '/': {
		float A, B;
		printf("digitar o primeiro valor:\n ");
		scanf("%f", &A);
		printf("digitar o segundo valor:\n ");
		scanf("%f", &B);
		printf("A Divis�o foi: %.2f", A / B);
		break;
	}
 default: printf("Valor Inv�lido");

}
	
	return 0;
}
