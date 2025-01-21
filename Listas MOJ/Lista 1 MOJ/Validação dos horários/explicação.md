**:**: Corresponde ao caractere literal de dois pontos que separa as horas dos minutos.

**([01][0-9]|2[0-3])**: Esta parte do regex verifica se a hora está correta.
    **[01][0-9]**: Corresponde a qualquer hora de "00" a "19".
    **2[0-3]**: Corresponde a qualquer hora de "20" a "23".

A segunda parte é dos minutos, o primeiro dígito indo de 0 a 5 e o segundo indo  de 0 a 9.