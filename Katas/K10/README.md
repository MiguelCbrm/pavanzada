A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.

Breakdown:

Para poder iniciar, es necesario recibir el arreglo con los enteros. El primer paso sería convertir todos los número en binario, de esa manera se podrían analizar de uno por uno. Una vez que se cambien los enteros por binarios, se analizarían de uno por uno en un método en específico.

En el método check(), con un for se analizarían de uno por uno. Convertiría el número binario en char para poder recorrerlo de uno en uno. Ya que al convertir el entero en binario, aquel binario que contenga un tamaño menor a 8 dígitos significaría que es te un solo byte. con eso se pordíra sacar una secuencia o se podría saber si hay error o no.

En caso de el tamaño llegue a ser mayor a 8 dígitos, también se podría descartar la opción de que estuviera correcto. Si el binario cumple con el tamaño indicado, que es 8, podríamos pasar al siguiente paso.

ya que se sabe que el tamaño es 8, se recorrería el caracter hasta encontrar un 0. El número de 1s nos diría el número de bytes que son, por lo que se le asignaría a un contador que el valor es X. ya que sabemos que el contador es X, podríamos pasar a analizar los siguientes binarios. Cada que se cumpla la doncidión de que los primeros dos caracteres son 1 y 0, le vamos sumando a un contador temporal. En caso de que se rompa la condición, se compara el temporal con el contador original.

En caso de ser iguales los contadores, se procede a seguir con el conteo si es necesario o se termina el programa regresando verdadero. De lo contrario, se termina el programa y marca falso.