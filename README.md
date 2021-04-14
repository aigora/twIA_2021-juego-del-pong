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
    *   [pulsador](#pulsador)
* * *

## en que consiste ## 
Crear un juego de Ping Pong en el que el movimiento de las raquetas sea controlado por sensores ultrasonidos.
En el juego habrá diferentes niveles de dificultad.
También apareceran elementos en mitad del terreno de juego que si son golpeados incrementarán la puntuación del jugador responsable.

## *Integrantes del equipo* ##

Javier Alonso Geijo (Usuario de GitHub(javieralonso1)),
Alberto Cámara López (Usuario de GitHub(AlbertoCL22)),
Carlos García López-Corona,
Sergio Cantalejo Villasante (Usuario de GitHub(SergioCantalejoVillasante)) y 
Pablo García de Lucas (Usuario de GitHub(PabloGarciadeLucas))

## Objetivos del trabajo

Aprender a programar en C++. Aprender a convertir el lenguaje de C++ a otros lenguajes (en este caso Arduino). Programar una inteligencia artifcial para cuando solo juegue un jugador. Aprender a usar y programar sensores como en este caso los ultrasonidos y pulsador.
JUEGO DEL PONG 
## Objetivo
Diseñar y desarrollar una aplicación en lenguaje C con el cual podamos jugar al ping pong mediante unos sensores de ultrasonido, el juego lleva por nombre Ultrapong.
Especificaciones del juego
Pong (o Tele-Pong) fue un videojuego de la primera generación de videoconsolas publicado por Atari, creado por Nolan Bushnell y lanzado el 29 de noviembre de 1972. Pong está basado en el deporte de tenis de mesa (o ping pong). La palabra Pong es una marca registrada por Atari Interactive, mientras que la palabra genérica «pong» es usada para describir el género de videojuegos «bate y bola». La popularidad de Pong dio lugar a una demanda de infracción de patentes y ganada por parte de los fabricantes de Magnavox Odyssey, que poseía un juego similar. Es un juego de deportes en dos dimensiones que simula un tenis de mesa. El jugador controla en el juego una paleta moviéndola verticalmente en la parte izquierda de la pantalla, y puede competir tanto contra un oponente controlado por computadora, como con otro jugador humano que controla una segunda paleta en la parte opuesta. Los jugadores pueden usar las paletas para pegarle a la pelota hacia un lado u otro. El objetivo consiste en que uno de los jugadores consiga más puntos que el oponente al finalizar el juego. Estos puntos se obtienen cuando el jugador adversario falla al devolver la pelota.

###### Dinámica de la aplicación


menú | 
------------ | 
1-Iniciar partida | 
2-Pausar/reanudar partida  |
3-Mostrar puntuación  | 
4-Abandonar la partida| 


## * _Opción 1 - Iniciar partida_
Primero se deberá elegir entre un jugador o dos. Acto seguido se deberá introducir el nombre de usuario para comenzar la partida. El juego no se iniciará si sendos jugadores tienen el mismo nombre de usuario.
Al elegir 1 jugador este se enfrentará contra la IA, contando esta con varias dificultades desde las más fáciles hasta las más difíciles.

## * -Opción 2 - Pausar/reanudar partida_
Si se desea parar la partida uno de los usuarios, pulsará un botón y la partida se para, al reanudar la partida, el programa cargará los datos almacenados en el fichero de texto y la partida continuará en el punto en el que fue interrumpida.

## * _Opción 3 – Mostrar puntuación 
Mostrará en pantalla la puntuación de los jugadores, al jugador que más puntos haya anotado se le asignará un tag que pondrá MVP (Most valuable player).

## * _Opción 4 – Abandonar partida_
El programa se finalizará dando la victoria al contrario.
Especificación de requisitos obligatorios
El juego contara con bonificaciones aleatorias para el jugador que este ganando, y así complicar la remontada al jugador que vaya por detrás en la partida.
Contaremos con la opción de seleccionar el usuario que queramos usar, para continuar con nuestro progreso en la partida previamente guardada.
El programa cargará los datos de los usuarios desde el fichero al iniciarse la aplicación y almacenará la información en el fichero.
Especificaciones de requisitos adicionales
Podremos guardar varias partidas, de tal manera el usuario escribirá save (nombre), para guardar la partida en dicho fichero.
Contaremos con un jugador predeterminado, la IA el cual tendrá varias dificultades y estrategias que utilizará para ganarnos.



 ## Identificación sensores y actuadores
Para el trabajo precisaremos de sensores de ultrasonido para controlar “las raquetas”, y de un botón con el cual pausemos la partida cuando queramos.
## Medida de la distancia - Sensor ultrasonidos HC-SR04
Queremos controlar las raquetas mediante los ultrasonidos, es decir, de forma que según movamos la mano estas se muevan a la izquierda o a la derecha.
Un sensor de ultra sonidos es un dispositivo para medir distancias. Su funcionamiento se base en el envío de un pulso de alta frecuencia, no audible por el ser humano. Este pulso rebota en los objetos cercanos y es reflejado hacia el sensor, que dispone de un micrófono adecuado para esa frecuencia.
Midiendo el tiempo entre pulsos, conociendo la velocidad del sonido, podemos estimar la distancia del objeto contra cuya superficie impacto el impulso de ultrasonidos
Los sensores de ultrasonidos son sensores baratos, y sencillos de usar. El rango de medición teórico del sensor HC-SR04 es de 2cm a 400 cm, con una resolución de 0.3cm. En la práctica, sin embargo, el rango de medición real es mucho más limitado, en torno a 20cm a 2 metros.
Los sensores de ultrasonidos son sensores de baja precisión. La orientación de la superficie a medir puede provocar que la onda se refleje, falseando la medición. Además, no resultan adecuados en entornos con gran número de objetos, dado que el sonido rebota en las superficies generando ecos y falsas mediciones. Tampoco son apropiados para el funcionamiento en el exterior y al aire libre.
Pese a esta baja precisión, que impide conocer con precisión la distancia a un objeto, los sensores de ultrasonidos son ampliamente empleados. En robótica es habitual montar uno o varios de estos sensores, por ejemplo, para detección de obstáculos, determinar la posición del robot, crear mapas de entorno, o resolver laberintos. En aplicaciones en que se requiera una precisión superior en la medición de la distancia, suelen acompañarse de medidores de distancia por infrarrojos y sensores ópticos.
 ## CÓMO FUNCIONA UN SENSOR DE ULTRASONIDOS
El sensor se basa simplemente en medir el tiempo entre el envío y la recepción de un pulso sonoro. Sabemos que la velocidad del sonido es 343 m/s en condiciones de temperatura 20 ºC, 50% de humedad, presión atmosférica a nivel del mar. Transformando unidades resulta

 

Es decir, el sonido tarda 29,2 microsegundos en recorrer un centímetro. Por tanto, podemos obtener la distancia a partir del tiempo entre la emisión y recepción del pulso mediante la siguiente ecuación.

 

El motivo de divir por dos el tiempo (además de la velociad del sonido en las unidades apropiadas, que hemos calculado antes) es porque hemos medido el tiempo que tarda el pulso en ir y volver, por lo que la distancia recorrida por el pulso es el doble de la que queremos medir.
EJEMPLO DE CÓDIGO
 SIN LIBRERÍAS
Para activar el sensor necesitamos generar un pulso eléctrico en el pin Trigger (disparador) de al menos 10us. Previamente, pondremos el pin a Low durante 4us para asegurar un disparo limpio.
Posteriormente usamos la función "pulseIn" para obtener el tiempo requerido por el pulso para volver al sensor. Finalmente, convertirmos el tiempo en distancia mediante la ecuación correspondiente.
Observar que intentamos emplear siempre aritmética de enteros, evitando usar números en coma flotante. Esto es debido a que las operaciones en coma flotante ralentizan mucho el procesador, y suponen cargar un gran número de librerías en memoria.
const int EchoPin = 5;
const int TriggerPin = 6;
 
void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
}
 
