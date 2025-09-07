#include <stdio.h>
int main() {
    int opcao;
    printf("Digite o numero da questao para escolher: \n");
    printf("LISTA 1: \n");
    printf("Exercicio 1 \n");
    printf("Exercicio 2 \n");
    printf("Exercicio 3 \n");
    printf("Exercicio 4 \n");
    printf("Exercicio 5 \n");
    printf("Exercicio 6 \n");
    printf("Exercicio 7 \n");
    printf("Exercicio 8 \n");
    printf("Exercicio 9 \n");
    printf("Exercicio 10 \n");
    printf("LISTA 2:\n");
    printf("Exercicio 11 \n");
    printf("Exercicio 12 \n");
    printf("Exercicio 13 \n");
    printf("Exercicio 14 \n");
    printf("Exercicio 15 \n");
    scanf("%i", &opcao);

    switch(opcao) {
        case 1: {
    float Celcius, Fahrenheit;
    printf("Digite o Valor do Celcius: ");
    scanf("%f", &Celcius);
    
    Fahrenheit = (9 * Celcius + 160) / 5;
    
    printf ("Valor do Fahrenheit: %.2f\n", Fahrenheit);
			break;
		}
		case 2: {
    float Celcius, Fahrenheit;
 printf("Digita o Valor do Fahrenheit: ");
 scanf("%f", &Fahrenheit);
 
 Celcius = (Fahrenheit - 32) /1.8;
 printf("Valor em Celcius: %.2f\n", Celcius);
			break;
		}
		case 3: {
			float Raio, Altura, Volume;

printf("Digite o Valor do RAIO: ");
scanf("%f", &Raio);

printf("Digite o Valor da ALTURA: ");
scanf("%f", &Altura);

Volume = 3.14 * Raio * Raio * Altura;

printf("O Valor do Volume é: %.2f\n", Volume);
			break;
		}
		case 4: {
		float Distancia, Velocidade, Tempo, Litros_Usados;

printf("Digite o Valor da VELOCIDADE: ");
scanf("%f", &Velocidade);

printf("Digite o Valor do TEMPO: ");
scanf("%f", &Tempo);

Distancia = Velocidade * Tempo;
Litros_Usados = Distancia / 12;

printf("O Valor da Velocidade: %.2f\n", Velocidade);
printf("O Valor de Tempo: %.2f\n", Tempo);
printf("O Valor da Distancia: %.2f\n", Distancia);
printf("O Valor de Litros Usados: %.2f\n", Litros_Usados);
			break;
		}
		case 5: {
		float Prestacao, Valor, Taxa, Tempo;

printf("Digite o Valor da TAXA: ");
scanf("%f", &Taxa);

printf("Digite o Valor do VALOR: ");
scanf("%f", &Valor);

printf("Digite o Valor do TEMPO: ");
scanf("%f", &Tempo);

Prestacao = Valor + (Valor * (Taxa/100) * Tempo);

printf("O Valor da Prestacao fica igual a: %.2f\n", Prestacao);
			break;
		}
		case 6: {
				int A, B, Troca;
	
	printf("Digite o valor de A: ");
	scanf("%i", &A);
	
	printf("Digite o valor de B: ");
	scanf("%i", &B);
	
	Troca = A;
	A = B;
	B = Troca;
	
	printf("Apos a Troca:\n");
	printf("A = %i\n", A);
	printf("B = %i\n", B);
			break;
		}
		case 7: {
		float Comprimento, Largura, Altura, Volume;
	
	printf("Digite o Valor do COMPRIMENTO: ");
	scanf("%f", &Comprimento);
	
	printf("Digite o Valor do LARGURA: ");
	scanf("%f", &Largura);
	
	printf("Digite o Valor do ALTURA: ");
	scanf("%f", &Altura);
	
    Volume = Comprimento * Largura * Altura;
    
    printf("O Volume da Caixa Retângular: %.2f\n", Volume);
			break;
		}case 8: {
			int quadrado, inteiro;
	
	printf("Digite seu numero inteiro: ");
	scanf("%i", &quadrado);
	
	inteiro = quadrado * quadrado;
	
	printf("Seu numero inteiro ao quadrado esta aqui: %i", inteiro);
			break;
		}case 9: {
				int Inteiro1, Inteiro2, Resultado, Quadrado;
	
	printf("Digite o primeiro numero: ");
	scanf("%i", &Inteiro1);
	
	printf("Digite o segundo numero: ");
	scanf("%i", &Inteiro2);
	
	Resultado = Inteiro1 - Inteiro2;
	
	Quadrado = Resultado * Resultado;
	
	printf("A Diferenca foi: %i\n", Resultado);
	printf("A Quadrado da Diferenca foi: %i\n", Quadrado);
			break;
		}
		case 10: {
				float cotacao, dolares, reais;
	
	printf("Digite o valor da cotacao: ");
	scanf("%f", &cotacao);
	
	printf("Digite a quantidade de dolares que possui: ");
	scanf("%f", &dolares);
	
	printf("Digite a quantidade de reais que possui: ");
	scanf("%f", &reais);
	
	reais = cotacao * dolares;
	
	printf("O Valor em Reais foi: %.2f\n", reais);
			break;
		}
		case 11: {
	int numero;
	printf("Digitar o numero: ");
	scanf("%i", &numero);
	if (numero<=0 * -1){
		printf("Negativo virou Positivo: %i", numero * -1);
	}
	else {
		printf("Positivo permanece Positivo: %i", numero);
	}
			break;
		}
		case 12: {
					float Nota1, Nota2, Nota3, Nota4, Media;
	
    printf("Digite a primeira nota: ");
    scanf("%f", &Nota1);
    
    printf("Digite a segunda nota: ");
    scanf("%f", &Nota2);
    
    printf("Digite a terceira nota: ");
    scanf("%f", &Nota3);
    
    printf("Digite a quarta nota: ");
    scanf("%f", &Nota4);
    
    Media = (Nota1 + Nota2 + Nota3 + Nota4) / 4;
    
    printf("A Media foi: %.2f\n", Media);
    if (Media>-1 && Media<11) {
	
    if (Media>=5) {
    	printf("Aprovado");
	} 
	else {
		printf("Reprovado");
	}
}

   else {
   	    printf("VALOR INVALIDO");
   }
			break;
		}
		case 13: {
				float nota1, nota2, nota3, nota4, media, EXAME, NovaMedia;
	printf("Digite a primeira nota: ");
	scanf("%f", &nota1);
	
	printf("Digite a segunda nota: ");
	scanf("%f", &nota2);
	
	printf("Digite a terceira nota: ");
	scanf("%f", &nota3);
	
	printf("Digite a quarta nota: ");
	scanf("%f", &nota4);
	
	media = (nota1 + nota2 + nota3 + nota4) / 4;
	
	
	if (media >= 7) {
	printf("APROVADO");
}
   else {
    	printf("Digite a nota do exame: ");
		scanf("%f", &EXAME);
   
   
   NovaMedia = (EXAME + media) / 2;
   
   	if (NovaMedia>=5) {
   		
    	printf("Aprovado em Exame");	
	}	
   else {
   	printf("REPROVADO");
   }
}
			break;
		}
	   	case 14: {
	   		float valor1, valor2, valor3;
	
	printf("Digitar o Primeiro valor: ");
	scanf("%f", &valor1);
	
	printf("Digitar o Segundo valor: ");
	scanf("%f", &valor2);
	
	printf("Digitar o Terceiro valor: ");
	scanf("%f", &valor3);
	
	if (valor1 < valor2 && valor2 < valor3) {
		printf("O primeiro valor foi o menor\nO segundo valor foi o mediano\nO terceiro valor foi o maior");
	}
	else if (valor3 < valor2 && valor2 < valor1) {
		printf("O terceiro valor foi o menor\nO segundo valor foi o mediano\nO primeiro valor foi o maior ");
	}
	else if (valor2 < valor3 && valor3 < valor1) {
		printf("O segundo valor foi o menor\nO terceiro valor foi o mediano\nO primeiro valor foi o maior ");
	}
	else if (valor1 < valor3 && valor3 < valor2) {
		printf("O primeiro valor foi o menor\nO terceiro valor foi o mediano\nO segundo valor foi o maior ");
	}
	else if (valor2 < valor1 && valor1< valor3) {
		printf("O segundo valor foi o menor\nO primeiro valor foi o mediano\nO terceiro valor foi o maior ");
	}
	else if (valor3 < valor1 && valor1 < valor2) {
		printf("O terceiro valor foi menor\nO primeiro valor foi o mediano\nO segundo valor foi o maior");
	}
	else if (valor1 == valor2 && valor2 == valor3) {
		printf("Valores todos iguais");
	}
	else {
		printf("Invalido");
	}
			break;
		}
        case 15: {
        		int n1, n2, n3, n4;
	
	printf("Digitar valor do primeiro: ");
	scanf("%i", &n1);
	
	printf("Digitar valor do segundo: ");
	scanf("%i", &n2);
	
	printf("Digitar valor do terceiro: ");
	scanf("%i", &n3);
	
	printf("Digitar valor do quarto: ");
	scanf("%i", &n4);
	
	if (n1 % 2 == 0 && n1 % 3 == 0) {
		printf("PRIMEIRO: Divisivel pra ambos\n");
	}
	else {
			printf("PRIMEIRO: nao disivivel pra ambos\n");
		}
	if (n2 % 2 == 0 && n2 % 3 == 0) {
		printf("SEGUNDO: Divisivel pra ambos\n");
	}
	else {
			printf("SEGUNDO: nao disivivel pra ambos\n");
		}
	if (n3 % 2 == 0 && n3 % 3 == 0) {
		printf("TERCEIRO: Divisivel pra ambos\n");
	}
	else {
			printf("TERCEIRO: nao disivivel pra ambos\n");
		}
	if (n4 % 2 == 0 && n4 % 3 == 0) {
		printf("QUARTO: Divisivel pra ambos\n");
	}
	else {
			printf("QUARTO: nao disivivel pra ambos\n");
		}
		break;
		}
    }

    return 0;
}

