#include<windows.h> 
#include<stdio.h> 
#include<conio.h> 
#include <stdlib.h> 
#include "SerialClass.h" 
#define ENCIMA 72 
#define ABAJO 80 
#define N 20

int esentero(char dato); //Funcion para identificar si es un numero el caracter que llega de la señal de entrada del Arduino

void SetColor(int ForgC); //Funcion para cambiar los colores

void HideCursor(); //Esconder el cursor

void posicion(int linea, int columna); //Funcion para colocar las cosas en su sitio

void posicion1(int linea1, int columna1); //Funcion para colocar las cosas en su sitio

void posicion2(int linea2, int columna2); //Funcion para colocar las cosas en su sitio

void bola(int x, int y); //Imprime la bola

void borrabola(int x, int y); //Borra la bola antes de borrar su posicion

void jugador1_pos(int linea_j1, int color); //Movimiento del j1

void jugador2_pos(int linea_j2, int color);//Movimiento del j2

void muro(); //Muro

void borrajugador1_pos(int linea_j1);//Borra movimiento del j1

void borrajugador2_pos(int linea_j2);//Borra movimiento del j2

void marcador(int punto1, int punto2, int color1, int color2); //Imprimimos el marcador en la parte inferior

void marcador_practica(int punto2, int puntuacion_muro);//Marcador en el modo práctica //Uso de fichero marcador.txt

void imprimir_campo(int columna);//Imprimimos el campo

void imprimir_campo_gol(int columna);//Imprimimos el campo gol

void imprimir_mvp(int punto1, int punto2);//Imprimimos el mvp (jugador con más puntuación) en el modo 2 jugadores

