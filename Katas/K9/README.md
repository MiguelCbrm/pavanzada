Inflight Entertainment System

You've built an inflight entertainment system with on-demand movie streaming. Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length. 

Write a function that takes an integer flight_length (in minutes) and a list of integers movie_lengths (in minutes) and returns a boolean indicating whether there are two numbers in movie_lengths whose sum equals flight_length. 

When building your function: 

Assume your users will watch exactly two movies
Don't make your users watch the same movie twice
Optimize for runtime over memory

Breakdown:

Para este problema, es necesario saber la disponibilidad de las películas y la duración de ellas. Del mismo modo se tiene que tomar en cuenta cuánto dura el vuelo. En este caso, se tomará como referencia el tiempo útil en el que se pueden ver películas durante el vuelo.

Para esto, se define una variable que almacenará la duración del vuelo y un arreglo de enteros que va a contener la duración de cada una de las películas. Para mayor eficiencia, las películas se ordenan de menor a mayor en cuanto a su duración.

En caso de que no se acomoden de manera manual, hay que implementar un algoritmo que las ordene en orden ascendente. Una vez temrinado el acomodo, sde podría llegar a implementar la opción sobre la posibilidad de ver más de dos películas en caso de existir tiempo de sobra y que la película extra pueda ser terminada.

Ya que tenemos ordenadas las  películas, se podría saber de manera sencilla cuáles películas se pueden ver.

Aquí se pueden presentar dos casos. Abarcar el mayor tiempo posible con películas, o ver el mayor número de películas. Ya que el problema menciona que solo serían dos películas, se tomará en cuenta solo la posibilidad de abarcar el mayor tiempo posible con dos películas.

Para poder abarcar más tiempo, se asignarán dos películas, la de mayor tiempo con la menor. Se compararán y en caso de no sobrepasar el límite de tiempo, se le asignará el par a una variable y se volverá a analizar entre la mayor y la que sigue de la menor y así sucesivamente hasta que sobrepase el límite de tiempo. Una vez sobrepasado, se regresará la última opción disponible.

En caso de que se recorra todo el arreglo y no haya opción disponible, la variable que contiene la película más grande se recorrerá a una más pequeña hasta poder encontrar una opción.