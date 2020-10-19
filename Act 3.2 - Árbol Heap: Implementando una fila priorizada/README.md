#Push

Su complejidad es O(log(n)), ya que cuenta con un ciclo while añade un elemento al árbol y realiza un chequeo para hacer la comparación de tamaños, siendo así logaritmica.

#Pop

Su complejidad es O(0), ya que solo remueve los elementos del árbol y no utliza ningun ciclo. 

#Top

Su complejidad es O(n), ya que cuenta con ciclos if para recorrer los pasos necesarios, para hallar la raíz del árbol y los nodos anteriores, siendo así lineal.

#Empty

Su complejidad es O(n), ya que cuenta con ciclos if 

El algoritmo busca encontrar el nivel en que se encuentra un valor dado como parámetro de la función, para hacer esto hace uso, nuevamente, de ciclos if recorriendo n pasos, los cuales devuelven el nivel, devolviendo -1 en caso de no existir, al ser ciclos que sólo siguen instrucciones lineales podemos decir que la complejidad temporal es O(n), es decir, lineal para el peor de los caso.

#Size

Su complejidad es O(log(n)), Es lineal, ya que cuenta con ciclos if que realizan la busqueda del nodo aledaño.
