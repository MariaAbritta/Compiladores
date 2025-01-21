# Tipos de Dados Inteiros
1. _integer_: Um tipo de dado para números inteiros que normalmente tem um alcance de -32768 a 32767.
2. _shortint_: Um tipo de dado inteiro com um alcance de -128 a 127.
3. _longint_: Um tipo de dado inteiro de longo alcance, tipicamente -2147483648 a 2147483647.
4. _byte_: Um tipo de dado inteiro não assinado com um alcance de 0 a 255.
5. _word_: Um tipo de dado inteiro não assinado com um alcance de 0 a 65535.
6. _longword_: Um tipo de dado inteiro não assinado de longo alcance, tipicamente de 0 a 4294967295.
    * "Um tipo de dado inteiro não assinado"
        * Tipo de dado que representa apenas números inteiros não negativos

# Tipos de Dados Reais
1. _real_: Um tipo de dado para números de ponto flutuante com precisão simples.
2. _single_: Um tipo de dado para números de ponto flutuante com precisão simples, similar a real.
3. _double_: Um tipo de dado para números de ponto flutuante com precisão dupla.
4. _extended_: Um tipo de dado para números de ponto flutuante com precisão estendida.
5. _comp_: Um tipo de dado para números inteiros de precisão estendida (não utilizado em muitas versões modernas de Pascal).
6. _currency_: Um tipo de dado especial para cálculos monetários, com quatro casas decimais fixas.
    * "Números de ponto flutuante com precisão simples"
        * Tipo de dado utilizado para representar números que têm frações decimais, permitindo assim uma gama muito maior de valores do que os números inteiros
    * "Números de ponto flutuante com precisão dupla"
        * Utiliza mais bits para armazenar o valor, o que permite representar números com maior precisão e um intervalo maior
    * "Números de ponto flutuante com precisão estendida"
        * Utiliza ainda mais bits do que os números de ponto flutuante com precisão dupla, proporcionando um intervalo ainda maior de valores e maior precisão

# Tipos de Dados Caracteres e Strings
1. _char_: Um tipo de dado para armazenar um único caractere.
2. _string_: Um tipo de dado para armazenar uma sequência de caracteres. Em Pascal clássico, isso pode ser uma string de comprimento fixo ou variável.
3. _ansistring_: Uma string de comprimento variável com base em ANSI (utilizado em versões mais modernas como Delphi).

# Tipos de Dados Booleanos
1. _boolean_: Um tipo de dado que pode ter um dos dois valores: true ou false.

# Tipos de Dados Estruturados
1. _array_: Um tipo de dado que permite armazenar uma coleção de elementos do mesmo tipo.
2. _record_: Um tipo de dado que permite armazenar uma coleção de elementos de diferentes tipos.
3. _set_: Um tipo de dado que representa um conjunto de valores do mesmo tipo.
4. _file_: Um tipo de dado que representa arquivos.