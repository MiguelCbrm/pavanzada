Miguel Angel Cabral Ramírez A01226132

Given two lists A and B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given

A = [12, 28, 46, 32, 50]  B = [50, 12, 32, 46, 28]  
We should return
[1, 4, 3, 2, 0]  
as  P[0] = 1 because the  0th element of  A appears at  B[1], and  P[1] = 4 because the  1st element of  A appears at  B[4], and so on.
Note:

A, B have equal lengths in range [1, 100].
A[i], B[i] are integers in range [0, 10^5].


Breakdowon:

Sabemos que un anagrama significa que el segundo elemento está compuesto por el primero. Esto es, que el segundo elemento contiene valores del primero y probablemente se encuentre cada valor en distinta posición en comparación con el primero. También sabemo que en esta ocasión, el arreglo de A y el arreglo de B tienen la misma longitud, por lo que se pudiera recorrer cada arreglo sin la preocupación de salirse de un index out of bounds.

Hay más de una manera de encontrar la solución, en esta kata explicaré dos maneras de hacerlo. La primera es la siguiente:

1. Crear una hash table que guarde los valores de cada casilla del arreglo B como key y la posición como valor.
2. Ya que se guarden los valores junto con sus posiciones, crear un método que recorra el arreglo A que vaya ingresando cada uno de los valores para que la hash table regrese sus posiciones.

La segunda forma de llegar a la solución es:

1. Recorrer el arreglo A e irlo comparando con el arreglo B hasta que encuentre una igualdad. En el momento en que se encuentre la igualdad, se regresa la posición del arreglo B y se continúa con el siguiente valor del arreglo A.

Para ambos casos, ya sea que los arreglos sean cortos o grandes, yo recomendaría la primera opción, ya que se recorre el el arreglo B solo una vez. De cualquier manera, es necesario hacer una evaluación para comprobar qué solución es la más eficiente.