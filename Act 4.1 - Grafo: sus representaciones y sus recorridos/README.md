#loadGraphMat

Su complejidad es O(n), es lineal, ya que abre el archivo txt y dependiendo los renglones que tenga va extrayendo información de los nodos, para posteriormente guardarlos.

#loadGraphList

Su complejidad es O(n), es lineal, ya que abre el archivo txt, el cual extrae información de los nodos, para que posteriormente los guarde en un solo paso.

#DFS

Su complejidad es O(V+E), ya que la función recursiva busca constantemente nodos que tengan un parecido al BFS y solo llegua a seguir una ruta a la vez, dado a que es DFS primero pasa por un nodo hasta que encuentre algun otro lugar a donde llegar.

#BFS

Su complejidad es O(V+E), ya que se mueve por cada nodo y vertice en base a cada arco medio que exista, estos seran los arcos que recorrera.
