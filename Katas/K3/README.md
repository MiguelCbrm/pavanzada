Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L(Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:

Input: "UD"  Output: true  
Example 2:

Input: "LL"  Output: false

Breakdown:

Ya que solo son posibles cuatro movimientos, a cada uno de ellos les asignaría un valor. L y R son un conjunto, ya que si el robot hace un movimiento para uno de ellos, el robot tiene que hacer el contrario para poder regresar al orignen. De la misma manera, en caso de los movimientos U y D, son otro conjunto. 

L tendría el valor de 1 y R tendía el valor de -1.
U tendría el valor de 2 y D tendría el valor de -2.

La diferencia de valores se debe a que puede llegar a haber una combinación de cada conjunto y si tuvieran el mismo valor, podría sumarse y resatarse e igualarlo a 0, y esa no sería la respuesta correcta.

Al momento de hacer los inputs, se evalúan las letras ingresadas, se hace una suma de las letras y el objetivo final es que el resultado sea igual a 0.

En caso de ser igual a 0, significa que el robot regresó a su origen, de lo contrario significa que el robot se ha movido de su lugar inicial y no ha vuelto a la posición (0,0).