int main() /////////
{
    int linea = 0, columna = 0, linea_j1 = 10, linea_j2 = 10, tecla, velocidad, fin = 2;
    int limiteinf = 20, limitesup = 0, x, y, direcy = -1, direcx = -1, punto1 = 0, punto2 = 0; 
    int restart = 2, color1 = 9, color2 = 9, puntuacion_muro;

    Serial* Arduino;
    char puerto[] = "COM5";
    char BufferEntrada[200], tmp[5], ind, sensor, sensora[3], sensorb[3];
    int bytesRecibidos, i = 0, j = 0, k = 0, sena = 0, senb = 0;
    int esentero(char);

    Arduino = new Serial((char*)puerto);



    HideCursor();
    SetColor(15);
    posicion(30, 2);
    printf("JUEGO DEL PONG");//TITULO DEL JUEGO
    posicion(2, 5);
    SetColor(12);
    printf("AVISO IMPORTANTE:");
    posicion(3, 7);
    SetColor(14);
    printf("Para poder jugar a este este juego es preciso disponer y tener conectado");
    posicion(3, 8);
    printf("durante la partida el circuito de ultrasonidos montado en Arduino.");
    posicion(3, 10);
    printf("Se recomienda no hacer movimientos demasiados bruscos a la hora de controlar");
    posicion(3, 11);
    printf("las palas, el rango de movimiento se encuentra entre 0 y 20 cm de distancia de");
    posicion(3, 12);
    printf("los ultrasonidos.");
    posicion(3, 14);
    printf("A cada jugador le corresponde un solo sensor.(Se recomienda practicar previamente)");
    SetColor(11);
    posicion(2, 17);
    printf("PRESIONA ENTER PARA COMENZAR");

    getchar();

    int tecla_opcion_menu = 0;

    while (tecla_opcion_menu != 2 && tecla_opcion_menu != 1 && tecla_opcion_menu != 3) {
        system("cls");
        SetColor(15);
        posicion(30, 2);
        printf("SELECCIONE MODO DE JUEGO");//MENU PRINCIPAL
        posicion(3, 6);
        SetColor(11);
        printf("1 - Un jugador (modo entrenamiento)");
        posicion(3, 7);
        printf("2 - Dos jugadores");
        posicion(3, 8);
        printf("3 - Salir del juego");
        scanf_s("%d", &tecla_opcion_menu);

        switch (tecla_opcion_menu)
        {
        case 1:
            system("cls");
            velocidad = 100;
            puntuacion_muro = 0;
            posicion(22, 5);
            printf("Dispones de 7 vidas");
            posicion(20, 7);
            printf("    %cBuena suerte!", 173);
            Sleep(5000);
            getchar();


            imprimir_campo(columna);//imprimimos el campo
            jugador1_pos(linea_j1, color1);//imprime jugador 1

            while (fin != 0)//COMIENZO DEL JUEGO
            {
                system("cls");
                imprimir_campo(columna);
                marcador_practica(punto2, puntuacion_muro);
                linea_j1 = 9;//coloca al jugador 1 en la  linea 9
                jugador1_pos(linea_j1, color1);
                x = 30;
                y = 2 + (rand() % 17);//Empieza siempre desde el centro del campo, pero a una altura aleatoria
                restart = 0;


                while (restart == 0)
                {

                    while (Arduino->IsConnected())//INICIO ARDUINO
                    {

                        bytesRecibidos = Arduino->ReadData(BufferEntrada, sizeof(char) * N);
                        if (bytesRecibidos != -1) // Lectura de mensaje desde el puerto
                        {
                            BufferEntrada[bytesRecibidos - 1] = '\0';
                        }
                        sensor = ' ';

                        for (i = 0; i < (N / 2); i++) {
                            ind = BufferEntrada[i];
                            if (ind == 'A') { sensor = 'A'; j = 0; k = 0; strcpy_s(sensora, ""); }
                            if (ind == 'B') { sensor = 'B'; j = 0; k = 0; strcpy_s(sensorb, ""); }
                            if (esentero(ind) && sensor == 'A' && j < 3) { sensora[j] = ind; j++; }
                            if (esentero(ind) && sensor == 'B' && k < 3) { sensorb[k] = ind; k++; }
                        }
                        sena = atoi(sensora);
                        senb = atoi(sensorb);

                        //Sleep(200);



                        posicion(0, 27);
                        printf("sena: %d", sena);
                        posicion(0, 28);
                        printf("senb: %d", senb);


                        borrabola(x, y);//Borrar la bola antes de actualizar su posicion
                        borrajugador1_pos(linea_j1);
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


                        if (x == 57)//Golpea el muro
                        {
                            direcx = -1;
                            puntuacion_muro++;
                            marcador_practica(punto2, puntuacion_muro);
                        }

                        if (x < 2)//Pierdes 1 vida
                        {
                            punto2 = punto2 + 1;
                            puntuacion_muro = 0;
                            imprimir_campo_gol(columna);
                            marcador_practica(punto2, puntuacion_muro);
                            restart = 2;
                            Sleep(1000);
                            break;
                        }



                        if (_kbhit())//MOVIMIENTO DE LAS RAQUETAS
                        {
                            tecla = 1;

                            if (sena >= 0 && sena <= 20)//Raqueta 1 ultrasonidos
                            {
                                linea_j1 = sena;
                                jugador1_pos(linea_j1, color1);
                            }

                            muro();
                        }
                        Sleep(velocidad);
                    }
                }
                //getchar();
                if (punto1 == 7 || punto2 == 7)//Juego hasta 7 ptos
                    fin = 0;//Cuando fin =0 sale del bucle while

            }//FIN DEL JUEGO

            tecla_opcion_menu = 0;
            fin = 2;
            punto1 = 0;
            punto2 = 0;          

            break;
        case 2:

            system("cls");
            velocidad = 100;
            posicion(20, 5);
            printf("Victoria al mejor de 7");
            posicion(20, 7);
            printf("    %cBuena suerte!", 173);
            Sleep(5000);
            getchar();
            system("cls");

            imprimir_campo(columna);//imprimimos el campo
            jugador1_pos(linea_j1, color1);//imprime jugador 1
            jugador2_pos(linea_j2, color2);//imprime jugador 2

            while (fin != 0)//COMIENZO DEL JUEGO
            {
                system("cls");
                imprimir_campo(columna);
                imprimir_mvp(punto1, punto2);
                linea_j1 = 9;//coloca al jugador 1 en la  linea 9
                linea_j2 = 9;//coloca al jugador 2 en la  linea 9
                jugador1_pos(linea_j1, color1);
                jugador2_pos(linea_j2, color2);
                x = 30;
                y = 2 + (rand() % 17);//Empieza siempre desde el centro del campo, pero a una altura aleatoria
                marcador(punto1, punto2, color1, color2);
                restart = 0;


                while (restart == 0)
                {

                    while (Arduino->IsConnected())//INICIO ARDUINO
                    {

                        bytesRecibidos = Arduino->ReadData(BufferEntrada, sizeof(char) * N);
                        if (bytesRecibidos != -1) // Lectura de mensaje desde el puerto
                        {
                            BufferEntrada[bytesRecibidos - 1] = '\0';
                        }
                        sensor = ' ';

                        for (i = 0; i < (N / 2); i++) {
                            ind = BufferEntrada[i];
                            if (ind == 'A') { sensor = 'A'; j = 0; k = 0; strcpy_s(sensora, ""); }
                            if (ind == 'B') { sensor = 'B'; j = 0; k = 0; strcpy_s(sensorb, ""); }
                            if (esentero(ind) && sensor == 'A' && j < 3) { sensora[j] = ind; j++; }
                            if (esentero(ind) && sensor == 'B' && k < 3) { sensorb[k] = ind; k++; }
                        }
                        sena = atoi(sensora);
                        senb = atoi(sensorb);

                        //Sleep(200);



                        posicion(0, 27);
                        printf("sena: %d", sena);
                        posicion(0, 28);
                        printf("senb: %d", senb);


                        borrabola(x, y);//Borrar la bola antes de actualizar su posicion
                        borrajugador1_pos(linea_j1);
                        borrajugador2_pos(linea_j2);
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

                        if (x < 2)//GOL DEL JUGADOR 2
                        {
                            punto2 = punto2 + 1;
                            imprimir_campo_gol(columna);
                            marcador(punto1, punto2, color1, color2);
                            imprimir_mvp(punto1, punto2);
                            restart = 2;
                            Sleep(1000);
                            break;
                        }

                        if (x > 58)//GOL DEL JUGADOR 1
                        {
                            punto1 = punto1 + 1;
                            imprimir_campo_gol(columna);
                            marcador(punto1, punto2, color1, color2);
                            imprimir_mvp(punto1, punto2);
                            restart = 1;
                            Sleep(1000);
                            break;
                        }

                        if (_kbhit())//MOVIMIENTO DE LAS RAQUETAS
                        {
                            tecla = 1;

                            if (sena >= 0 && sena <= 20)//Raqueta 1 ultrasonidos
                            {
                                linea_j1 = sena;
                                jugador1_pos(linea_j1, color1);
                            }
                            if (senb >= 0 && senb <= 20)//Raqueta 2 ultrasonidos
                            {
                                linea_j2 = senb;
                                jugador2_pos(linea_j2, color2);
                            }
                        }
                        Sleep(velocidad);
                    }
                }
                //getchar();

                if (punto1 == 7 || punto2 == 7)//Juego hasta 7 ptos
                    fin = 0;//Cuando fin =0 sale del bucle while

            }//FIN DEL JUEGO


            if (punto1 > punto2)
            {
                system("cls");
                posicion(20, 5);
                printf("HA GANADO EL JUGADOR 1");
            }
            else
            {
                system("cls");
                posicion(20, 5);
                printf("HA GANADO EL JUGADOR 2");
            }

            tecla_opcion_menu = 0;
            fin = 2;
            punto1 = 0;
            punto2 = 0;
            Sleep(5000);
            getchar();

            break;

        case 3:

            printf("Pulse cualquier tecla para salir del juego");
            break;

        default:
            printf("Opción incorrecta\n");

        }
    }
}

