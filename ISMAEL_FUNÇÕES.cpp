#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
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
char nome[50], sexo[25], endereco[50], email[40], senha[50], cpf[16], idade[20], reescreverEmail[40], reescreverSenha[50];//todos tem que ser strings
fflush(stdin);//coloquei aqui para evitar o buffer no inicio tambem

printf("Qual seu nome? ");
fgets(nome, 50, stdin);
nome[strcspn(nome, "\n")] = '\0';
fflush(stdin);

printf("Qual seu Sexo? ");
fgets(sexo, 25, stdin);
sexo[strcspn(sexo, "\n")] = '\0';
fflush(stdin);

printf("Qual seu endereço? ");
fgets(endereco, 50, stdin);
endereco[strcspn(endereco, "\n")] = '\0';
fflush(stdin);

printf("Qual seu email? ");
fgets(email, 40, stdin);
email[strcspn(email, "\n")] = '\0';
fflush(stdin);

printf("Qual sua senha? ");
fgets(senha, 50, stdin); //a string senha vai receber até aos limitados 50
senha[strcspn(senha, "\n")] = '\0'; //tirar o quebra linha "\n" escondido do fgets 
fflush(stdin); //limpa o espaço e evita buffer

printf("Qual seu CPF? ");
fgets(cpf, 50, stdin);
cpf[strcspn(cpf, "\n")] = '\0';
fflush(stdin);

printf("Qual sua idade? ");
fgets(idade, 20, stdin);
idade[strcspn(idade, "\n")] = '\0';
fflush(stdin);

printf("Confirma o seu Email: ");
fgets(reescreverEmail, 40, stdin);
reescreverEmail[strcspn(reescreverEmail, "\n")] = '\0';
fflush(stdin);

printf("Confirma a sua Senha: ");
fgets(reescreverSenha, 40, stdin);
reescreverSenha[strcspn(reescreverSenha, "\n")] = '\0';
fflush(stdin);

printf("\n");

if (!(strcmp(email, reescreverEmail) && strcmp(senha, reescreverSenha)))
printf("CADASTRO REALIZADO\n\n");
else
printf("ERRO\n\n");
system("pause");
system("cls");
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
