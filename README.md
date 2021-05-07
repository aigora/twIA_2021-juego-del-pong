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

/*CÓDIGO ARDUINO*/****************************************

const int EchoPin = 5;
const int TriggerPin = 6;
const int EchoPin2 = 2;
const int TriggerPin2 = 3;

void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(TriggerPin2, OUTPUT);
   pinMode(EchoPin2, INPUT);
}

void loop() {
   int cm = ping(TriggerPin, EchoPin);
   int cm2 = ping(TriggerPin2, EchoPin2);
   /*Se pone una A delante de la distancia del ultrasonido 1 y B delante del 2 para poder analizar posteriormente la correspondencia a cada uno de los sensores al trabajar en visual*/
   Serial.print("A");
   Serial.println(cm);
   Serial.print("B");
   Serial.println(cm2);
   delay(200);
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
int ping2(int TriggerPin2, int EchoPin2) {
   long duration2, distanceCm2;
   
   digitalWrite(TriggerPin2, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin2, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin2, LOW);
   
   duration2 = pulseIn(EchoPin2, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm2 = duration2 * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm2;
}

**********************************************************

Fuente: https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/
El principal inconveniente que encontramos es que la lectura de distancias implica bloquear la ejecución del programa mientras esta se lleva a cabo impidiendo que la aplicación realice acciones adicionales mientras espera la medida, además que en el ejemplo que hemos puesto precisamos de, cada sensor requiere dos pines del microcontrolador (Echo y Trigger).
La distancia recibida por el sensor de ultrasonidos 1 viene dada en cm y es la variabe "cm", la distancia recibida por el segundo también viene dada en cm y es la variable "cm".




/*LIBRERÍAS*/*********************************************
Para poder recibir la señal del arduino (desde el puerto asignado "COM5"), se necesitará la biblioteca "SerialClass.h" para manejar la información desde el visual.

-------SerialClass.h-------

#ifndef SERIALCLASS_H_INCLUDED
#define SERIALCLASS_H_INCLUDED

#define ARDUINO_WAIT_TIME 2000

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

class Serial
{
private:
    //Serial comm handler
    HANDLE hSerial;
    //Connection status
    bool connected;
    //Get various information about the connection
    COMSTAT status;
    //Keep track of last error
    DWORD errors;

public:
    //Initialize Serial communication with the given COM port
    Serial(char* portName);
    //Close the connection
    //NOTA: for some reason you can't connect again before exiting
    //the program and running it again
    ~Serial();
    //Read data in a buffer, if nbChar is greater than the
    //maximum number of bytes available, it will return only the
    //bytes available. The function return -1 when nothing could
    //be read, the number of bytes actually read.
    int ReadData(char* buffer, unsigned int nbChar);
    //Writes data from a buffer through the Serial connection
    //return true on success.
    bool WriteData(char* buffer, unsigned int nbChar);
    //Check if we are actually connected
    bool IsConnected();


};

#endif // SERIALCLASS_H_INCLUDED

---------------------------



------SerialClass.cpp------

#include "SerialClass.h"

Serial::Serial(char *portName)
{
    //We're not yet connected
    this->connected = false;

    //Try to connect to the given port throuh CreateFile
    this->hSerial = CreateFile(portName,
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            NULL);

    //Check if the connection was successfull
    if(this->hSerial==INVALID_HANDLE_VALUE)
    {
        //If not success full display an Error
        if(GetLastError()==ERROR_FILE_NOT_FOUND){

            //Print Error if neccessary
            printf("ERROR: Handle was not attached. Reason: %s not available.\n", portName);

        }
        else
        {
            printf("ERROR!!!");
        }
    }
    else
    {
        //If connected we try to set the comm parameters
        DCB dcbSerialParams = {0};

        //Try to get the current
        if (!GetCommState(this->hSerial, &dcbSerialParams))
        {
            //If impossible, show an error
            printf("failed to get current serial parameters!");
        }
        else
        {
            //Define serial connection parameters for the arduino board
            dcbSerialParams.BaudRate=CBR_9600;
            dcbSerialParams.ByteSize=8;
            dcbSerialParams.StopBits=ONESTOPBIT;
            dcbSerialParams.Parity=NOPARITY;

             //Set the parameters and check for their proper application
             if(!SetCommState(hSerial, &dcbSerialParams))
             {
                printf("ALERT: Could not set Serial Port parameters");
             }
             else
             {
                 //If everything went fine we're connected
                 this->connected = true;
                 //We wait 2s as the arduino board will be reseting
                 Sleep(ARDUINO_WAIT_TIME);
             }
        }
    }

}

Serial::~Serial()
{
    //Check if we are connected before trying to disconnect
    if(this->connected)
    {
        //We're no longer connected
        this->connected = false;
        //Close the serial handler
        CloseHandle(this->hSerial);
    }
}

int Serial::ReadData(char *buffer, unsigned int nbChar)
{
    //Number of bytes we'll have read
    DWORD bytesRead;
    //Number of bytes we'll really ask to read
    unsigned int toRead;

    //Use the ClearCommError function to get status info on the Serial port
    ClearCommError(this->hSerial, &this->errors, &this->status);

    //Check if there is something to read
    if(this->status.cbInQue>0)
    {
        //If there is we check if there is enough data to read the required number
        //of characters, if not we'll read only the available characters to prevent
        //locking of the application.
        if(this->status.cbInQue>nbChar)
        {
            toRead = nbChar;
        }
        else
        {
            toRead = this->status.cbInQue;
        }

        //Try to read the require number of chars, and return the number of read bytes on success
        if(ReadFile(this->hSerial, buffer, toRead, &bytesRead, NULL) && bytesRead != 0)
        {
            return bytesRead;
        }

    }

    //If nothing has been read, or that an error was detected return -1
    return -1;

}


bool Serial::WriteData(char *buffer, unsigned int nbChar)
{
    DWORD bytesSend;

    //Try to write the buffer on the Serial port
    if(!WriteFile(this->hSerial, (void *)buffer, nbChar, &bytesSend, 0))
    {
        //In case it don't work get comm error and return false
        ClearCommError(this->hSerial, &this->errors, &this->status);

        return false;
    }
    else
        return true;
}

bool Serial::IsConnected()
{
    //Simply return the connection status
    return this->connected;
}

---------------------------





## Diseño sistema

#include <stdio.h>

#include <locale.h>

#include <stdlib.h>

#include<malloc.h>

#include <windows.h>

#include"SerialClass.h"

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




## NUEVA ESTRUCTURA DE CODIGO FUNCIONAL
/*Parte del codigo desarrollado con videos de youtube,pues habia partes en las que nos quedabamos trabados*/


#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include "SerialClass"
#define ENCIMA 72
#define ABAJO 80
#define ESC 27
#define N 19

/*La parte de Arduino está pendiente de revisión por problemas al convertir la distancia del sensor 2 a una variable del tipo int manejable*/
//Introducir en la parte correspondiente del juego del Pong

int main() /*Conexión con arduino y lectura de distancias por los ultrasonidos*/
{
	Serial* Arduino;
	char puerto[] = "COM5";
	char BufferEntrada[200], tmp[5], ind, sensor, sensora[3], sensorb[3];
	int bytesRecibidos, i = 0, j = 0, k = 0, sena = 0, senb = 0;
	int esentero(char);
	
	Arduino = new Serial((char*)puerto);
	while (Arduino->IsConnected())
	{
		bytesRecibidos = Arduino->ReadData(BufferEntrada, sizeof(char) * N);
		if (bytesRecibidos != -1) // Lectura de mensaje desde el puerto
		{
			BufferEntrada[bytesRecibidos - 1] = '\0';
			printf("%s\n", BufferEntrada); //Impresión entrada arduino
		}
		/*else
			printf("No se ha recibido nada\n");*/
		printf("-------------\n");
		sensor = ' ';
		
		for (i = 0;i < N;i++) {
			ind = BufferEntrada[i];
			if (ind == 'A') { sensor = 'A';j = 0; k = 0; strcpy_s(sensora, "");}
			if (ind == 'B') { sensor = 'B';j = 0;k = 0;strcpy_s(sensorb, ""); }
			if (esentero(ind) && sensor == 'A' && j < 3) { sensora[j] = ind; j++; }
			if (esentero(ind) && sensor == 'B' && k < 3) { sensorb[k] = ind; k++; }
		}

		printf("sensora:  %s   j:%d   k:%d\n", sensora, j, k);
		printf("sensorb:  %s   j:%d   k:%d\n", sensorb, j, k);

		sena = atoi(sensora);
		senb = atoi(sensorb);

		printf("sena:  %d\n", sena);
		printf("senb:  %d\n", senb);

		Sleep(200);
	}
}
int esentero(char dato) /*Para ver si es un número entero a la hora de analizar los datos de entrada*/
{
	if (dato == '0' || dato == '1' || dato == '2' || dato == '3' || dato == '4' || dato == '5' || dato == '6' || dato == '7' || dato == '8' || dato == '9')
	{
		return 1;
	}
	else {
		return 0;
	}
}





void SetColor(int ForgC)//Funcion para cambiar los colores
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void HideCursor()//Esconder el cursor
{
    CONSOLE_CURSOR_INFO cursor = { 1, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void posicion(int linha, int coluna)//Funcion para colocar las cosas en sus lugares
{
    COORD p = { linha,coluna };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void bola(int x, int y)//Imprime la bola
{
    posicion(x, y);
    SetColor(15);
    printf("%c", 254);
}
void apagabola(int x, int y)//Borra la bola antes de borrar su posicion
{
    posicion(x, y);
    printf(" ");
}
void jugador1_abajo(int linea_j1, int cor)//Movimiento del j1 hacia abajo
{
    int limiteinf = 17;
    SetColor(cor);
    posicion(1, linea_j1 - 1);
    printf(" ");

    posicion(1, linea_j1);
    printf("%c", 178);

    posicion(1, linea_j1 + 1);
    printf("%c", 178);

    posicion(1, linea_j1 + 2);
    printf("%c", 178);

    if (linea_j1 < limiteinf)
    {

        posicion(1, linea_j1 + 3);
        printf(" ");
    }
}
void jugador1_arriba(int linea_j1, int cor)//Movimiento del j1 hacia arriba
{
    int limitesup = 1;
    SetColor(cor);
    posicion(1, linea_j1);
    printf("%c", 178);

    posicion(1, linea_j1 + 1);
    printf("%c", 178);

    posicion(1, linea_j1 + 2);
    printf("%c", 178);

    posicion(1, linea_j1 + 3);
    printf(" ");
    if (linea_j1 > limitesup)
    {
        posicion(1, linea_j1 - 1);
        printf(" ");
    }
}
void jugador2_abajo(int linea_j2, int cor)//Movimiento del j2 hacia abajo
{
    int limiteinf = 17;
    SetColor(cor);
    posicion(58, linea_j2 - 1);
    printf(" ");

    posicion(58, linea_j2);
    printf("%c", 178);

    posicion(58, linea_j2 + 1);
    printf("%c", 178);

    posicion(58, linea_j2 + 2);
    printf("%c", 178);
    if (linea_j2 < limiteinf)
    {
        posicion(58, linea_j2 + 3);
        printf(" ");
    }
}
void jugador2_arriba(int linea_j2, int cor)//Movimiento del j2 hacia arriba
{
    int limitesup = 1;
    SetColor(cor);
    posicion(58, linea_j2);
    printf("%c", 178);

    posicion(58, linea_j2 + 1);
    printf("%c", 178);

    posicion(58, linea_j2 + 2);
    printf("%c", 178);

    posicion(58, linea_j2 + 3);
    printf(" ");
    if (linea_j2 > limitesup)
    {
        posicion(58, linea_j2 - 1);
        printf(" ");
    }
}
void marcador(int punto1, int punto2, int cor1, int cor2)//Imprimimos el marcador en la parte inferior
{
    posicion(15, 22);
    SetColor(15);
    printf("MARCADOR:        -  ");
    posicion(27, 22);
    SetColor(cor1);
    printf("%d", punto1);
    posicion(37, 22);
    SetColor(cor2);
    printf("%d", punto2);
}
void imprimir_pong(int cor)//Imprimimos PONG
{
    int linea = 3, columna = 15, c, l;
    SetColor(cor);

    posicion(columna, linea);
    printf("%c", 201);
    for (c = columna + 1; c < columna + 8; c++)
    {
        posicion(c, linea);
        printf("%c", 205);
    }
    for (l = linea + 1; l < linea + 3; l++)
    {
        posicion(columna, l);
        printf("%c", 186);
    }
    posicion(columna, linea + 3);
    printf("%c", 204);
    for (c = columna + 1; c < columna + 8; c++)
    {
        posicion(c, linea + 3);
        printf("%c", 205);
    }
    for (l = linea + 4; l < linea + 7; l++)
    {
        posicion(columna, l);
        printf("%c", 186);
    }
    posicion(columna + 8, linea);
    printf("%c", 187);
    posicion(columna + 8, linea + 3);
    printf("%c", 188);
    for (l = linea + 1; l < linea + 3; l++)
    {
        posicion(columna + 8, l);
        printf("%c", 186);
    }

    posicion(columna + 10, linea);
    printf("%c", 201);
    for (l = linea + 1; l < linea + 6; l++)
    {
        posicion(columna + 10, l);
        printf("%c", 186);
    }
    for (l = linea + 1; l < linea + 6; l++)
    {
        posicion(columna + 18, l);
        printf("%c", 186);
    }
    posicion(columna + 10, linea + 6);
    printf("%c", 200);
    for (c = columna + 11; c < columna + 18; c++)
    {
        posicion(c, linea);
        printf("%c", 205);
    }
    for (c = columna + 11; c < columna + 18; c++)
    {
        posicion(c, linea + 6);
        printf("%c", 205);
    }
    posicion(columna + 18, linea);
    printf("%c", 187);
    posicion(columna + 18, linea + 6);
    printf("%c", 188);

    posicion(columna + 20, linea);
    printf("%c", 201);
    for (l = linea + 1; l < linea + 7; l++)
    {
        posicion(columna + 20, l);
        printf("%c", 186);
    }
    for (l = linea + 1; l < linea + 7; l++)
    {
        posicion(columna + 29, l);
        printf("%c", 186);
    }
    posicion(columna + 29, linea);
    printf("%c", 187);
    for (c = columna + 21; c < columna + 29; c++)
    {
        posicion(c, linea);
        printf("%c", 205);
    }

    posicion(columna + 31, linea);
    printf("%c", 201);
    for (l = linea + 1; l < linea + 6; l++)
    {
        posicion(columna + 31, l);
        printf("%c", 186);
    }
    posicion(columna + 31, linea + 6);
    printf("%c", 200);
    for (c = columna + 32; c < columna + 39; c++)
    {
        posicion(c, linea + 6);
        printf("%c", 205);
    }
    posicion(columna + 39, linea + 6);
    printf("%c", 188);
    for (l = linea + 5; l > linea + 3; l--)
    {
        posicion(columna + 39, l);
        printf("%c", 186);
    }
    for (c = columna + 36; c < columna + 39; c++)
    {
        posicion(c, linea + 3);
        printf("%c", 205);
    }
    posicion(columna + 39, linea + 3);
    printf("%c", 187);
    for (c = columna + 32; c < columna + 40; c++)
    {
        posicion(c, linea);
        printf("%c", 205);
    }
}
void imprimir_gol(int columna, int linea, int cor)//Imprime aviso objetivo
{
    posicion(20, 7);
    SetColor(cor);
    printf("%c", 201);

    for (columna = 21; columna < 26; columna++)
    {
        posicion(columna, 7);
        printf("%c", 205);
    }

    for (linea = 8; linea < 13; linea++)
    {
        posicion(20, linea);
        printf("%c", 186);
    }

    posicion(20, 13);
    printf("%c", 200);

    for (columna = 21; columna < 25; columna++)
    {
        posicion(columna, 13);
        printf("%c", 205);
    }
    posicion(25, 13);
    printf("%c", 188);
    posicion(25, 12);
    printf("%c", 186);
    posicion(25, 11);
    printf("%c", 187);
    posicion(24, 11);
    printf("%c", 205);

    posicion(27, 7);
    printf("%c", 201);

    for (columna = 28; columna < 33; columna++)
    {
        posicion(columna, 7);
        printf("%c", 205);
    }
    for (linea = 8; linea < 13; linea++)
    {
        posicion(27, linea);
        printf("%c", 186);
    }
    posicion(27, 13);
    printf("%c", 200);

    for (columna = 28; columna < 33; columna++)
    {
        posicion(columna, 13);
        printf("%c", 205);
    }
    for (linea = 8; linea < 13; linea++)
    {
        posicion(33, linea);
        printf("%c", 186);
    }
    posicion(33, 7);
    printf("%c", 187);
    posicion(33, 13);
    printf("%c", 188);

    for (linea = 7; linea < 13; linea++)
    {
        posicion(35, linea);
        printf("%c", 186);
    }
    posicion(35, 13);
    printf("%c", 200);

    for (columna = 36; columna < 41; columna++)
    {
        posicion(columna, 13);
        printf("%c", 205);
    }
}
void imprimir_campo(int columna)//Imprimimos el campo
{
    for (columna = 0; columna < 60; columna++)//Empieza arriba
    {
        posicion(columna, 0);
        SetColor(14);
        printf("%c", 219);
    }

    for (columna = 0; columna < 60; columna++)//Empieza abajo
    {
        posicion(columna, 20);
        SetColor(14);
        printf("%c", 219);
    }
    posicion(61, 2);
    SetColor(15);
    printf("ESC - sair");//Advertencias de la esquina de la pantalla
    posicion(61, 4);
    printf("R - Volver a empezar");
}
void colores()//Paleta de colores para que los jugadores seleccionen uno
{
    posicion(2, 10);
    printf("Introduzca un numero para seleccionar un color\n\n");
    SetColor(9);
    printf("\n\n\t9");
    SetColor(10);
    printf("\t10");
    SetColor(11);
    printf("\t11");
    SetColor(12);
    printf("\t12");
    SetColor(13);
    printf("\t13");
    SetColor(14);
    printf("\t14");
    SetColor(15);
    printf("\t15");
}
int main()
{
    int linea = 0, columna = 0, linea_j1 = 10, linea_j2 = 10, tecla, velocidad, fin = 2, limiteinf = 20, limitesup = 0, x, y, direcy = -1, direcx = -1, punto1 = 0, punto2 = 0, restart = 2, cor1, cor2;
    HideCursor();
    posicion(45, 13);
    printf("Cargando...");//No se esta cargando, pero queda bonito :)
    imprimir_pong(9);//Cambia el color en el que esta escrito pong
    Sleep(500);
    imprimir_pong(10);
    Sleep(500);
    imprimir_pong(11);
    Sleep(500);
    imprimir_pong(12);
    Sleep(500);
    imprimir_pong(13);
    Sleep(500);
    imprimir_pong(14);
    Sleep(500);
    imprimir_pong(15);
    Sleep(500);
    system("cls");
    posicion(15, 2);
    SetColor(15);
    printf("BIENVENIDOS AL JUEGO DEL PONG!!!");//TITULO DEL JUEGO
    posicion(2, 5);
    printf("Instrucciones:\n\tJugador 1: W para ir hacia arriba\n\t           S para ir hacia abajo\n\n");
    printf("\tJugador 2: Flecha para arriba, para ir hacia arriba\n\t           Flecha para abajo, para ir hacia abajo\n\n");
    printf("\t*NO VALE PULSAR EL BOTON CONTINUAMENTE PARA MOVER LAS RAQUETAS*\n");
    printf("Presione cualquier boton para continuar");
    getchar();
    system("cls");
    colores();
    posicion(2, 2);
    printf("Seleccione el color para el jugador 1:\t");//Menu para escoger los colores del j1
    scanf_s("%d", &cor1);
    posicion(2, 4);
    printf("Seleccione el color para el jugador 2:\t");//Menu para escoger los colores del j2
    scanf_s("%d", &cor2);
    system("cls");
    printf("\n\tEn que dificultad quieres jugar?\n\nPresione: [1] Para facil\n\n          [2] Para moderado\n\n          [3] Para dificil\n\n    Seleccionado: ");
    scanf_s("%d", &velocidad);//Elegir la velocidad de l abola
    system("cls");
    if (velocidad == 1)
        velocidad = 100;
    if (velocidad == 2)
        velocidad = 75;
    if (velocidad == 3)
        velocidad = 50;
    printf("\n\nEl primero en anotar 7 goles gana,buena suerte a los jugadores!!!\n\nPresione cualquier boton para comenzar");
    getchar();
    imprimir_campo(columna);//imprimimos el campo
    jugador1_arriba(linea_j1, cor1);//imprime jugador 1
    jugador2_arriba(linea_j2, cor2);//imprime jugador 2
    
       while (fin != 0)//COMIENZO DEL JUEGO
    {
        system("cls");
        imprimir_campo(columna);
        linea_j1 = 9;//coloca al jugador 1 en la  linea 9
        linea_j2 = 9;//coloca al jugador 2 en la  linea 9
        jugador1_arriba(linea_j1, cor1);
        jugador2_arriba(linea_j2, cor2);
        x = 30;
        y = 2 + (rand() % 17);//Empieza siempre desde el centro del campo, pero a una altura aleatoria
        placar(punto1, punto2, cor1, cor2);
        restart = 0;
        getchar();

        while (restart == 0)
        {
            apagabola(x, y);//Borrar la bola antes de actualizar su posicion
            y = y + direcy;//Actualiza y
            x = x + direcx;//Actualiza x
            bola(x, y);//Imprimimos la bola con pos actualizada

            if (y <= limitesup + 1)//Golpea la pelota en la parte superior del campo
            {
                direcy = +1;
            }

            if (y >= limiteinf - 1)//Golpea la pelota en la parte inferior del campo
            {
                direcy = -1;
            }

            if (y == linea_j1 && x == 2 || y == linea_j1 + 1 && x == 2 || y == linea_j1 + 2 && x == 2)//Golpea la pelota en la raqueta del jugador 1
            {
                direcx = +1;
            }

            if (y == linea_j2 && x == 57 || y == linea_j2 + 1 && x == 57 || y == linea_j2 + 2 && x == 57)//Golpea la pelota en la raqueta del jugador 2
            {
                direcx = -1;
            }

            if (x < 2)//GOL DDEL JUGADOR 2
            {
                punto2 = punto2 + 1;
                restart = 2;
            }

            if (x > 58)//GOL DEL JUGADOR 1
            {
                punto1 = punto1 + 1;
                restart = 1;
            }

            if (_kbhit())//MOVIMIENTO DE LAS RAQUETAS
            {
                tecla = getchar();
                if (tecla == 's')//Raqueta 1(hacia abajo)
                {
                    linea_j1++;
                    if (linea_j1 < limiteinf - 2)
                    {
                        jugador1_abajo(linea_j1, cor1);
                    }
                    else
                    {
                        linea_j1--;
                    }
                }

                if (tecla == 'w')//Raqueta 1(hacia arriba)
                {
                    linea_j1--;
                    if (linea_j1 > limitesup)
                    {
                        jugador1_arriba(linea_j1, cor1);
                    }
                    else
                    {
                        linea_j1++;
                    }
                }

                if (tecla == ABAJO)//Raqueta 2(flecha abajo)
                {
                    linea_j2++;
                    if (linea_j2 < limiteinf - 2)
                    {
                        jugador2_abajo(linea_j2, cor2);
                    }
                    else
                    {
                        linea_j2--;
                    }
                }
                if (tecla == ENCIMA)//Raqueta 2(flecha arriba)
                {
                    linea_j2--;
                    if (linea_j2 > limitesup)
                    {
                        jugador2_arriba(linea_j2, cor2);
                    }
                    else
                    {
                        linea_j2++;
                    }
                }
                if (tecla == ESC)//Opcion de boton(Juego ha terminado)
                {
                    return 0;
                }
                if (tecla == 'r')//Reiniciar el juego
                {
                    restart = 3;
                    punto1 = 0;
                    punto2 = 0;
                }
            }
            Sleep(velocidad);
        }//Despues de algun gol
        
        if (restart == 1)//GOL DEL JUGADOR
        {
            imprimir_gol(columna, linea, cor1);
            direcx = -1;
        }
        if (restart == 2)//GOL DEL JUGADOR 2
        {
            imprimir_gol(columna, linea, cor2);
            direcx = +1;
        }
        getchar();
        if (punto1 == 7 || punto2 == 7)//Juego hasta 7 ptos
            fim = 0;//Cuando fim =0 sale del bucle while

    }//FIN DEL JUEGO

    if (punto1 > punto2)
    {
        system("cls");
        posicion(20, 5);
        SetColor(cor1);
        printf("GANA EL JUGADOR 1!!!");
    }
    else
    {
        system("cls");
        posicion(20, 5);
        SetColor(cor2);
        printf("GANA EL JUGADOR 2!!!");
    }
    getchar();
    return 0;
}




