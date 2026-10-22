# ITP - Segunda avaliação: Boletim de uma pequena turma

## Identificação

- **Nome:** Caio Felipe Sales da Silva
- **Projeto escolhido:** Opção 1 - Boletim de uma pequena turma

## Descrição

O programa registra as notas de uma pequena turma e mostra um resumo dos resultados.

Funcionalidades implementadas:

- Solicita a quantidade de estudantes (entre 1 e 10) e o nome de cada um, rejeitando nomes vazios.
- Lê três notas por estudante, aceitando apenas valores entre 0 e 10.
- Armazena as notas em uma matriz `notas[10][3]` (linhas = estudantes, colunas = avaliações).
- Calcula a média aritmética de cada estudante e a guarda em um vetor alocado dinamicamente (`calloc`), com uma posição por estudante.
- Exibe uma tabela com nome, notas, média e situação ("atingiu a meta" quando a média é maior ou igual a 6, "abaixo da meta" nos demais casos).
- Exibe a média geral da turma e o nome de quem obteve a maior média, listando todos em caso de empate.

Organização do código (`main.c`): `limparBuffer`, `lerEstudantes`, `calcularMedias`, `exibirTabela` e `exibirResumo`, além da `main`. A função `calcularMedias` recebe um ponteiro e escreve as médias na memória alocada pela `main`.

## Compilação e execução 

Em Linux ou macOS, com o GCC instalado:

```
gcc -std=c11 -Wall -Wextra main.c -o programa
./programa
```

## Testes

### Teste 1 - funcionamento normal, com nota inválida

Entradas, uma por linha:

```
1
Ana
11
5
6
7
```

Resultado esperado: a nota 11 é rejeitada ("Nota invalida. Digite de novo:") e solicitada novamente; depois a média de Ana é 6.00, a situação é "atingiu a meta", a média geral é 6.00 e a maior média (6.00) é de Ana.

### Teste 2 - limites e empate

Entradas, uma por linha (a quantidade 0 e a nota "abc" são inválidas; a linha vazia é um nome inválido):

```
0
2
(linha vazia)
Davi
abc
4
5
3
Ela
4
5
3
```

Resultado esperado: a quantidade 0 é rejeitada e a 2 é aceita; o nome vazio é rejeitado; a nota "abc" é rejeitada. Davi e Ela ficam com média 4.00 ("abaixo da meta"), a média geral é 4.00 e a maior média (4.00) é listada para os dois, Davi e Ela.

## Vídeo

[COLE AQUI O LINK DO VÍDEO NO YOUTUBE]

## Referências

- Aula 6 - Matrizes
- Aula 7 - Tipos de dados
- Aula 8 - Strings em C
- Aula 9 - Estrutura de Memória
- Aula 10 - Memória Estática e Heap
- Aula 11 - Ponteiros e Alocação Dinâmica
