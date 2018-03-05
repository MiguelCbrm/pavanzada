Kata 5: infographic


You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a hash table ↴ , where the keys are words and the values are the number of times the words occurred.

Think about capitalized words. For example, look at these sentences:

  "After beating the eggs, Dana read the next step:"

"Add milk and eggs, then add flour and sugar."

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of 

2

2. Make reasonable (not necessarily perfect) decisions about cases like "After" and "Dana".

Assume t


Breakdown:

Antes de poder implementar la hashtable, es necesario tener en consideración ciertos puntos. El primero de ellos es la repetición de palabras con mayúsculas y minúsculas, si las palabras tienen signos de puntuación o no dependiendo del idioma o si están mal escritas. Para el último parámetro, se asumirá que el texto a analizar no contará con ninguna falta de ortografía. 

Para evitar que haya repetición de palabras gracias a las mayúsculas, antes de analizar cada palabra se cambiarán todas las mayúsculas de la palabra (suponiendo que tiene por lo menos una en mayúscula) popr letras en minúscula. De esta manera, se hará un análisis de una manera más sencilla. 

De igual manera, en caso de que una palabra tenga signos de puntuación o no, se analizará cada caracter y se terminará comparando en la hashtable sin signos.

Uno de los puntos a evaluar es el analizador de texto. Éste tiene que leer palabra por palabra, pero siene que remover cualquier símbolo que se encuentre en él. Por ejemplo, es importante analizar el texto sin incluir comas o puntos. La idea principal del programa antes de guardarlo es que se limpie por completo la palabra para poder evitar interferencias.

Otro punto importante son las palabras en plural. Se puede implementar un algoritmo que compare la similitud en porcentaje de las palabras con las que ya existen en caso de que la nueva palabra no esté registrada. Ya que se asume que no existen errores ortográficos, se puede implementar un algoritmo que compruebe que el primer 80% o 90% sea exactamente igual y que solo analice la parte final y a partir de su nivel de porcentaje de coincidencia, lo sume a la lista o lo agregue. 

Finalmente, a la hora de imprimir la hashtable, solo sería recorrer todas las palabras agregadas e imprimir el número de verces que se repite cada una.