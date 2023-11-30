#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

//Func�o para cadastrar usu�rios no sistema
int registro()
{
	//Inicio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o das vari�veis
	
	printf("Bem Vindo(a) ao registro de nomes\n\n");
	
	//Coletando informa��es do usu�rio
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s � usado para salvar um string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "w"); //criar arquivo e o "w" � para escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //"a" usado para atualizar o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Bem Vindo(a) a consulta de nomes\n\n");
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nN�o foi possivel abrir o arquivo, CPF n�o localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Bem-vindo(a) ao campo de deletar usu�rio!\n\n");
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nCPF do usu�rio n�o encontrado no sistema!\n\n");
		system("pause");
		fclose(file);
	}
	
}

int main()
{
	
	//Defini��o de Vari�vel
	int opcao = 0;
	int x = 1;
	
	for(x=1; x=1;)
	{
		
		system("cls");
	
		//Defini��o de Linguagem
		setlocale(LC_ALL, "Portuguese");
		
		//Inicio do Menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do memu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Op��o: ");
		//Fim do Menu
		
		//Armazenando Escolha de Usuario
		scanf("%d", &opcao);
		
		//Resposavel por limpar a tela
		system("cls");
		
		//Inicio da Sele��o
		switch(opcao)
		{
			case 1:
				registro(); //Chamada de fun��o
			break;
			
			case 2:
				consulta(); //Chamada de fun��o
			break;
				
			case 3:
				deletar(); //Chamada de fun��o
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!");;
				return 0;
			break;
			
			default:
				printf("Essa op��o n�o esta disponivel!\n\n");
				system("pause");
			break;
		}
		//Fim da Sele��o
		
		printf("Esse software pertence ao Diego!");
		
	}
}
