juego del pong
==================

*   [en que consiste](#en-que-consiste)
*   [integrantes del equipo](#Integrantes-del-equipo)
*   [objetivos del trabajo](#Objetivos-del-trabajo)
*   [dinamica de la aplicacion](#Dinámica-de-la-aplicación)
    *   [iniciar la partida](#Opción-1-Iniciar-partida)
    *   [reanudar/pausar la partida](#Opción-2-Pausar/reanudar-partida)
    *   [mostrar puntacion](#Opción-3–Mostrar-puntuación ) 
    *   [iniciar la partida](#Opción-1-Iniciar-partida)
*   [Identificación sensores y actuadores](#Identificación-sensores-y-actuadores)  
    *   [Medida de la distancia -Sensor ultrasonidos](#Medida-de-la-distancia---Sensor-ultrasonidos-HC-SR04) 
    *   [comobfunciona un sensor ultrasonidos](#CÓMO-FUNCIONA-UN-SENSOR-DE-ULTRASONIDOS)
* * *

## en que consiste ## 
Crear el juego del Pong en el que el movimiento de las raquetas sea controlado por sensores ultrasonidos.

## *Integrantes del equipo* ##

Javier Alonso Geijo (Usuario de GitHub(javieralonso1)),
Alberto Cámara López (Usuario de GitHub(AlbertoCL22)),
Carlos García López-Corona,
Sergio Cantalejo Villasante (Usuario de GitHub(SergioCantalejoVillasante)) y 
Pablo García de Lucas (Usuario de GitHub(PabloGarciadeLucas))

## Objetivos del trabajo

Aprender a programar en C++. Aprender a convertir el lenguaje de C++ a otros lenguajes (en este caso Arduino) y viceversa. Aprender a usar y programar sensores como en este caso los ultrasonidos.
JUEGO DEL PONG 
## Objetivo
Diseñar y desarrollar una aplicación en lenguaje C con el cual podamos jugar al pong mediante unos sensores de ultrasonidos.
Especificaciones del juego
Pong (o Tele-Pong) fue un videojuego de la primera generación de videoconsolas publicado por Atari, creado por Nolan Bushnell y lanzado el 29 de noviembre de 1972. Pong está basado en el deporte de tenis de mesa (o ping pong). La palabra Pong es una marca registrada por Atari Interactive, mientras que la palabra genérica «pong» es usada para describir el género de videojuegos «bate y bola». La popularidad de Pong dio lugar a una demanda de infracción de patentes y ganada por parte de los fabricantes de Magnavox Odyssey, que poseía un juego similar. Es un juego de deportes en dos dimensiones que simula un tenis de mesa. El jugador controla en el juego una paleta moviéndola verticalmente en la parte izquierda de la pantalla, y puede competir tanto contra un oponente controlado por computadora, como con otro jugador humano que controla una segunda paleta en la parte opuesta. Los jugadores pueden usar las paletas para pegarle a la pelota hacia un lado u otro. El objetivo consiste en que uno de los jugadores consiga más puntos que el oponente al finalizar el juego. Estos puntos se obtienen cuando el jugador adversario falla al devolver la pelota.

###### Dinámica de la aplicación


menú | 
------------ | 
1-Un jugador | 
2-Dos jugadores |
3-Cerrar juego  | 


## * _Opción 1 - Un jugador_
 Modo de práctica a modo de frontón.
 Para este modo sólo es necesario el ultrasonido del jugador 1.
 El jugador empieza con 7 vidas, cada vez que le marcan gol pierde una vida, así hasta quedarse con ninguna.
 El objetivo de este modo es dar el máximo número de veces al muro de la derecha para perfeccionar tus habilidades.
 Para este modo de juego se ha creado un fichero de texto "marcadores.txt", gracias a esto podrás conservar tu mejor puntuación de una partida a otra e intentar superarte.

## * _Opción 2 - Dos jugadores_
El clásico juego del pong para dos jugadores locales.
Para este modo cada jugador deberá usar un ultrasonido.
El objetivo de este modo es llegar a 7 puntos, el primero que lo consiga ganará la partida.
Debajo del terreno de juego aparecerá un marcador en el cual se mostrará la puntuación, y si vas ganando aparecerá una flecha amarilla en tu respectivo lugar.

## * _Opción 3 – Cerrar juego_
Con esta opción se cierra el programa.


 ## Identificación sensores y actuadores
Para el trabajo precisaremos de sensores de ultrasonidos para controlar “las raquetas”, estos sensores se encontrarán en un circuito montado en Arduino que deberá estar conectado durante la ejecución del programa para que funcione adecuadamente.
Para ver el montaje del Arduino, dirígete al esquema que se encuentra al principio del proyecto de GitHub.
En caso de error durante la ejecucuión del programa le hemos asignado el puerto "COM5".

## Medida de la distancia - Sensor ultrasonidos HC-SR04
Queremos controlar las raquetas mediante los ultrasonidos, es decir, de forma que según movamos la mano estas se muevan hacia arriba o abajo.
Un sensor de ultra sonidos es un dispositivo para medir distancias. Su funcionamiento se basa en el envío de un pulso de alta frecuencia, no audible por el ser humano. Este pulso rebota en los objetos cercanos y es reflejado hacia el sensor, que dispone de un micrófono adecuado para esa frecuencia.
Midiendo el tiempo entre pulsos, conociendo la velocidad del sonido, podemos estimar la distancia del objeto contra cuya superficie impacto el impulso de ultrasonidos
Los sensores de ultrasonidos son sensores baratos, y sencillos de usar. El rango de medición teórico del sensor HC-SR04 es de 2cm a 400 cm, con una resolución de 0.3cm. En la práctica, sin embargo, el rango de medición real es mucho más limitado, en torno a 20cm a 2 metros.
Los sensores de ultrasonidos son sensores de baja precisión. La orientación de la superficie a medir puede provocar que la onda se refleje, falseando la medición. Además, no resultan adecuados en entornos con gran número de objetos, dado que el sonido rebota en las superficies generando ecos y falsas mediciones. Tampoco son apropiados para el funcionamiento en el exterior y al aire libre.
Pese a esta baja precisión, que impide conocer con precisión la distancia a un objeto, los sensores de ultrasonidos son ampliamente empleados. En robótica es habitual montar uno o varios de estos sensores, por ejemplo, para detección de obstáculos, determinar la posición del robot, crear mapas de entorno, o resolver laberintos. En aplicaciones en que se requiera una precisión superior en la medición de la distancia, suelen acompañarse de medidores de distancia por infrarrojos y sensores ópticos.

## ¿Cómo funciona un sensor de ultrasonidos?
El sensor se basa simplemente en medir el tiempo entre el envío y la recepción de un pulso sonoro. Sabemos que la velocidad del sonido es 343 m/s en condiciones de temperatura 20 ºC, 50% de humedad, presión atmosférica a nivel del mar.
El sonido tarda 29,2 microsegundos en recorrer un centímetro.
El motivo de divir por dos el tiempo (además de la velociad del sonido en las unidades apropiadas, que hemos calculado antes) es porque hemos medido el tiempo que tarda el pulso en ir y volver, por lo que la distancia recorrida por el pulso es el doble de la que queremos medir.
Para activar el sensor necesitamos generar un pulso eléctrico en el pin Trigger (disparador) de al menos 10us. Previamente, pondremos el pin a Low durante 4us para asegurar un disparo limpio.
Posteriormente usamos la función "pulseIn" para obtener el tiempo requerido por el pulso para volver al sensor. Finalmente, convertirmos el tiempo en distancia mediante la ecuación correspondiente.
Observar que intentamos emplear siempre aritmética de enteros, evitando usar números en coma flotante. Esto es debido a que las operaciones en coma flotante ralentizan mucho el procesador, y suponen cargar un gran número de librerías en memoria.
Fuente: https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/


El principal inconveniente que encontramos es que la lectura de distancias implica bloquear la ejecución del programa mientras esta se lleva a cabo impidiendo que la aplicación realice acciones adicionales mientras espera la medida, causa por la que nos hemos visto limitados a la hora de implementar opciones para pausar o reiniciar la partida una vez empezada. 
Cada sensor requiere dos pines del microcontrolador (Echo y Trigger).
La distancia recibida por el sensor de ultrasonidos 1 viene dada en cm y es la variabe "cm", la distancia recibida por el segundo también viene dada en cm y es la variable "cm2".


