// Programa: CRIPTOGRAFIA RSA
// Aluno: Icaro Henrique Vieira Pinheiro
// Matricula: 20180465556 

// Inclusao de Bibliotecas
#include <stdio.h>
#include <string.h>
#include <math.h>

// Funcoes
long eleva(long long valor,long long expoente, long long tira);
int verificaPrimo(int a);

//Programa Principal
int main(){

	// Declaracao de Variaveis
	char mensagemTexto[500];
	int mensagemValor[500];
	int mensagemEncriptada[500];
	int mensagemDescriptada[500];
	char mensagemString[500];
	int primoP,primoQ,inteiroN,inteiroE = 0,inteiroD = 1,totiente;
	int tamanhoMensagem,i;
	int n1,n2,resto;
	int verificador1 = 1,verificador2 = 1;

	printf("****** CRIPTOGRAFIA RSA ******\n\n");

	// Captura da Mensagem
	printf("Digite a mensagem que deseja Criptografar: ");
	fgets(mensagemTexto,500,stdin);

	// Captura dos Numeros Primos
	do{
	printf("Digite os numeros P e Q que devem ser primos: ");
	scanf("%d%d",&primoP,&primoQ);
	verificador1 = verificaPrimo(primoP);
	verificador2 = verificaPrimo(primoQ);
	}while(verificador1 != 0 || verificador2 != 0);

	// Captura o tamanho da mensagem
	tamanhoMensagem = strlen(mensagemTexto) - 1;

	printf("\n----- PROCESSO DE CRIPTOGRAFIA -----\n");

	// Armazena em outro vetor os valores dos caracteres de acordo com a tabela ASCII
	printf("Sem Criptografar: ");
	for (i = 0; i < tamanhoMensagem; ++i){
		mensagemValor[i] = mensagemTexto[i]; 
		printf("%d|",mensagemValor[i]);
	}
	printf("\n");

	// Calcula a chave N e o Totiente
	inteiroN = primoP * primoQ;
	totiente = (primoP - 1)*(primoQ - 1);

	// Algoritmo de Eclides para achar a chave E(Expoente de Cifragem)
	i = 5;
	while(inteiroE == 0){
		n1 = totiente;
		n2 = i;
		// Euclides
		resto = n1 % n2;
		while(resto != 0){
			n1 = n2;
			n2 = resto;
			resto = n1%n2;
		}
		if(n2 == 1){
			inteiroE = i;
		}
		i++;
	}

	// Calcula a chave D (Expoente de decifragem)
	while(inteiroD*inteiroE % totiente != 1){
		inteiroD++;
	}
	
	// Encriptar
	printf("Encriptado:       ");
	for (i = 0; i < tamanhoMensagem; ++i){
		mensagemEncriptada[i] = eleva(mensagemValor[i],inteiroE,inteiroN);
		printf("%d |",mensagemEncriptada[i]);
	}
	printf("\n");

	//Desencriptar
	for (int i = 0; i < tamanhoMensagem; ++i){
		mensagemDescriptada[i] = eleva(mensagemEncriptada[i],inteiroD,inteiroN);
	}
	
	for (int i = 0; i <= tamanhoMensagem; ++i){
		if(i == tamanhoMensagem)
			mensagemString[i] = '\0';
		else
			mensagemString[i] = mensagemDescriptada[i];
	}

	printf("String Desencriptada: %s\n",mensagemString);

	printf("------  CHAVES------ \n");
	printf("Chave D: %d \n",inteiroD );
	printf("Chave E: %d \n",inteiroE );
	printf("Chave N: %d \n",inteiroN );
	return 0;
}

// Funcao para realizar (valor elevado ao expoente mod) de forma reduzida 
long eleva(long long valor,long long expoente, long long modulo){
	long long potencia = 1;
	while(1){
		if(expoente == 0)
			return potencia;
		else if(expoente%2 !=0){
			// Diminui o modulo das multiplicacoes
			potencia = (valor*potencia)%modulo;
			expoente = (expoente-1)/2;
		}
		else{
			expoente = expoente/2;
		}
		// atualiza a sequencia de potencias
		valor = (valor*valor)%modulo;
	}
	
}

// Funcao para verificar se os numeros inseridos sao primos
int verificaPrimo(int a){
	int cont = 0;
	int primo;
	int i;

	for (i = 1; i <= a; ++i){
		if(a % i == 0){
			cont++;
		}
	}
	if(cont > 2){
		primo = 1;
	} else{
		primo = 0;
	}
	
	return primo;
}