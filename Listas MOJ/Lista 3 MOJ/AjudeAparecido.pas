program AjudeAparecido;
var
  C1, C2, C3, T, soma: longint;
begin
  // Ler os valores das contas
  readln(C1, C2, C3);
  
  // Ler o valor da soma calculada
  readln(T);
  
  // Calcular a soma correta
  soma := C1 + C2 + C3;
  
  // Verificar se a soma está correta
  if soma = T then
    writeln('Acertou')
  else
    writeln('Errou');
end.
