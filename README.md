# Conway's Game of Life

¡Sean ustedes bienvenidos a este simulador del *Juego de la Vida* de Conway!
Este proyecto fue realizado al cabo de dos meses por sus compañeros:

   - Alexa Dileny González Nieto
   - José Rodrigo Cisneros Murillo


## Compilación y ejecución
Para jugar el juego, compilen usando:
    g++ main.cpp src/GOL.cpp -Iheaders -g -lncurses -o GameOfLife

Una vez compilado el programa, podrán jugar el juego!
Uso del juego:
	./GameOfLife A B C
	./GameOfLife PATTERN_OR_SAVE_FILE
	./GameOfLife PATTERN_OR_SAVE_FILE X_OFFSET Y_OFFSET

La primera forma de ejecutar el juego es una demo para mostrar lo que
se puede llegar a hacer.

En la segunda forma, el usuario podrá abrir un patrón dentro de la carpeta
de ./patterns (o cualquier otro directorio). Se fomenta que cada quien
haga su propio patrón para probar las capacidades del juego. Véase más en
patrones.

La tercera y última forma de ejecutar el programa será de igual manera con 
un patrón pero ahora con un offset en X y en Y. Esto va a hacer que el pa-
trón aparezca más a la derecha o abajo.


## Controles


| Tecla | Uso     |
|:-----:|:-------:|
| ESC   | Pausa   |
| Q     | Salir   |
| S     | Guardar |
-------------------

## Guardar Partidas

Para guardar su partida, se deberá especificar la dirección del archivo en
el que se va a guardar en ./defaultPath.txt

En caso de no especificar el archivo en el que se va a guardar, será guar-
dado de forma automática en ./game_saves/defaultPastState.txt

Si se llega a perder ./defaultPath.txt se puede crear otro archivo bajo el
mismo nombre o dejar sin archivo (aunque de esa manera, todas las partidas
serán guardadas en ./game_saves/defaultPastState.txt).

**LA CARPETA DE ./game_saves ES ESENCIAL PARA EL FUNCIONAMIENTO DEFAULT DEL
PROGRAMA**


## Patrones

Para crear patrones, se puede crear un archivo en blanco e ir dejando ya
sean espacios o puntos como las células "muertas", Y para las células vi-
vas ya sea una 'X', un 'o', o una 'b'.

Ejemplos de patrones:

```
...................................
....................o..............
....................o..............
....................o..............
......o.............o..............
.........o..........o..............
................o..................
...............o..o................
...................................
......o............................
...................................
```

```
         XXXXXXXXXX                
                                   
            X                  X   
             X                    
                        X          
       X                           
         X                        X
       X                         X 
                                  X
      XXXXXXXXXXXXXXXXXX           
```

```
...................................
....bbb.......................b....
....bbb............b...b......b....
..............................b....
..............................b....
.............b..b..................
..........b........................
..b.b.........b....b...............
..b..b..........b..................
.b....b............................

```

```
....oooo...................    ....
....oooo...................    ....
....oooo......X....b...b...    ....
.   ........ .X..... . .... ..XXXX.
..............X...............XXXX.
....         bX.o.............XXXX.
..........b........................
..ooo.........b....b...............
..oo                          .....
.b..                          .....
```



