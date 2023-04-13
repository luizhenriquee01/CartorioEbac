#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()//fun��o responsavel por cadastrar os usu�rios no sistema

{
	//inicio croa��o de vari�veis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletandi informa��o do usu�rio
	scanf("%s", cpf);//vai salvar dentro de uma string//refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string
	
	FILE *file;  //Voce vai procurar nas nossas bibliotecas, alguma estrutura que se chama file, pq vamos criar um arquivo //FILE j� existe no sistema//file � oq criamos/cria arquivo
	file = fopen(arquivo, "w");//arquivo novo//cria o arquivo //"w" vai escrever
	file = fopen(arquivo, "a");
	fprintf(file, " CPF: ");
	fprintf (file,cpf); //o mesmo printf, porem ele est� salvando no arquivo//salva o valor da variavel
	fclose(file); //temos que fechar o arquivo//fecha o arquivo
	
	file = fopen(arquivo, "a");//abrindo novamente o arquivo que j� esta salvo
	fprintf(file,",\n");//salvar uma informa��o dentro do arquivo, (no caso do exemplo uma ",", para separar nosso cpf, nome, sobrenome e cargo)
	fclose(file);//fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, " Nome: ");
	fclose(file);
	
	file = fopen(arquivo, "a");//atualizando o arquivo
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, " Sobrenome: ");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\n");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " Cargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	system ("pause");
	

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");// tem que colocar novamente, pois est� em fun��o diferente//colocar a assenta��o
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	
	FILE *file;//consulta o arquivo
	file = fopen(cpf, "r");//esse � o cpf(arquivo), ent�o l� para mim

	
	
	if (file == NULL)//SE O ARQUIVO FOR NULL, ELE VAI DIZER..
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");//n�o achou
	}
	
	while (fgets(conteudo, 200, file) != NULL)//enquanto ele estiver escrevendo na variavel ou string conteudo at� 200 valores
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//depois que ele avaliar todo esse conteudo, ele tras a informa��o
		printf("%s", conteudo);
		printf("\n\n");
		
	}

	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];//char para gerenciamento de string funciona melhor
	
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //ele vai varrer tudo oq o usu�rio digitar, e vai salvar tudo oq a gente pedir//provem da biblioteca//salvar dentro da variavel

	
	remove(cpf);   //muito cuidado, conforme dito anteriormente//pode dar um problem�o//***criar depois uma fun��o replay***	
   
   
	FILE *file;
	file = fopen(cpf, "r");//fun��o de abrir//ler esse arquivo CPF


	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()//fun��o principal sempre vai ser chamada primeiro
    {
    	int opcao=0;//Definindo vari�veis //= igual a atribui��o
          	
       	int laco=1;
          	
       	for(laco=1;laco=1;)
       	{
          	system("cls");//respons�vel por limpar a tela

           	setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
          	
           	printf("### Cart�rio da EBAC ###\n\n");//Inicio de Menu
          	
	    	printf("Escolha a op��o desejada do menu:\n\n");
          	
		    printf("\t1 - Registrar nomes\n");
           	printf("\t2 - Consultar nomes\n");
       	    printf("\t3 - Deletar nomes\n");
           	printf("\t4 - Sair do sistema\n");
          	
          	printf("Op��o: ");//fim do menu
           	scanf("%d", &opcao);//armazenando a escolha do usu�rio//armazenar a variavel (op��o)o valor que o cliente vai digitar
           	
       	    system("cls");//limpar a tela
          	    
            switch(opcao)//inicio da sele��o do menu
            {
  				case 1: 
		    	registro();//chamada das fun��es
		 	   	break;        	       	

				case 2: 
			    consulta();
		 	    break;
		 	        
				case 3: 
				deletar();
            	break;
            	
            	case 4:
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break;
            		    
            	default:printf("Essa op��o n�o est� dispon�vel\n");
            	system("pause");
            	break;
			        	
			}
		}//fim da sele��o 
    } 

