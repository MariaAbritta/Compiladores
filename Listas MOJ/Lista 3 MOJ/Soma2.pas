program SomaNumeros; // Declaração do nome do programa
var // Esta linha inicia a seção de declaração de variáveis. 
// Em Pascal, todas as variáveis devem ser declaradas antes de serem usadas.
  num1, num2, soma: longint;
  // longint - que é um tipo de dado para números inteiros de longo alcance.
begin
  // Lendo 2 números inteiros
  // Esta linha lê um número inteiro da entrada padrão (normalmente o teclado) e o armazena nas varáveis.
  readln(num1);
  readln(num2);

  // Cálculo da soma
  soma := num1 + num2;
  // O operador := é usado em Pascal para atribuir um valor a uma variável.

  // Resultado
  writeln(soma);
  // A função writeln é usada para imprimir texto ou valores na tela.
end.
