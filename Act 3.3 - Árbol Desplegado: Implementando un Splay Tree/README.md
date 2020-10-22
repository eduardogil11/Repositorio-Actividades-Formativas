#Add

Su complejidad es O(n), es lineal, ya que cuenta con una función la cual realiza rotaciones entre el abuelo, padre y hijo, para que el hijo pueda llegar a ser la raíz.

#Remove

Su complejidad es O(log(n)), ya que busca el objeto en el arbol para poder borrarlo y posteriormente realiza una función splay en el objeto padre que se borro.

#Find

Su complejidad es O(log(n)), ya que realiza una función splay en el objeto hallado, para posteriormente dejarlo como raíz.

#Inorder

Su complejidad es O(n), es lineal, ya que recorre todos los objetos para imprimirlos en el orden que le corresponde.

#Size

Su complejidad es O(1), ya que es una consulta del atributo de la clase.
