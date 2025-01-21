**(0)?**: Um grupo de captura opcional que corresponde a um único "0".

**(.*?)**: Match everything, ele aceita qualquer inciio, qualquer coisa

**[02468]**: Números pares

**([^0-9].*)**: Este grupo de captura corresponde a qualquer caractere que não seja um dígito ([^0-9]) seguido por zero ou mais caracteres (.*)

**[0-9]*[02468][^0-9]**: Este padrão corresponde a zero ou mais dígitos de 0 a 9, seguidos por um dígito par de 1 a 9 e um caractere que não é um dígito.

**[0-9]*[02468]**: Este padrão corresponde a zero ou mais dígitos de 0 a 9, seguidos por um dígito par de 1 a 9.

1º: Pode começar com um 0, seguido de qualquer string que tenha um número par e finalize com qualquer caracter que não seja um número -> . , ! ?

2º: número de 0 a 9, podendo repetir nenhuma ou várias vezes, que finalize com um número par para ser par e e finalize com qualquer caracter que não seja um número -> . , ! ?

3º: qualquer número par. 