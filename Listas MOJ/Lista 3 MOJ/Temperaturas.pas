program ConversaoTemperatura;
var
  escalaOrigem, escalaDestino: char;
  temperatura, temperaturaConvertida: real;

function CelsiusParaFahrenheit(c: real): real;
begin
  CelsiusParaFahrenheit := c * 9 / 5 + 32;
end;

function CelsiusParaKelvin(c: real): real;
begin
  CelsiusParaKelvin := c + 273.15;
end;

function FahrenheitParaCelsius(f: real): real;
begin
  FahrenheitParaCelsius := (f - 32) * 5 / 9;
end;

function FahrenheitParaKelvin(f: real): real;
begin
  FahrenheitParaKelvin := (f - 32) * 5 / 9 + 273.15;
end;

function KelvinParaCelsius(k: real): real;
begin
  KelvinParaCelsius := k - 273.15;
end;

function KelvinParaFahrenheit(k: real): real;
begin
  KelvinParaFahrenheit := (k - 273.15) * 9 / 5 + 32;
end;

begin
  // Ler as escalas de origem e destino e a temperatura
  readln(escalaOrigem);
  readln(escalaDestino);
  readln(temperatura);

  // Converter a temperatura conforme as escalas fornecidas
  if escalaOrigem = 'C' then
  begin
    if escalaDestino = 'F' then
      temperaturaConvertida := CelsiusParaFahrenheit(temperatura)
    else if escalaDestino = 'K' then
      temperaturaConvertida := CelsiusParaKelvin(temperatura);
  end
  else if escalaOrigem = 'F' then
  begin
    if escalaDestino = 'C' then
      temperaturaConvertida := FahrenheitParaCelsius(temperatura)
    else if escalaDestino = 'K' then
      temperaturaConvertida := FahrenheitParaKelvin(temperatura);
  end
  else if escalaOrigem = 'K' then
  begin
    if escalaDestino = 'C' then
      temperaturaConvertida := KelvinParaCelsius(temperatura)
    else if escalaDestino = 'F' then
      temperaturaConvertida := KelvinParaFahrenheit(temperatura);
  end;

  // Imprimir a temperatura convertida com duas casas decimais
  writeln(temperaturaConvertida:0:2);
end.
