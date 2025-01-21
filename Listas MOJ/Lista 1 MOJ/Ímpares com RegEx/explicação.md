**(0)?**: Um grupo de captura opcional que corresponde a um único "0".

**(.*?)**: Match everything, ele aceita qualquer inciio, qualquer coisa

**(1|3|5|7|9)**: Números ímpares

**([^0-9].*)**: Este grupo de captura corresponde a qualquer caractere que não seja um dígito ([^0-9]) seguido por zero ou mais caracteres (.*)

**[0-9]*[13579][^0-9]**: Este padrão corresponde a zero ou mais dígitos de 0 a 9, seguidos por um dígito ímpar de 1 a 9 e um caractere que não é um dígito.

**[0-9]*[13579]**: Este padrão corresponde a zero ou mais dígitos de 0 a 9, seguidos por um dígito ímpar de 1 a 9.

**([.|?])$**: Finaliza com ponto ou interrogação. Tem que terminar com número ímpar e seguido de ponto ou interrogação.

1º: Pode começar com um 0, seguido de qualquer string que tenha um número impar e finalize com qualquer caracter que não seja um número -> . , ! ?

2º: número de 0 a 9, podendo repetir nenhuma ou várias vezes, que finalize com um número ímpar para ser ímpar e e finalize com qualquer caracter que não seja um número -> . , ! ?

3º: qualquer número ímpar
