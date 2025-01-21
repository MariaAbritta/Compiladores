**\-**: Literam do "-" operador matemático

**\-[0]+[1-9][0-9]*$**: Pode um negativo começando com 0 mas necessariamente ter um numero de 1 a 9 após MAS podendo ou não ter uma cadeia

**-[1-9][0-9]*$**: Negativo começando sem ser com 0 podendo ou não ter uma cadeia

--

**\-[0]+[1-9][0-9]*$**: Este padrão corresponde a números negativos que começam com um ou mais zeros seguidos por um dígito diferente de zero.

**|\-[1-9][0-9]*$**: Este padrão corresponde a números negativos que começam com um dígito diferente de zero.

**[0-9]+$**: Este padrão corresponde a números positivos que contêm apenas dígitos de 0 a 9.

**[0-9]+$**: Podendo ter uma cadeia positiva -> + signficia 1 ou mais -> $ significa acabou aqui, acabou no numero