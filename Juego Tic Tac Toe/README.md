Repositorio destinado a la creacion de codigo C para la creacion del juego
Tic Tac Toe (Juego de Gato) por parte de estudiantes del curso Programacion
Bajo Plataformas Abiertas de la Universidad de Costa Rica.

Bibliotecas necesarias: GTK +3.0

*La biblioteca GTK +3.0 viene instalada por defecto en los sistemas Ubuntu.



Comando para compilar el codigo:
$ gcc `pkg-config --cflags gtk+-3.0` ./ProyectoC_Grupo_8.c -o exe `pkg-config
--libs gtk+-3.0`

Comando para ejecutar el programa:
./exe


Es posible utilizar el archivo Makefile ubicado en el repositorio para compilar
y ejecutar el codigo con mayor facilidad. Para realizar la compilacion del
codigo a traves del archivo Makefile utilizar el siguiente comando:

$ make

Para ejecutar el programa a traves del archivo Makefile utilizar el comando:

$ make run

*Nota: El comando ($ make run) se puede ejecutar unicamente despues de utilizar
el comando ($ make), ya que en caso contrario no habra archivo ejecutable para
ejecutar el programa.


Descripción y uso de la aplicacion:
La aplicación es un juego de tic tac toe, o mejor conocido como juego de gato.
La forma en la que se juega es por turnos, cada jugador jugará con una ficha "X"
u "O", el que logre poner tres de sus fichas en una linea seguida, será el
ganador del juego. El ganador del juego se mostrará en la parte superior, al
lado del boton de "reiniciar". Una vez que se muestra al jugador, no se podrán
realizar mas movimientos, hasta que se presione el boton "reinciar", para
comenzar una nueva partida.

Autores de la aplicacion:
-Sergio Camacho B91476
-Johan Solis Soto C07686
-Mario Navarro Bejarano B75398
