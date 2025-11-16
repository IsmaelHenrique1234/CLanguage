#include <stdio.h> //me custou horas codando e debbugando
#include <stdlib.h>
#include <string.h>
#include <locale.h>
const int MAX=50;// limitando o tamanho do vetor
int ordenado=0;// variável p/ controlar a ordenação dos dados
// Tipo de dado especial (Registro)
typedef struct TProduto{
    long int codigo;
    char nome[21];
    int  grupo;
    char descricao[41];
    char unidade[3];
    char fornecedor[41];
    float quantidade;
    float pr_compra;
    float pr_venda;
    int lucroMin;
    float estoque_min;
    float quantidadeComprada;
    float lucro;
}Tproduto;

//escopo do programa/funções criadas, TOTAL = 15
void leitura(Tproduto estoque[], int *tamanho);//gera o arquivo .dat na primeira vez
void gravacao(Tproduto estoque[], int tamanho);// realiza a gravação dos dado no arquivo
int pesquisabinaria(Tproduto estoque[], int chave, int tamanho);// busca e retorna a posição do produto no vetor
void pesquisaSequencial(Tproduto estoque[], int tamanho);
int vazio (int tamanho);// função auxiliar para da pesquisa binária
void ordena(Tproduto estoque[], int tamanho);//ordena o cadastro dos produtos por código
void inclusao(Tproduto estoque[],int *tamanho);
int gerarCodigo(Tproduto estoque[], int tamanho);
void relatorio_produto (Tproduto estoque[], int tamanho);
void relatorio_lista (Tproduto estoque[], int tamanho);
void relatorio_margemLucro (Tproduto estoque[], int tamanho);
void consulta(Tproduto estoque[], int tamanho);
void excluir (Tproduto estoque[], int *tamanho);
void altera (Tproduto estoque[], int *tamanho);
void movimentacao (Tproduto estoque[], int *tamanho);

int main(){
	setlocale(LC_ALL, "");
	Tproduto estoque[MAX];
    int tamanho=0, opc, opcao;
    leitura(estoque, &tamanho);// abre o arquivo da base de dados
    do{
        printf ("\n (1)- CADASTRAR\t(5)- RELATÓRIO DOS PRODUTOS\n");
        printf (" (2)- CONSULTAR\t(6)- RELATÓRIO DAS PREÇO\n");
    	printf (" (3)- ALTERAR\t(7)- RELATÓRIO DE MARGEM DE LUCRO\n");
        printf (" (4)- EXCLUIR\t(8)- MOVIMENTAÇÃO DE COMPRAS\n");
        printf ("\t(0)- SAIR\n");
        printf ("\nESCOLHA A OPÇÃO DESEJADA:\n");
        scanf ("%d",&opcao); fflush(stdin);
        system("cls");
        switch (opcao){
            case 1:{
            	inclusao(estoque, &tamanho);
            	gravacao(estoque, tamanho);
				break;
			}
			case 2:{
				int opc;
            	consulta(estoque, tamanho);
				break;
			}
			case 3:{
				altera (estoque, &tamanho);
				gravacao(estoque, tamanho);
				break;
			}
		    case 4:{
				excluir (estoque, &tamanho);
				gravacao(estoque, tamanho);
				break;
			}           	
            case 5:{
				int opc;
				relatorio_produto(estoque, tamanho);
				break;
			}
			case 6:{
				int opc;
				relatorio_lista(estoque, tamanho);
				break;
			}
			case 7:{
				int opc;
				relatorio_margemLucro (estoque, tamanho);
				break;
			}
			case 8:{
				movimentacao (estoque, &tamanho);
				gravacao(estoque, tamanho);
				break;
			}

            case 0: 
				printf("Obrigado por usar nosso sistema.\n");
				system("pause");
				exit(0);
				break;
            default: printf("OPCÃO INVÁLIDA!\n");
            	system("pause");
            	system("cls");
        }
    }while (opcao!=0);
             gravacao(estoque, tamanho); // grava após realizada as operações
	return 0;
}

void leitura(Tproduto estoque[], int *tamanho){
    FILE *arquivo;
  	arquivo= fopen("estoque.dat", "a+b");	   /* abrimos para anexar, binário */ 
  	if (!arquivo){
  		printf("Erro ao abrir arquivo!");
  		return;
  	}
//le os dados do arquivo
    while(!feof(arquivo)){
       fread (&estoque[*tamanho], sizeof (Tproduto) , 1, arquivo);
       (*tamanho)++;
    }
	(*tamanho)--;
//fecha o arquivo
	fclose(arquivo);
	return;
}

void gravacao(Tproduto estoque[], int tamanho){
    FILE *arquivo;
    int i;
    arquivo= fopen("estoque.dat", "w+b");	   /* abre e apaga o conteúdo do arquivo,binário */ 
  	if (!arquivo){
  		printf("Erro ao abrir arquivo!");
  		return;
  	}
// grava a estrutura no arquivo
    for(i=0;i<tamanho;i++)  
       fwrite(&estoque[i], sizeof(Tproduto), 1, arquivo);
// Fecha o arquivo de dados
	fclose(arquivo);
	return;
}

