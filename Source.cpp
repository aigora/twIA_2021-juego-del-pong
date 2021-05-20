#include<windows.h> 
#include<stdio.h> 
#include<conio.h> 
#include <stdlib.h> 
#include "SerialClass.h" 
#define ENCIMA 72 
#define ABAJO 80 
#define ESC 27
#define N 20

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
void HideCursor()//Esconder el cursor
{
    CONSOLE_CURSOR_INFO cursor = { 1, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void posicion(int linea, int columna)//Funcion para colocar las cosas en sus lugares
{
    COORD p = { linea,columna };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void posicion1(int linea1, int columna1)//Funcion para colocar las cosas en sus lugares
{
    COORD p1 = { linea1,columna1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p1);
}
void posicion2(int linea2, int columna2)//Funcion para colocar las cosas en sus lugares
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
void apagabola(int x, int y)//Borra la bola antes de borrar su posicion
{
    posicion(x, y);
    printf(" ");
}
/*
void jugador1_abajo(int linea_j1, int cor)//Movimiento del j1 hacia abajo
{
    int limiteinf = 17;
    SetColor(cor);
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
}
void jugador1_arriba(int linea_j1, int cor)//Movimiento del j1 hacia arriba
{
    int limitesup = 1;
    SetColor(cor);
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
*/


void jugador1_pos(int linea_j1, int cor)//Movimiento del j1
{
    int limiteinf = 17;
    SetColor(cor);
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
    SetColor(cor);
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

void jugador2_pos(int linea_j2, int cor)
{
    int limiteinf = 17;
    SetColor(cor);
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
    SetColor(cor);
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

void apagajugador1_pos(int linea_j1)//Borra movimiento del j1
{
    posicion1(1, linea_j1);
    printf(" ");

    posicion1(1, linea_j1 + 1);
    printf(" ");

    posicion1(1, linea_j1 + 2);
    printf(" ");
}
void apagajugador2_pos(int linea_j2)//Borra movimiento del j2
{
    posicion1(59, linea_j2);
    printf(" ");

    posicion1(59, linea_j2 + 1);
    printf(" ");

    posicion1(59, linea_j2 + 2);
    printf(" ");
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
/*
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
}*/
void placar(int punto1, int punto2, int cor1, int cor2)//Imprimimos el marcador en la parte inferior
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
    posicion(0, 24);
    SetColor(15);
    printf("ESC - sair");//Advertencias de la esquina de la pantalla
    posicion(0, 25);
    printf("R - Volver a empezar");
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
    posicion(0, 24);
    SetColor(15);
    printf("ESC - sair");//Advertencias de la esquina de la pantalla
    posicion(0, 25);
    printf("R - Volver a empezar");
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



int main() /////////
{
    int linea = 0, columna = 0, linea_j1 = 10, linea_j2 = 10, tecla, velocidad, fim = 2, limiteinf = 20, limitesup = 0, x, y, direcy = -1, direcx = -1, punto1 = 0, punto2 = 0, restart = 2, cor1 = 9, cor2 = 9;


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
    printf("Se arrecomienda no hacer movimientos demasiados bruscos a la hora de controlar");
    posicion(3, 11);
    printf("las palas, el rango de movimiento se encuentra entre 0 y 20 cm de distancia de");
    posicion(3, 12);
    printf("los ultrasonidos.");
    posicion(3, 14);
    printf("A cada jugador le corresponde un solo sensor.");
    SetColor(11);
    posicion(2, 17);
    printf("PRESIONA ENTER PARA COMENZAR");

    getchar();

    int tecla_opcion_menu = 0;

    while (tecla_opcion_menu != 2 && tecla_opcion_menu != 1) {
        system("cls");
        SetColor(15);
        posicion(30, 2);
        printf("SELECCIONE MODO DE JUEGO");//MENU PRINCIPAL
        posicion(3, 6);
        SetColor(11);
        printf("1 - Un jugador");
        posicion(3, 7);
        printf("2 - Dos jugadores");
        scanf_s("%d", &tecla_opcion_menu);

        if (tecla_opcion_menu == 2)//2 JUGADORES
        {
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
            jugador1_pos(linea_j1, cor1);//imprime jugador 1
            jugador2_pos(linea_j2, cor2);//imprime jugador 2

            while (fim != 0)//COMIENZO DEL JUEGO
            {
                system("cls");
                imprimir_campo(columna);
                imprimir_mvp(punto1, punto2);
                linea_j1 = 9;//coloca al jugador 1 en la  linea 9
                linea_j2 = 9;//coloca al jugador 2 en la  linea 9
                jugador1_pos(linea_j1, cor1);
                jugador2_pos(linea_j2, cor2);
                x = 30;
                y = 2 + (rand() % 17);//Empieza siempre desde el centro del campo, pero a una altura aleatoria
                placar(punto1, punto2, cor1, cor2);
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

                        for (i = 0;i < (N / 2);i++) {
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


                        apagabola(x, y);//Borrar la bola antes de actualizar su posicion
                        apagajugador1_pos(linea_j1);
                        apagajugador2_pos(linea_j2);
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
                            placar(punto1, punto2, cor1, cor2);
                            imprimir_mvp(punto1, punto2);
                            restart = 2;
                            Sleep(1000);
                            break;
                        }

                        if (x > 58)//GOL DEL JUGADOR 1
                        {
                            punto1 = punto1 + 1;
                            imprimir_campo_gol(columna);
                            placar(punto1, punto2, cor1, cor2);
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
                                jugador1_pos(linea_j1, cor1);
                            }
                            if (senb >= 0 && senb <= 20)//Raqueta 1 ultrasonidos
                            {
                                linea_j2 = senb;
                                jugador2_pos(linea_j2, cor2);
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
                    }
                }
                //getchar();
                if (punto1 == 7 || punto2 == 7)//Juego hasta 7 ptos
                    fim = 0;//Cuando fim =0 sale del bucle while

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
            fim = 2;
            punto1 = 0;
            punto2 = 0;
            Sleep(5000);
            getchar();
        }
        
        if (tecla_opcion_menu == 1)//1 JUGADOR
        {
            system("cls");
            velocidad = 100;
            posicion(20, 5);
            printf("Victoria al mejor de 7");
            posicion(20, 7);
            printf("    %cBuena suerte!", 173);
            Sleep(5000);
            getchar();


            imprimir_campo(columna);//imprimimos el campo
            jugador1_pos(linea_j1, cor1);//imprime jugador 1

            while (fim != 0)//COMIENZO DEL JUEGO
            {
                system("cls");
                imprimir_campo(columna);
                imprimir_mvp(punto1, punto2);
                linea_j1 = 9;//coloca al jugador 1 en la  linea 9
                jugador1_pos(linea_j1, cor1);
                x = 30;
                y = 2 + (rand() % 17);//Empieza siempre desde el centro del campo, pero a una altura aleatoria
                placar(punto1, punto2, cor1, cor2);
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

                        for (i = 0;i < (N / 2);i++) {
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


                        apagabola(x, y);//Borrar la bola antes de actualizar su posicion
                        apagajugador1_pos(linea_j1);
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
                        //if (y == linea_j2 && x == 57 || y == linea_j2 + 1 && x == 57 || y == linea_j2 + 2 && x == 57)//Golpea la pelota en la raqueta del jugador 2
                        
                        if (x == 57)//Golpea la pelota en la raqueta del jugador 2
                        {
                            direcx = -1;
                        }
                        
                        if (x < 2)//GOL DEL JUGADOR 2
                        {
                            punto2 = punto2 + 1;
                            imprimir_campo_gol(columna);
                            placar(punto1, punto2, cor1, cor2);
                            imprimir_mvp(punto1, punto2);
                            restart = 2;
                            Sleep(1000);
                            break;
                        }

                        if (x > 58)//GOL DEL JUGADOR 1
                        {
                            punto1 = punto1 + 1;
                            imprimir_campo_gol(columna);
                            placar(punto1, punto2, cor1, cor2);
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
                                jugador1_pos(linea_j1, cor1);
                            }

                            muro();

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
                    }
                }
                //getchar();
                if (punto1 == 7 || punto2 == 7)//Juego hasta 7 ptos
                    fim = 0;//Cuando fim =0 sale del bucle while

            }//FIN DEL JUEGO

            tecla_opcion_menu = 0;
            fim = 2;
            punto1 = 0;
            punto2 = 0;
        }
    }
}