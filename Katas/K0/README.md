Miguel Angel Cabral Ramírez A01226132
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

Breakdown:

Primero, se establecen las reglas para poder acotar el problema y tener una solución más eficiente en ciertos casos.

Caso 1 - acotar el problema a que siempre habrá una solución.
Caso 2 - establecer si todos los números son positivos o todos negativos.
Caso 3 - establecer un tamaño finito en el tamaño del arreglo.

Hay dos maneras de poder llegar a la solución. La primera es la siguiente:

1. Ordenar el arreglo en orden descendente.
2. Ya que existe una solución, se puede evaluar el ejercicio de una forma más sencilla. Se reccorre el arreglo y se va comparando el valor del arreglo, en caso de que el valor sea mayor a la solución, se recorre el arreglo.
3. Una vez que el valor del arreglo sea menor que la solución, se le resta el valor de la casilla del arreglo a la solución y ahora se busca ese valor en arreglo.
4. Se podría emprezar a recorrer el arreglo desde la posición en la que se quedó y buscar su complemento, o empezar a recorrerlo desde el final hacia el inicio.
5. Ya que siempre hay solución, en algún punto se encontrarán los dos valores

La segunda manera de llegar a la solución es la siguiente:

1. Crear una hash table que guarde las sumas de todas las combinaciones posibles.
2. Una vez que se hace la hash table, simplemente se ingresa la solución final y regresa el índice en el que se encuentran los valores.