void loop() {
   int cm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(cm);
   delay(1000);
}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}

Fuente: https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/
El principal inconveniente que encontramos es que la lectura de distancias implica bloquear la ejecución del programa mientras esta se lleva a cabo impidiendo que la aplicación realice acciones adicionales mientras espera la medida, además que en el ejemplo que hemos puesto precisamos de, cada sensor requiere dos pines del microcontrolador (Echo y Trigger)
## Pulsador

El funcionamiento básico de un botón es muy sencillo. Básicamente se conecta a un pin digital con el que leerás un 0 o un 1 dependiendo de si lo pulsas o no.
Hay dos formas de conectarlo. El primer tipo de conexion, con la que recibes un 1 cuando pulsas el botón y un 0 cuando no está pulsado. A lo largo del tutorial nosotros vamos a utilizar este tipo de conexión. Sin embargo, vamos a explicar rápidamente como funcionan ambas conexiones por si acaso necesitas saberlo


## Diseño sistema

#include <stdio.h>

#include <locale.h>

#include <stdlib.h>

#include<malloc.h>

int main_menu(void);

void configura(void);

int main()
{
    int menu;
    //configuracion y carga
    configura();
    //bucle ppal
    do
    {
        menu = main_menu();
        switch(menu)
        {
        case 1:break;
        case 2:break;
        case 3:break;
        case 4:break;
        case 5:break;
        }
    } while (menu != 5);
    //desconexion y cierre
}
int main_menu(void)
{
    int option;
    do
    {
        printf("1- Comenzar partida:\n");
        printf("2- \n");
        printf("3- \n");
        printf("4- \n");
        printf("5- Cerrar el juego\n");
        printf("Seleccione una opcion:\n");
        scanf_s("%d", &option);
        if (option < 1 || option>5);
        printf("\nSeleccione una opcion valida, porfavor\n");
    } while (option < 1 || option>5);
    return (option);
}
void configura(void)
{
    setlocale(LC_ALL, "spanish");
}