int pesquisabinaria(Tproduto estoque[], int chave, int tamanho){
    if(vazio(tamanho))
       return -1;// vetor vazio       
    if (! ordenado){
        ordena(estoque,tamanho);// ordena
        ordenado=1;// variavel global
    }
    int inicio=0,final=tamanho, meio;
    while (inicio<=final){
        meio=(int)(inicio+final)/2;
        if (estoque[meio].codigo==chave)
           return meio; // encontrou
        if (estoque[meio].codigo<chave)
           inicio=meio+1;
        else
           final=meio-1;
    }
    return -1; // não encontrou
}
int pesquisaSequencial(Tproduto estoque[], char chave[], int tamanho) {
    for (int i = 0; i < tamanho; i++) { // Compara apenas o início do nome com a chave
        if (strncmp(estoque[i].nome, chave, strlen(chave)) == 0) {
            return i; // Retorna a posição do primeiro encontrado
        }
    }

    return -1; // Não encontrado
}

int vazio(int tamanho){
     if(tamanho==0){
        return 1;// vazio
     }
     return 0;// preenchido
}

void ordena(Tproduto estoque[], int tamanho){
	int i,j;
    Tproduto aux;
    for(i=0;i<tamanho-1;i++)
        for(j=i+1;j<tamanho;j++)
          	if (estoque[i].codigo>estoque[j].codigo){
              	aux=estoque[i];
              	estoque[i]=estoque[j];
              	estoque[j]=aux;
            }
}
int gerarCodigo(Tproduto estoque[], int tamanho) { //função de gerar codigo e evitar duplicação de codigos
    int codigo = 1; //começar sempre com o menor número possivel = 1
    for (int i = 0; i < tamanho; i++) { //verificação do codigo
        if (estoque[i].codigo == codigo)
            codigo++;
        else
            break;
    }
    return codigo; //Retorna o menor código disponível
}
void inclusao(Tproduto estoque[],int *tamanho){
             if (*tamanho==MAX){ 
                   printf ("\n ERRO! \n ARQUIVO CHEIO.\n");
                   return;
             }
             Tproduto aux;
             char correto='n';
            if (pesquisabinaria(estoque, aux.codigo, *tamanho) <0){
            	aux.codigo = gerarCodigo(estoque, *tamanho); //AUX.CODIGO recebe o codigo da função
            	do{
                        printf ("Nome do Produto ...................................: "); //Por que "20[^\n]s"?, É pra considerar Espaços, ou usar funcao GETS pra facilitar a vida
                        scanf ("%20[^\n]s",&aux.nome);
						fflush(stdin);
                    }while(aux.nome<0);
            	  do{
                        printf ("Grupo do Produto ..................................: ");
                        scanf ("%d",&aux.grupo);
						fflush(stdin);
                    }while(aux.grupo<0);
                  do{
                        printf ("Descrição do Produto ..............................: ");
                        scanf ("%40[^\n]s",&aux.descricao);
						fflush(stdin);
                    }while(aux.descricao<0);
                  do{
                        printf ("Unidade do Produto ................................: ");
                        scanf ("%s",&aux.unidade);
						fflush(stdin);
                    }while(aux.unidade<0);
                  do{
                        printf ("Nome do Fornecedor ................................: ");
                        scanf ("%40[^\n]s",&aux.fornecedor);
						fflush(stdin);
                    }while(aux.fornecedor<0);
                  do{
                        printf ("Quantidade do produto .............................: ");
                        scanf ("%f",&aux.quantidade);
						fflush(stdin);
                    }while(aux.quantidade<0);
                  do{
                  		printf ("Preço de compra do produto ........................: ");
                  		scanf ("%f",&aux.pr_compra);
						fflush(stdin);
				  }while(aux.pr_compra<0);
				  do{
                  		printf ("Preço de venda do produto .........................: ");
                  		scanf ("%f",&aux.pr_venda);
						fflush(stdin);
				  }while(aux.pr_venda<0);
				  do{
                  		printf ("Margem de lucro mínima (em Porcentagem) ...........: ");
                  		scanf ("%d",&aux.lucroMin);
						fflush(stdin);
				  }while(aux.lucroMin<0);
				  do{
                  		printf ("Quantidade mínima em estoque ......................: ");
                  		scanf ("%f",&aux.estoque_min);
						fflush(stdin);
				  }while(aux.estoque_min<0);
				  aux.lucro = ((aux.pr_venda - aux.pr_compra) / aux.pr_venda) * 100;
				  do {
				  printf ("Os dados estao corretos?(S/N): ");
                  correto=getchar();
				  fflush(stdin);
				  if (correto != 's' && correto != 'S' && correto != 'n' && correto != 'N')
				  printf("\nOPÇÃO INVALIDA\n\n");
			      }
                  while(correto != 's' && correto != 'S' && correto != 'n' && correto != 'N');
                  if (correto=='s'||correto=='S'){
                       estoque [*tamanho] = aux;// faz a transferência
                       (*tamanho) ++;
                       ordenado=0;
                       printf ("\tO CADASTRO FOI INCLUIDO!\n");
					fflush(stdin);
                  }
                  else if (correto=='n' || correto=='N'){ 
                       printf ("\tO CADASTRO NÃO FOI INCLUIDO!\n");
				  }
			}else 
    			printf ("\tCODIGO JA CADASTRADO!!\n");
    printf("\tAPERTE ENTER PARA VOLTAR AO MENU");
    fflush(stdin);
    getchar();
    system("cls");
    return;
}
void consulta(Tproduto estoque[], int tamanho) {
	     if(tamanho==0){
        printf("\nREGISTRO VAZIO!\n\n");
        system("pause");
        system("cls");
        return;
     }
     int selecao;
     do {
     printf("COMO VOCÊ GOSTARIA DE PESQUISAR?\n\n(1) - CÓDIGO (Binária)\n(2) - NOME (Sequencial)\n\nEscolher de acordo com o número (ou 0 para voltar): ");
     scanf("%d", &selecao); fflush(stdin);
     if (selecao == 0) {
     system("cls");
     return;
     } 
 } while (selecao != 0 && selecao != 1 && selecao != 2);
     switch (selecao) {
     	case 1: {
     		fflush(stdin);
            int posicao, i, codigo;
            char confirma;
            printf("Digitar Código......: ");
	        scanf("%d", &codigo);fflush(stdin);
            posicao=pesquisabinaria(estoque, codigo, tamanho);
    if (posicao>=0) {//encontrou registro
    printf("\n===========================================================================\n");
    printf("Codigo: %ld\t\tNome do Produto: %s\t\tGrupo: %d\n\nDescrição: %s\tUnidade: %s\n\nFornecedor: %s\n\nPreço de Compra: %.2f \tPreço de Venda: %.2f \tLucro Mínimo: %d%% \n\nQuantidade em Estoque: %.2f\t\tQuantidade Mínima: %.2f\n",
	estoque[posicao].codigo, estoque[posicao].nome, estoque[posicao].grupo, estoque[posicao].descricao, estoque[posicao].unidade, estoque[posicao].fornecedor, estoque[posicao].pr_compra, estoque[posicao].pr_venda, estoque[posicao].lucroMin, estoque[posicao].quantidade, estoque[posicao].estoque_min);
	printf("---------------------------------------------------------------------------\n\n");
	printf("APERTE ENTER PARA VOLTAR AO MENU"); 
	getchar(); fflush(stdin);
	system("cls");
	return;
		 }
		 else {
		 	printf("\nO REGISTRO NÃO EXISTE\n\n");
		 	printf("APERTE ENTER PARA VOLTAR AO MENU");
		 	getchar(); fflush(stdin);
		 	system("cls");
		 	return;
		 }
		 break;
	 }
	 case 2: {
	 int posicao, i, selecao;
	 char busca[21];
     char confirma, correto; // uma pra confirmar o codigo e outra para a alteração
     Tproduto aux;
     printf("Inserir o nome para alterar o codigo......: ");
	 fgets(busca, 21, stdin);
     busca[strcspn(busca, "\n")] = '\0'; //essencial para pular virgula
     posicao=pesquisaSequencial(estoque, busca, tamanho);
          if (posicao>=0) {//encontrou registro
    printf("\n===========================================================================\n");
    printf("Codigo: %ld\tNome do Produto: %s\t\tGrupo: %d\n\nDescrição: %s\tUnidade: %s\n\nFornecedor: %s\n\nPreço de Compra: %.2f \tPreço de Venda: %.2f \tLucro Mínimo: %d%% \n\nQuantidade em Estoque: %.2f\t\tQuantidade Mínima: %.2f\n",
	estoque[posicao].codigo, estoque[posicao].nome, estoque[posicao].grupo, estoque[posicao].descricao, estoque[posicao].unidade, estoque[posicao].fornecedor, estoque[posicao].pr_compra, estoque[posicao].pr_venda, estoque[posicao].lucroMin, estoque[posicao].quantidade, estoque[posicao].estoque_min);
	printf("---------------------------------------------------------------------------\n\n");
	printf("APERTE ENTER PARA VOLTAR AO MENU"); 
	getchar(); fflush(stdin);
	system("cls");
	return;
	 }
	 	else {
		 	printf("\nO REGISTRO NÃO EXISTE\n\n");
		 	printf("APERTE ENTER PARA VOLTAR AO MENU");
		 	getchar(); fflush(stdin);
		 	system("cls");
		 	return;
		 }
		break;
	 }
}
}
void relatorio_produto (Tproduto estoque[], int tamanho){
	int i;
	    if(tamanho==0){
        printf("\nREGISTRO VAZIO!\n\n");
        system("pause");
        system("cls");
        return;
     }
    printf("\t\tControle de Estoque - Relatorio dos Produtos\n");
    for( i=0; i<tamanho; i++) {
    ordena(estoque, tamanho);
    if (estoque[i].estoque_min > estoque[i].quantidade){ //MOSTRA ALERTA DO ESTOQUE
    printf("\n===================================================================================\n");
    printf("Codigo: %-4ld\tNome do Produto: %-20.20s\tGrupo: %-2d\n\nDescrição: %-40.40s\tUnidade: %-2.2s\n\nFornecedor: %-40.40s\n\nPreço de Compra: R$ %-5.2f\tPreço de Venda: R$ %-5.2f\tLucro Mínimo: %d%% \n\nQuantidade em Estoque: %-5.2f\t\tQuantidade Mínima: %.2f\n\n\t\tALERTA: ESTOQUE ABAIXO DO MÍNIMO\n",
	estoque[i].codigo, estoque[i].nome, estoque[i].grupo, estoque[i].descricao, estoque[i].unidade, estoque[i].fornecedor, estoque[i].pr_compra, estoque[i].pr_venda, estoque[i].lucroMin, estoque[i].quantidade, estoque[i].estoque_min);
	printf("-----------------------------------------------------------------------------------\n\n"); }
	else { //MOSTRA NORMALMENTE
	printf("\n===================================================================================\n");
    printf("Codigo: %-4ld\tNome do Produto: %-20.20s\tGrupo: %-2d\n\nDescrição: %-40.40s\tUnidade: %-2.2s\n\nFornecedor: %-40.40s\n\nPreço de Compra: R$ %-10.2f\tPreço de Venda: R$ %-10.2f\tLucro Mínimo: %d%% \n\nQuantidade em Estoque: %-5.2f\t\tQuantidade Mínima: %.2f\n",
	estoque[i].codigo, estoque[i].nome, estoque[i].grupo, estoque[i].descricao, estoque[i].unidade, estoque[i].fornecedor, estoque[i].pr_compra, estoque[i].pr_venda, estoque[i].lucroMin, estoque[i].quantidade, estoque[i].estoque_min);
	printf("-----------------------------------------------------------------------------------\n\n");
	}
    if (i % 2 == 1 && i < tamanho - 1) { //Poderio criar outra variavel para contar o número de listas, mas isso também funciona
        system("pause");
        system("cls");
    }
}
    printf("APERTE ENTER PARA VOLTAR AO MENU\n");
    getchar(); fflush(stdin);
    system("cls");
}
void relatorio_lista (Tproduto estoque[], int tamanho){
	if(tamanho==0){
        printf("\nREGISTRO VAZIO!\n\n");
        system("pause");
        system("cls");
        return;
     }
		int linhas = 0;
    //cabelhaço
    printf("=====================================================================\n");
    printf("Codigo     Descrição                                Preço\n");

    for (int i = 0; i < tamanho; i++) {
        //Linha de preços
        printf("%-10d %-40.40s R$ %-8.2f\n",estoque[i].codigo, estoque[i].descricao, estoque[i].pr_venda);
        linhas++;
        //Controle de pagina
        if (linhas == 15 && i < tamanho - 1) {
            printf("---------------------------------------------------------------------\n");
            system("pause");
            system("cls");
            //Reimpremir cabelhaço
            printf("=====================================================================\n");
            printf("Codigo     Descrição                                Preço\n");
            linhas = 0; //RESETAR AS LINHAS PARA CONTAR ATÉ 15 TUDO DENOVO
        }
    }
    printf("---------------------------------------------------------------------\n");
    printf("APERTE ENTER PARA VOLTAR AO MENU");
    fflush(stdin);
    getchar();
    system("cls");
}
void relatorio_margemLucro(Tproduto estoque[], int tamanho){
	if(tamanho==0){
        printf("\nREGISTRO VAZIO!\n\n");
        system("pause");
        system("cls");
        return;
     }
	int linhas = 0;


    //cabelhaço
    printf("============================================================================================\n");
    printf("Codigo\t\tCusto\t\tVenda\t\tMargem Atual\tMargem Minima\t   Status\n");

    for (int i = 0; i < tamanho; i++) {
        //Linha de preços
        if (estoque[i].lucro < estoque[i].lucroMin)
    printf("%-10d\tR$%-8.2f\tR$ %-8.2f\t%-3.0f%%\t\t%-3d%%\t\t   ABAIXO\n",estoque[i].codigo, estoque[i].pr_compra, estoque[i].pr_venda, estoque[i].lucro, estoque[i].lucroMin);
        else
        printf("%-10d\tR$%-8.2f\tR$ %-8.2f\t%-3.0f%%\t\t%-3d%%\t\t   OK\n",estoque[i].codigo, estoque[i].pr_compra, estoque[i].pr_venda, estoque[i].lucro, estoque[i].lucroMin);
        linhas++;
        //Controle de pagina
        if (linhas == 15 && i < tamanho - 1) {
    printf("--------------------------------------------------------------------------------------------\n");
            system("pause");
            system("cls");
            //Reimpremir cabelhaço
            printf("============================================================================================\n");
            printf("Codigo     Descrição                                Preço\n");
            linhas = 0; //RESETAR AS LINHAS PARA CONTAR ATÉ 15 TUDO DENOVO
        }
    }

    printf("--------------------------------------------------------------------------------------------\n");
    printf("APERTE ENTER PARA VOLTAR AO MENU");
    fflush(stdin);
    getchar();
    system("cls");
}
void excluir (Tproduto estoque[], int *tamanho){
     if(*tamanho==0){
        printf("\nREGISTRO VAZIO!\n\n");
        system("pause");
        system("cls");
        return;
     }
     int selecao;
     do {
     printf("COMO VOCÊ GOSTARIA DE PESQUISAR?\n\n(1) - CODÍGO (Binária)\n(2) - NOME (Sequencial)\n\nEscolher de acordo com o número (ou 0 para voltar): ");
     scanf("%d", &selecao); fflush(stdin);
     if (selecao == 0) {
     system("cls");
     return;
     }
     else
     system("cls");
     } while (selecao != 1 && selecao != 2 && selecao != 0);
     switch (selecao){
	    case 1: {
	    	fflush(stdin);
            int posicao, i, codigo;
            char confirma;
            printf("Codigo a ser excluido......: ");
	        scanf("%d", &codigo);fflush(stdin);
            posicao=pesquisabinaria(estoque, codigo, *tamanho);
     if (posicao>=0) {//encontrou registro
    printf("\n===========================================================================\n");
    printf("Codigo: %ld\t\tNome do Produto: %s\t\tGrupo: %d\n\nDescrição: %s\tUnidade: %s\n\nFornecedor: %s\n\nPreço de Compra: %.2f \tPreço de Venda: %.2f \tLucro Mínimo: %d%% \n\nQuantidade em Estoque: %.2f\t\tQuantidade Mínima: %.2f\n",
	estoque[posicao].codigo, estoque[posicao].nome, estoque[posicao].grupo, estoque[posicao].descricao, estoque[posicao].unidade, estoque[posicao].fornecedor, estoque[posicao].pr_compra, estoque[posicao].pr_venda, estoque[posicao].lucroMin, estoque[posicao].quantidade, estoque[posicao].estoque_min);
	printf("---------------------------------------------------------------------------\n\n");
	        do {
     		printf("Confirma a exclusao do registro desse produto? (S/N) ");fflush(stdin);
            confirma=getchar(); fflush(stdin);
            if (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N')
            printf("\nOPÇÃO INVALIDA\n\n");
        }
        while(confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N');
            if (confirma == 's' || confirma == 'S'){
                for (i=posicao;i<(*tamanho)-1;i++) // copia os dados do proximo registro para o anterior
                    estoque[i]=estoque[i+1];
            (*tamanho)--;
        	printf("REGISTRO REMOVIDO!\n\n");
            }else if (confirma == 'n' || confirma == 'N')
                printf("\n O REGISTRO NÃO FOI EXCLUIDO!\n\n");
            else {
            	printf("\n DIGITAR UM VALOR VALIDO!\n\n");
            	system("pause");
            	system("cls");
            	return;
			}
     }else
         printf("O REGISTRO NÃO FOI LOCALIZADO!\n\n"); 
         printf("APERTE ENTER PARA VOLTAR AO MENU");
         getchar();
         system("cls");
         return;
         break;
         }
    case 2: {
    	fflush(stdin);
        int posicao, i;
		char busca[21];
        char confirma;
        printf("Nome a ser excluído: ");
        fgets(busca, 21, stdin);
        busca[strcspn(busca, "\n")] = '\0'; //Tira o quebra linha "\n" e recoloca para "\0"
        posicao=pesquisaSequencial(estoque, busca, *tamanho);
     if (posicao>=0) {//encontrou registro
    printf("\n===========================================================================\n");
    printf("Codigo: %ld\t\tNome do Produto: %s\t\tGrupo: %d\n\nDescrição: %s\tUnidade: %s\n\nFornecedor: %s\n\nPreço de Compra: %.2f \tPreço de Venda: %.2f \tLucro Mínimo: %d%% \n\nQuantidade em Estoque: %.2f\t\tQuantidade Mínima: %.2f\n",
	estoque[posicao].codigo, estoque[posicao].nome, estoque[posicao].grupo, estoque[posicao].descricao, estoque[posicao].unidade, estoque[posicao].fornecedor, estoque[posicao].pr_compra, estoque[posicao].pr_venda, estoque[posicao].lucroMin, estoque[posicao].quantidade, estoque[posicao].estoque_min);
	printf("---------------------------------------------------------------------------\n\n");
	        do {
     		printf("Confirma a exclusao do registro desse produto? (S/N) ");fflush(stdin);
            confirma=getchar(); fflush(stdin);
            if (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N')
            printf("\nOPÇÃO INVALIDA\n\n");
        }
        while(confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N');
            if (confirma == 's' || confirma == 'S'){
                for (i=posicao;i<(*tamanho)-1;i++) // copia os dados do proximo registro para o anterior
                    estoque[i]=estoque[i+1];
            (*tamanho)--;
        	printf("REGISTRO REMOVIDO!\n\n");
            }else if (confirma == 'n' || confirma == 'N')
                printf("\n O REGISTRO NÃO FOI EXCLUIDO!\n\n");
            else {
            	printf("\n DIGITAR UM VALOR VALIDO!\n\n");
            	system("pause");
            	system("cls");
            	return;
			}
     }else
         printf("O REGISTRO NÃO FOI LOCALIZADO!\n\n"); 
         printf("APERTE ENTER PARA VOLTAR AO MENU");
         getchar();
         system("cls");
         return;
     }
		break;
	}     		
	 }
void altera (Tproduto estoque[], int *tamanho){
     if(*tamanho==0){
        printf("\nREGISTRO VAZIO!\n\n");
        system("pause");
        system("cls");
        return;
     }
     
     int selecao;
     do {
     printf("COMO VOCÊ GOSTARIA DE PESQUISAR?\n\n(1) - CODÍGO (Binária)\n(2) - NOME (Sequencial)\n\nEscolher de acordo com o número (ou 0 para voltar): ");
     scanf("%d", &selecao); fflush(stdin);
     if (selecao == 0) {
     system("cls");
     return;
     }
     else
     system("cls");
     } while (selecao != 1 && selecao != 2 && selecao != 0);
     
     switch (selecao) {
     case 1: {
     int posicao, i, codigo, selecao;
     char confirma, correto; // uma pra confirmar o codigo e outra para a alteração
     Tproduto aux;
     printf("Codigo a ser alterado......: ");
	 scanf("%d", &codigo);fflush(stdin);
     posicao=pesquisabinaria(estoque, codigo, *tamanho);
     if (posicao>=0) {//encontrou registro
    printf("\n===========================================================================\n");
    printf("Codigo: %ld\tNome do Produto: %s\t\tGrupo: %d\n\nDescrição: %s\tUnidade: %s\n\nFornecedor: %s\n\nPreço de Compra: %.2f \tPreço de Venda: %.2f \tLucro Mínimo: %d%% \n\nQuantidade em Estoque: %.2f\t\tQuantidade Mínima: %.2f\n",
	estoque[posicao].codigo, estoque[posicao].nome, estoque[posicao].grupo, estoque[posicao].descricao, estoque[posicao].unidade, estoque[posicao].fornecedor, estoque[posicao].pr_compra, estoque[posicao].pr_venda, estoque[posicao].lucroMin, estoque[posicao].quantidade, estoque[posicao].estoque_min);
	printf("---------------------------------------------------------------------------\n\n");
	        do {
     		printf("Confirma a alteração do registro desse produto? (S/N): ");fflush(stdin);
            confirma=getchar(); fflush(stdin);
            if (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N')
            printf("\nOPÇÃO INVALIDA\n\n");
            }
            while (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N');
            if (confirma == 's' || confirma == 'S'){
                printf("\nQual desses você vai escolher pra alterar?\n\n");
                printf("(1) - Nome\n");
                printf("(2) - Grupo\n");
				printf("(3) - Descriçao\n");
				printf("(4) - Unidade\n");
				printf("(5) - Fornecedor\n");
				printf("(6) - Quantidade em Estoque\n");
				printf("(7) - Preço de Compra\n");
				printf("(8) - Preço de Venda\n");
				printf("(9) - Margem de Lucro Mínimo\n");
				printf("(10) - Quantidade Mínima\n\n");
				do {
                printf("Escolher de acordo com o numero: ");
                scanf("%d", &selecao); fflush(stdin);
                if (selecao < 1 || selecao > 10)
                printf("\nNÚMERO INVALIDO\n\n"); 
                }
                while (selecao < 1 || selecao > 10);
            switch (selecao) {
            	case 1: {
            		fflush(stdin);
            		do{
                        printf ("Nome do Produto ...................................: ");
                        scanf ("%20[^\n]s",&estoque[posicao].nome);
						fflush(stdin);
                    }while(aux.nome<0);
					break;
				}
            	case 2: {
            		fflush(stdin);
            		do{
                        printf ("Grupo do Produto ..................................: ");
                        scanf ("%d",&estoque[posicao].grupo);
						fflush(stdin);
                    }while(aux.grupo<0);
					break;
				}
				case 3: {
					fflush(stdin);
            		do{
                        printf ("Descrição ..................................: ");
                        scanf ("%40[^\n]s",&estoque[posicao].descricao); 
						fflush(stdin);
                    }while(aux.descricao<0);
					break;
				}
				case 4: {
					fflush(stdin);
            		do{
                        printf ("Unidade ..................................: ");
                        scanf ("%2[^\n]s",&estoque[posicao].unidade); 
						fflush(stdin);
                    }while(aux.unidade<0);
					break;
				}
				case 5: {
					fflush(stdin);
            		do{
                        printf ("Fornecedor ..................................: ");
                        scanf ("%40[^\n]s",&estoque[posicao].fornecedor); 
						fflush(stdin);
                    }while(aux.fornecedor<0);
					break;
				}
				case 6: {
					fflush(stdin);
            		do{
                        printf ("Quantidade em Estoque ..................................: ");
                        scanf ("%f",&estoque[posicao].quantidade); 
						fflush(stdin);
                    }while(aux.quantidade<0);
					break;
				}
				case 7: {
					fflush(stdin);
            		do{
                        printf ("Preço de Compra ..................................: ");
                        scanf ("%f",&estoque[posicao].pr_compra); 
						fflush(stdin);
						aux.lucro = ((aux.pr_venda - aux.pr_compra) / aux.pr_venda) * 100;
                    }while(aux.pr_compra<0);
					break;
				}
				case 8: {
					fflush(stdin);
            		do{
                        printf ("Preço de Venda ..................................: ");
                        scanf ("%f",&estoque[posicao].pr_venda); 
						fflush(stdin);
						aux.lucro = ((aux.pr_venda - aux.pr_compra) / aux.pr_venda) * 100;
                    }while(aux.pr_venda<0);
					break;
				}
				case 9: {
					fflush(stdin);
            		do{
                        printf ("Margem de Lucro Mínimo ..................................: ");
                        scanf ("%d",&estoque[posicao].lucroMin); 
						fflush(stdin);
                    }while(aux.lucroMin<0);
					break;
				}
				case 10: {
					fflush(stdin);
            		do{
                        printf ("Quantidade Mínima ..................................: ");
                        scanf ("%f",&estoque[posicao].estoque_min); 
						fflush(stdin);
                    }while(aux.estoque_min<0);
					break;
				}
			}
			printf("\nREGISTRO ALTERADO COM SUCESSO!\n\n");
            }else if (confirma == 'n' || confirma == 'N')
                printf("\n O REGISTRO NÃO FOI ALTERADO!\n\n");
            else {
            	printf("\n DIGITAR UM VALOR VALIDO!\n\n");
            	system("pause");
            	system("cls");
            	return;
			}
     }
 else
    printf("O REGISTRO NÃO FOI LOCALIZADO!\n\n");
    printf("APERTE ENTER PARA VOLTAR AO MENU");
    getchar();
    system("cls");
    return;
    break;
}
case 2: {
	 int posicao, i, selecao;
	 char busca[21];
     char confirma, correto; // uma pra confirmar o codigo e outra para a alteração
     Tproduto aux;
     printf("Inserir o nome para alterar o codigo......: ");
	 fgets(busca, 21, stdin);
     busca[strcspn(busca, "\n")] = '\0';
     posicao=pesquisaSequencial(estoque, busca, *tamanho);
     if (posicao>=0) {//encontrou registro
    printf("\n===========================================================================\n");
    printf("Codigo: %ld\tNome do Produto: %s\t\tGrupo: %d\n\nDescrição: %s\tUnidade: %s\n\nFornecedor: %s\n\nPreço de Compra: %.2f \tPreço de Venda: %.2f \tLucro Mínimo: %d%% \n\nQuantidade em Estoque: %.2f\t\tQuantidade Mínima: %.2f\n",
	estoque[posicao].codigo, estoque[posicao].nome, estoque[posicao].grupo, estoque[posicao].descricao, estoque[posicao].unidade, estoque[posicao].fornecedor, estoque[posicao].pr_compra, estoque[posicao].pr_venda, estoque[posicao].lucroMin, estoque[posicao].quantidade, estoque[posicao].estoque_min);
	printf("---------------------------------------------------------------------------\n\n");
	        do {
     		printf("Confirma a alteração do registro desse produto? (S/N): ");fflush(stdin);
            confirma=getchar(); fflush(stdin);
            if (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N')
            printf("\nOPÇÃO INVALIDA\n\n");
            }
            while (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N');
            if (confirma == 's' || confirma == 'S'){
                printf("\nQual desses você vai escolher pra alterar?\n\n");
                printf("(1) - Nome\n");
                printf("(2) - Grupo\n");
				printf("(3) - Descriçao\n");
				printf("(4) - Unidade\n");
				printf("(5) - Fornecedor\n");
				printf("(6) - Quantidade em Estoque\n");
				printf("(7) - Preço de Compra\n");
				printf("(8) - Preço de Venda\n");
				printf("(9) - Margem de Lucro Mínimo\n");
				printf("(10) - Quantidade Mínima\n\n");
				do {
                printf("Escolher de acordo com o numero: ");
                scanf("%d", &selecao); fflush(stdin);
                if (selecao < 1 || selecao > 10)
                printf("\nNÚMERO INVALIDO\n\n"); 
                }
                while (selecao < 1 || selecao > 10);
            switch (selecao) {
            	case 1: {
            		fflush(stdin);
            		do{
                        printf ("Nome do Produto ...................................: ");
                        scanf ("%20[^\n]s",&estoque[posicao].nome);
						fflush(stdin);
                    }while(aux.nome<0);
					break;
				}
            	case 2: {
            		fflush(stdin);
            		do{
                        printf ("Grupo do Produto ..................................: ");
                        scanf ("%d",&estoque[posicao].grupo);
						fflush(stdin);
                    }while(aux.grupo<0);
					break;
				}
				case 3: {
					fflush(stdin);
            		do{
                        printf ("Descrição ..................................: ");
                        scanf ("%40[^\n]s",&estoque[posicao].descricao); 
						fflush(stdin);
                    }while(aux.descricao<0);
					break;
				}
				case 4: {
					fflush(stdin);
            		do{
                        printf ("Unidade ..................................: ");
                        scanf ("%2[^\n]s",&estoque[posicao].unidade); 
						fflush(stdin);
                    }while(aux.unidade<0);
					break;
				}
				case 5: {
					fflush(stdin);
            		do{
                        printf ("Fornecedor ..................................: ");
                        scanf ("%40[^\n]s",&estoque[posicao].fornecedor); 
						fflush(stdin);
                    }while(aux.fornecedor<0);
					break;
				}
				case 6: {
					fflush(stdin);
            		do{
                        printf ("Quantidade em Estoque ..................................: ");
                        scanf ("%f",&estoque[posicao].quantidade); 
						fflush(stdin);
                    }while(aux.quantidade<0);
					break;
				}
				case 7: {
					fflush(stdin);
            		do{
                        printf ("Preço de Compra ..................................: ");
                        scanf ("%f",&estoque[posicao].pr_compra); 
						fflush(stdin);
						aux.lucro = ((aux.pr_venda - aux.pr_compra) / aux.pr_venda) * 100;
                    }while(aux.pr_compra<0);
					break;
				}
				case 8: {
					fflush(stdin);
            		do{
                        printf ("Preço de Venda ..................................: ");
                        scanf ("%f",&estoque[posicao].pr_venda); 
						fflush(stdin);
						aux.lucro = ((aux.pr_venda - aux.pr_compra) / aux.pr_venda) * 100;
                    }while(aux.pr_venda<0);
					break;
				}
				case 9: {
					fflush(stdin);
            		do{
                        printf ("Margem de Lucro Mínimo ..................................: ");
                        scanf ("%d",&estoque[posicao].lucroMin); 
						fflush(stdin);
                    }while(aux.lucroMin<0);
					break;
				}
				case 10: {
					fflush(stdin);
            		do{
                        printf ("Quantidade Mínima ..................................: ");
                        scanf ("%f",&estoque[posicao].estoque_min); 
						fflush(stdin);
                    }while(aux.estoque_min<0);
					break;
				}
			}
			printf("\nREGISTRO ALTERADO COM SUCESSO!\n\n");
            }else if (confirma == 'n' || confirma == 'N')
                printf("\n O REGISTRO NÃO FOI ALTERADO!\n\n");
            else {
            	printf("\n DIGITAR UM VALOR VALIDO!\n\n");
            	system("pause");
            	system("cls");
            	return;
			}
     }
 else
    printf("O REGISTRO NÃO FOI LOCALIZADO!\n\n");
    printf("APERTE ENTER PARA VOLTAR AO MENU");
    getchar();
    system("cls");
    return;
	break;
}
    }
}
void movimentacao (Tproduto estoque[], int *tamanho){
     if(*tamanho==0){
        printf("\nREGISTRO VAZIO!\n\n");
        system("pause");
        system("cls");
        return;
     }
     int posicao, i, codigo, selecao;
     char confirma, correto; // uma pra confirmar o codigo e outra para a alteração
     Tproduto aux;
     printf("Codigo......: ");
	 scanf("%d", &codigo);fflush(stdin);
     posicao=pesquisabinaria(estoque, codigo, *tamanho);
     if (posicao>=0) {//encontrou registro
    printf("\n===========================================================================\n");
    printf("Codigo: %ld\n\nNome do Produto: %s\n\nDescrição: %s\n\nUnidade: %s\n\nFornecedor: %s\n\n",
	estoque[posicao].codigo, estoque[posicao].nome, estoque[posicao].descricao, estoque[posicao].unidade, estoque[posicao].fornecedor);
	printf("---------------------------------------------------------------------------\n\n");
	        do {
     		printf("Confirma a compra desse produto? (S/N): ");fflush(stdin);
            confirma=getchar(); fflush(stdin);
            if (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N')
            printf("\nOPÇÃO INVALIDA\n\n");
            }
            while (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N');
            if (confirma == 's' || confirma == 'S'){
					fflush(stdin);
            		do{
                        printf ("Fornecedor ...........................................: ");
                        scanf ("%40[^\n]s",&estoque[posicao].fornecedor); 
						fflush(stdin);
                    }while(aux.fornecedor<0);
					fflush(stdin);
            		do{
                        printf ("Quantidade Comprada ..................................: ");
                        scanf ("%f",&estoque[posicao].quantidadeComprada); 
						fflush(stdin);
                    }while(aux.quantidade<0);
					fflush(stdin);
            		do{
                        printf ("Preço de Compra ......................................: ");
                        scanf ("%f",&estoque[posicao].pr_compra); 
						fflush(stdin);
                    }while(aux.pr_compra<0);
                   estoque[posicao].quantidade = estoque[posicao].quantidade - estoque[posicao].quantidadeComprada;
                    printf("\nREGISTRO MOVIMENTADO COM SUCESSO!\n\n");
			}
            else if (confirma == 'n' || confirma == 'N')
                printf("\n MOVIMENTAÇÃO CANCELADA!\n\n");
            /*else {
            	printf("\n DIGITAR UM VALOR VALIDO!\n\n"); //isso ficou obsoleto, mas deixo ai para um caso especial
            	system("pause");
            	system("cls");
            	return; 
		}*/
	}else
    printf("O REGISTRO NÃO FOI LOCALIZADO!\n\n");
    printf("APERTE ENTER PARA VOLTAR AO MENU");
    getchar();
    system("cls");
    return;
}
