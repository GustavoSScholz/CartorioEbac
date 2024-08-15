#include <stdio.h> //biblioteca de comunicação com o usuario 
#include <stdlib.h> //biblioteca de espaço e memoria 
#include <locale.h> //biblioteca de textos da região
#include <string.h> //biblioteca responsavel por cuidar das string
		
int registro() // FUnção responsavel por criar a registro do usuários
{
	//inicio da variavel 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da variavel
	
	printf("Digite o CPF a ser cadastrado: "); // coletar os dados do usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf para fazer uma consulta: ");
    scanf("%s" ,cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("não foi possivel abrir o arquivo, não localizado! \n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\nEssa são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s,cpf");
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuario não se encontra no sistema.\n");
	    system("pause");
	}
	
}


	
int main()
	{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		
			
		printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuÃ¡rio
		
		system("cls");
	
		switch(opcao) //inicio da seleÃ§Ã£o
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opção não esta¡ disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
