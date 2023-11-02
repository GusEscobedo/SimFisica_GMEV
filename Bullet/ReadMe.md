# Read me
## Bullet
### Gustavo Martín Escobedo Vázquez

Una simulación en Box 2d en la cual se dispara una bala, imprimiendo en consola el tiempo en que tarda la bala al tocar el suelo

Configuramos el mundo para que tenga una gravedad de 9.8, después definimos la bala como un cuerpo dinámico (para que pueda moverse), le damos un radio de 1, una fricción de 0.3, le asignamos un ángulo inicial de 10 y una velocidad inicial de 5.

Para comprobar en que momento la bala toca el suelo, lo que hago es que mediante una variable obtengo la position en Y de la bala y cuando sea <=0 imprimo el tiempo en el que transcurre.