int esentero(char dato)
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

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor = { 1, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void posicion(int linea, int columna)//Funcion para colocar las cosas en su sitio
{
    COORD p = { linea,columna };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void posicion1(int linea1, int columna1)//Funcion para colocar las cosas en su sitio
{
    COORD p1 = { linea1,columna1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p1);
}

void posicion2(int linea2, int columna2)//Funcion para colocar las cosas en su sitio
{
    COORD p2 = { linea2,columna2 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p2);
}

void bola(int x, int y)//Imprime la bola
{
    posicion(x, y);
    SetColor(15);
    printf("%c", 79);
}

void borrabola(int x, int y)//Borra la bola antes de borrar su posicion
{
    posicion(x, y);
    printf(" ");
}

void jugador1_pos(int linea_j1, int color)//Movimiento del j1
{
    int limiteinf = 17;
    SetColor(color);
    posicion(1, linea_j1 - 1);
    printf(" ");

    posicion(1, linea_j1);
    printf("%c", 219);

    posicion(1, linea_j1 + 1);
    printf("%c", 219);

    posicion(1, linea_j1 + 2);
    printf("%c", 219);

    if (linea_j1 < limiteinf)
    {

        posicion(1, linea_j1 + 3);
        printf(" ");
    }

    int limitesup = 1;
    SetColor(color);
    posicion(1, linea_j1);
    printf("%c", 219);

    posicion(1, linea_j1 + 1);
    printf("%c", 219);

    posicion(1, linea_j1 + 2);
    printf("%c", 219);

    posicion(1, linea_j1 + 3);
    printf(" ");

    if (linea_j1 > limitesup)
    {
        posicion(1, linea_j1 - 1);
        printf(" ");
    }
}

void jugador2_pos(int linea_j2, int color)//Movimiento del j2
{
    int limiteinf = 17;
    SetColor(color);
    posicion(59, linea_j2 - 1);
    printf(" ");

    posicion(59, linea_j2);
    printf("%c", 219);

    posicion(59, linea_j2 + 1);
    printf("%c", 219);

    posicion(59, linea_j2 + 2);
    printf("%c", 219);

    if (linea_j2 < limiteinf)
    {

        posicion(59, linea_j2 + 3);
        printf(" ");
    }

    int limitesup = 1;
    SetColor(color);
    posicion(59, linea_j2);
    printf("%c", 219);

    posicion(59, linea_j2 + 1);
    printf("%c", 219);

    posicion(59, linea_j2 + 2);
    printf("%c", 219);

    posicion(59, linea_j2 + 3);
    printf(" ");

    if (linea_j2 > limitesup)
    {
        posicion(59, linea_j2 - 1);
        printf(" ");
    }
}

void muro()//Muro
{

    int m;
    SetColor(15);
    for (m = 0; m < 20; m++)
    {

        posicion(59, m);
        printf("%c", 219);


    }

}

void borrajugador1_pos(int linea_j1)//Borra movimiento del j1
{
    posicion1(1, linea_j1);
    printf(" ");

    posicion1(1, linea_j1 + 1);
    printf(" ");

    posicion1(1, linea_j1 + 2);
    printf(" ");
}

void borrajugador2_pos(int linea_j2)//Borra movimiento del j2
{
    posicion1(59, linea_j2);
    printf(" ");

    posicion1(59, linea_j2 + 1);
    printf(" ");

    posicion1(59, linea_j2 + 2);
    printf(" ");
}

void marcador(int punto1, int punto2, int color1, int color2)//Imprimimos el marcador en la parte inferior
{
    posicion(30, 22);
    SetColor(15);
    printf("-");
    posicion(25, 22);
    SetColor(11);
    printf("%d", punto1);
    posicion(35, 22);
    SetColor(11);
    printf("%d", punto2);
}

void marcador_practica(int punto2, int puntuacion_muro)//Marcador en el modo práctica //Uso de fichero marcador.txt
{
    int aux, leer;
    int escr;
    int record_maximo, vidas_restantes;

    vidas_restantes = 7 - punto2;

    FILE* marcadores;
    errno_t err;

    err = fopen_s(&marcadores, "marcadores.txt", "a+");
    //Verificación de apertura del archivo
    if (err == NULL)
        printf("\n");

    else
    {
        printf("Error al abrir el fichero.\n");
        Sleep(300);
        exit(1);
    }

    while (!feof(marcadores))
    {
        fscanf_s(marcadores, "%d", &leer);
    }

    fclose(marcadores);

    if (leer < puntuacion_muro)
    {
        fopen_s(&marcadores, "marcadores.txt", "w");
        record_maximo = puntuacion_muro;
        fprintf(marcadores, "%d", record_maximo);

    }

    fclose(marcadores);

    err = fopen_s(&marcadores, "marcadores.txt", "a+");
    //Verificación de apertura del archivo
    if (err == NULL)
        printf("\n");

    else
    {
        printf("Error al abrir el fichero.\n");
        Sleep(300);
        exit(1);
    }

    while (!feof(marcadores))
    {
        fscanf_s(marcadores, "%d", &aux);
    }
    //printf("%d", aux);

    fclose(marcadores);

    //Marcadores
    posicion(0, 22);
    SetColor(15);
    printf("Vidas restantes:  ");
    SetColor(10);
    printf("%d", vidas_restantes);//Vidas restantes

    posicion(0, 23);
    SetColor(15);
    printf("Intento actual:  ");
    SetColor(11);
    printf("%d", puntuacion_muro);//Golpes muro

    posicion(0, 24);
    SetColor(15);
    printf("Mejor intento:  ");
    SetColor(6);
    printf("%d", aux);//Mejor marca
}
void imprimir_campo(int columna)//Imprimimos el campo
{
    for (columna = 0; columna < 60; columna++)//Empieza arriba
    {
        posicion(columna, 0);
        SetColor(8);
        printf("%c", 219);
    }

    for (columna = 0; columna < 60; columna++)//Empieza abajo
    {
        posicion(columna, 20);
        SetColor(8);
        printf("%c", 219);
    }
   
}

void imprimir_campo_gol(int columna)//Imprimimos el campo gol
{
    for (columna = 0; columna < 60; columna++)//Empieza arriba
    {
        posicion(columna, 0);
        SetColor(6);
        printf("%c", 219);
    }

    for (columna = 0; columna < 60; columna++)//Empieza abajo
    {
        posicion(columna, 20);
        SetColor(6);
        printf("%c", 219);
    }
    
}

void imprimir_mvp(int punto1, int punto2)//Imprimimos el mvp
{
    if (punto1 == punto2) {
        posicion(23, 22);
        SetColor(6);
        printf(" ");
        posicion(37, 22);
        SetColor(6);
        printf(" ");
    }
    if (punto1 > punto2) {
        posicion(23, 22);
        SetColor(6);
        printf("%c", 175);
        posicion(37, 22);
        SetColor(6);
        printf(" ");
    }
    if (punto1 < punto2) {
        posicion(23, 22);
        SetColor(6);
        printf(" ");
        posicion(37, 22);
        SetColor(6);
        printf("%c", 174);
    }
}
