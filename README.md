# CRIPTOGRAFIA RSA
Aluno: Icaro Henrique Vieira Pinheiro

Matricula: 2018046556

DOCUMENTAÇÃO

 Instruções
Para compilar: gcc trabalhopratico.c –Wall –lm –o exec

Para executar: ./exec

Não devem ser utilizados números primos pequenos como 2,3,7...
por comprometerem a segurança e criptografia

 Sumario
Neste projeto a proposta é desenvolver uma implementação em C
do método de criptografia RSA, a ideia principal é fornecer ao usuário uma
ferramenta para uma comunicação mais segura.
Os Principais desafios foram realizar cálculos com números
extremamente grandes, como por exemplo, 651 elevado 11 visto as limitações
das bibliotecas como math.h. A partir disso foi estabelecido estratégias
desenvolvendo algoritmos que realizassem o cálculos como 611 elevado a 11
mod 899 de forma otimizada.

 Descrição dos Procedimentos
- Algoritmo de Euclides
O algoritmo de Euclides é utilizado para encontrar a chave
de cifragem. Um método simplificado
para encontrar o MDC entre dois números.
- Função para validar as entradas de números primos. 
O método RSA é baseado na premissa que não é possível
fatorar números primos muito grande, por isso é de extrema
importância que os números inseridos pelo usuário sejam primos.
- Função que realiza as potencias e módulos (eleva)
Devido aos problemas de memória com os cálculos
matemáticos foi necessário desenvolver uma função que
fatorasse o calculo, dessa forma a função realiza a potencia com
expoentes menores e tira o modulo, após isso atualiza qual é a
próxima potencia a ser realizada em sequencia, esse método é
baseado na expansão binária do expoente
