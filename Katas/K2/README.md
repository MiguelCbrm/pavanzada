A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

int strongPasswordChecker(char* s) {    }

breakdown:

Para considerar que la contraseña es fuerte, es necesario cumplir con tres reglas. En este caso, la regla dos se conforma por más parámetros dentro de ella misma. En este caso, se me ocurre hacer 3 métodos por separado, cada uno representando una regla. Para iniciar, se crea el método:

char* checkLen(char* psw)

Este método se encargaría de contar el número de caracteres que la contraseña contiene y checaría que estuviera entre el rango mencionado [6 - 20]. En caso de cumplir con la primera regla, no regresa nada. De lo contrario, regresará un mensaje diciendo que no cumple con la primera regla.

El segundo método sería:

char* charChecker(char* psw)

En este método se tienen que comprobar tres cosas: que la contraseña contenga al menos una minúscula, al menos una mayúscula, y al menos un dígito. Una vez recorrida la contraseña, en caso de cumplir con los tres requerimientos, no regresar nada. De lo contrario, regresará un mensaje diciendo que no cumple con la segunda regla y qué es lo que falta.

El tercer método sería:

char* CheckSequence(char* psw)

Éste evaluaría que no exista una secuencia uniforme de caracteres mayor o igual a tres caracteres. Esto es, que en caso de existir un caracter que se repita de manera seguida por más de 2 veces, regresar una alerta mencionando que se infringe la regla tres. De no ser así, no regresar nada.

En el método int strongPasswordChecker(char* s) {    }, la idea es evaluar los tres métodos creados y así cada uno regresaría su sugerencia en caso de no haber cumplido con alguna de ellas. Finalmente, si es que no hubo ninguna infracción, el método principal anunciaría que la contraseña es fuerte.