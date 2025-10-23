#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void Exercicio1(){
//Construir aqui o seu exercício 1
int vetA[5] = {3, 2, 1, 0, 1}, vetB[5] = {2, 2, 2, 2, 2}, vetC[10];
for (int i = 0; i < 5; i++) {
	printf("\nVetor A [%i] = %i", i, vetB[i]);
}
printf("\n");
for (int i = 0; i < 5; i++) {
	printf("\nVetor B [%i] = %i", i, vetB[i]);
}
printf("\n\n"); 
for (int i = 0; i < 5; i++) {
		vetC[i] = vetA[i];
        vetC[5+i] = vetB[i];
}
for (int i = 0; i < 10; i++) {
	printf("Vetor C [%i] = %i\n", i, vetC[i]);
}
system("pause");
system("cls");
}
void Exercicio2(){
//Construir aqui o seu exercício 2
int vetA[5] = {3, 2, 1, 0, 1}, vetB[10] = {2, 2, 2, 2, 2, 1, 1, 1, 1, 1}, vetC[15];
for (int i = 0; i < 5; i++) {
	printf("\nVetor A [%i] = %i", i, vetB[i]);
}
printf("\n");
for (int i = 0; i < 10; i++) {
	printf("\nVetor B [%i] = %i", i, vetB[i]);
}
printf("\n\n"); 
for (int i = 0; i < 5; i++) {
		vetC[i] = vetA[i];
}
for (int i = 0; i < 10; i++) {
        vetC[5+i] = vetB[i];
}
for (int i = 0; i < 15; i++) {
	printf("Vetor C [%i] = %i\n", i, vetC[i]);
}
system("pause");
system("cls");
}
void Exercicio3(){
//Construir aqui o seu exercício
int matriz[3][3];
for (int i = 0; i < 3; i++)
for (int j = 0; j < 3; j++) {
	printf("Ler a matriz [%i][%i] = ", i, j);
	scanf("%i", &matriz[i][j]);
}
for (int i = 0; i < 3; i++) {
	printf("\n");
for (int j = 0; j < 3; j++) 
	printf("%i ", matriz[j][i]);
}
printf("\n\n");
system("pause");
system("cls");
}
void Exercicio4(){
//Construir aqui o seu exercício
char nome[50], sexo[25], endereco[50], email[40], senha[50], cpf[16];
int idade;
printf("Qual seu nome?");
scanf("");
}
void Menu(){
int opc;
 do{
 printf("Menu\n\n");
 printf(" 1 - Exercício 1\n");
 printf(" 2 - Exercício 2\n");
 printf(" 3 - Exercício 3\n");
 printf(" 4 - Exercício 4\n");
 printf(" 0 - Sair\n");
 printf("\nEntre com uma opção: ");
 scanf("%i", &opc);
 switch (opc){
 case 1 :
 Exercicio1();
 break;
 case 2 :
 Exercicio2();
 break;
 case 3 :
 Exercicio3();
 break;
 case 4 :
 Exercicio4();
 break;
case 0:
exit(0);
break;
default :
 printf ("Valor invalido!\n");
 }
}while(opc!=0);
}

int main (){
 setlocale(LC_ALL, "");
 Menu();
 return 0;
}
