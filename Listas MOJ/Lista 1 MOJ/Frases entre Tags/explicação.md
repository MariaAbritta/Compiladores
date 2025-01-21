**^**: Indica o início da linha.
**(\w+)**: Captura uma palavra como grupo de captura número 1 (a palavra inicial).
.*: Corresponde a zero ou mais caracteres (qualquer caractere), permitindo que haja outros caracteres entre a palavra inicial e final.
**\b**: Representa uma fronteira de palavra, garantindo que a palavra final seja uma palavra completa.
**\1**: Corresponde à mesma palavra capturada pelo grupo de captura número 1 (a palavra inicial).
**$**: Indica o final da linha.
**(\S+)**: Captura uma sequência de caracteres que não sejam espaços em branco como grupo de captura número 1 (a palavra inicial).

