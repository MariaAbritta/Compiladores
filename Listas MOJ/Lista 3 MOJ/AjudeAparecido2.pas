program AjudeAparecido;

var
  N, T, i, Soma: integer;
  // Array que pode armazenar até 10 inteiros
  Conta: array[1..10] of integer;

begin
  // Ler o valor de N (número de pessoas)
  readln(N);

  // Inicializar a variável Soma
  Soma := 0;

  // Ler os valores das contas e calcular a soma
  for i := 1 to N do
  begin
    read(Conta[i]);
    Soma := Soma + Conta[i];
  end;

  // Ler o valor total calculado pelo doutorando
  readln(T);

  // Comparar a soma calculada com o valor fornecido
  if Soma = T then
    writeln('Acertou')
  else
    writeln('Errou');
end.
