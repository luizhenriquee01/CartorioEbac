#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()//função responsavel por cadastrar os usuários no sistema

{
	//inicio croação de variáveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletandi informação do usuário
	scanf("%s", cpf);//vai salvar dentro de uma string//refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string
	
	FILE *file;  //Voce vai procurar nas nossas bibliotecas, alguma estrutura que se chama file, pq vamos criar um arquivo //FILE já existe no sistema//file é oq criamos/cria arquivo
	file = fopen(arquivo, "w");//arquivo novo//cria o arquivo //"w" vai escrever
	file = fopen(arquivo, "a");
	fprintf(file, " CPF: ");
	fprintf (file,cpf); //o mesmo printf, porem ele está salvando no arquivo//salva o valor da variavel
	fclose(file); //temos que fechar o arquivo//fecha o arquivo
	
	file = fopen(arquivo, "a");//abrindo novamente o arquivo que já esta salvo
	fprintf(file,",\n");//salvar uma informação dentro do arquivo, (no caso do exemplo uma ",", para separar nosso cpf, nome, sobrenome e cargo)
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
	setlocale(LC_ALL, "Portuguese");// tem que colocar novamente, pois está em função diferente//colocar a assentação
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	
	FILE *file;//consulta o arquivo
	file = fopen(cpf, "r");//esse é o cpf(arquivo), então lê para mim

	
	
	if (file == NULL)//SE O ARQUIVO FOR NULL, ELE VAI DIZER..
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");//não achou
	}
	
	while (fgets(conteudo, 200, file) != NULL)//enquanto ele estiver escrevendo na variavel ou string conteudo até 200 valores
	{
		printf("\nEssas são as informações do usuário: ");//depois que ele avaliar todo esse conteudo, ele tras a informação
		printf("%s", conteudo);
		printf("\n\n");
		
	}

	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];//char para gerenciamento de string funciona melhor
	
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //ele vai varrer tudo oq o usuário digitar, e vai salvar tudo oq a gente pedir//provem da biblioteca//salvar dentro da variavel

	
	remove(cpf);   //muito cuidado, conforme dito anteriormente//pode dar um problemão//***criar depois uma função replay***	
   
   
	FILE *file;
	file = fopen(cpf, "r");//função de abrir//ler esse arquivo CPF


	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()//função principal sempre vai ser chamada primeiro
    {
    	int opcao=0;//Definindo variáveis //= igual a atribuição
          	
       	int laco=1;
          	
       	for(laco=1;laco=1;)
       	{
          	system("cls");//responsável por limpar a tela

           	setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
          	
           	printf("### Cartório da EBAC ###\n\n");//Inicio de Menu
          	
	    	printf("Escolha a opção desejada do menu:\n\n");
          	
		    printf("\t1 - Registrar nomes\n");
           	printf("\t2 - Consultar nomes\n");
       	    printf("\t3 - Deletar nomes\n");
           	printf("\t4 - Sair do sistema\n");
          	
          	printf("Opção: ");//fim do menu
           	scanf("%d", &opcao);//armazenando a escolha do usuário//armazenar a variavel (opção)o valor que o cliente vai digitar
           	
       	    system("cls");//limpar a tela
          	    
            switch(opcao)//inicio da seleção do menu
            {
  				case 1: 
		    	registro();//chamada das funções
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
            		    
            	default:printf("Essa opção não está disponível\n");
            	system("pause");
            	break;
			        	
			}
		}//fim da seleção 
    } 

