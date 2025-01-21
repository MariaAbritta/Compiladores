program Soma_N; // Nome do programa
var // Esta linha inicia a seção de declaração de variáveis. 
// Em Pascal, todas as variáveis devem ser declaradas antes de serem usadas.
  N, X, Soma, i: longint;
  // longint, que é um tipo de dado para números inteiros de longo alcance.
begin
  // Ler o valor de N
  readln(N);
  
  // Inicializar a variável Soma
  Soma := 0; // O operador := é usado em Pascal para atribuir um valor a uma variável.
  
  // Ler e somar os N números
  for i := 1 to N do
  begin
    readln(X);
    Soma := Soma + X;
  end;
  
  // Imprimir a soma
  writeln(Soma);
end.
