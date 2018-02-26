65. Valid Number

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Breakdown:

Para poder comprobar que la entrada es un número válido, primero se tienen que analizar varios casos:

1. La entrada tiene puros enteros?
2. La entrada cuenta con puros número enteros y solo un '.'?
3. La entrada cuenta con algun caracter alfabético que no sea 'e'?
4. La entrada cuenta con solo una letra 'e' en toda la entrada?
5. El uso de comas es el correcto?

Para cada caso, el análisis debe de ser distinto. Para el primer caso, se podría analizar cada uno de los caracteres y comprobar que sean puros dígitos.

Para el segundo caso, se podría tener un contador de '.' para saber la cantidad que hay en la entrda. Existe la posibilidad de tener dos '.' en caso que a partir de la 'e' se utilicen decimales, se intentará abarcar ambos casos, aquel que acepta solo un '.' antes de la 'e' y aquel que acepta solo un '.' después de la 'e'. NOTA: para este programa, haré que antes y después de un '.' tenga que haber forzosamente un dígito.

Para el tercer caso, sería comparar cada caracter y comprobar que si es que hay una letra, que no sea igual a e. En caso de haber una letra, terminar la ejecución.

Para el cuarto caso, se utilizaría el mismo enfoque que tiene el caso dos. Se utilizaría un contador que fuerca contando el número de 'e' que vayan apareciendo. En este caso, solo puede haber una 'e'.

Finalmente, para el último caso, sería analizar que a partir de las comas, tienen que sobrar un número de caracteres que sean múltiplos de tres más las comas restantes.