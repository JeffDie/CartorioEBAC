#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

//Funcão para cadastrar usuários no sistema
int registro()
{
	//Inicio da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação das variáveis
	
	printf("Bem Vindo(a) ao registro de nomes\n\n");
	
	//Coletando informações do usuário
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s é usado para salvar um string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "w"); //criar arquivo e o "w" é para escrever
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
		printf("\nNão foi possivel abrir o arquivo, CPF não localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Bem-vindo(a) ao campo de deletar usuário!\n\n");
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nCPF do usuário não encontrado no sistema!\n\n");
		system("pause");
		fclose(file);
	}
	
}

int main()
{
	
	//Definição de Variável
	int opcao = 0;
	int x = 1;
	
	for(x=1; x=1;)
	{
		
		system("cls");
	
		//Definição de Linguagem
		setlocale(LC_ALL, "Portuguese");
		
		//Inicio do Menu
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do memu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Opção: ");
		//Fim do Menu
		
		//Armazenando Escolha de Usuario
		scanf("%d", &opcao);
		
		//Resposavel por limpar a tela
		system("cls");
		
		//Inicio da Seleção
		switch(opcao)
		{
			case 1:
				registro(); //Chamada de função
			break;
			
			case 2:
				consulta(); //Chamada de função
			break;
				
			case 3:
				deletar(); //Chamada de função
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!");;
				return 0;
			break;
			
			default:
				printf("Essa opção não esta disponivel!\n\n");
				system("pause");
			break;
		}
		//Fim da Seleção
		
		printf("Esse software pertence ao Diego!");
		
	}
}
