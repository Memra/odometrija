#ifndef REGULACIJA_H
#define	REGULACIJA_H

#ifndef FCY
#define FCY 29491200ULL
#endif

#define PI	3.1415926535897932384626433832795
#define d_tocka	52.5 // precnik odometrijskog tocka
#define D_tocka	275 //rastojanje izmedju tockova
#define K1	(long)(40000.0f * D_tocka / d_tocka)  //broj ikremenata po krugu
#define K2	(long)(20000.0f / (d_tocka * PI))  //za konverziju mm u inkremente == 121.26
#define Gp_D	0.8
#define Gd_D	5
#define Gp_T	0.4
#define Gd_T	1.66

//#define STATUS_IDLE     'I'
//#define STATUS_MOVING   'M'
//#define STATUS_STUCK    'S'
enum States
{
    STATUS_IDLE,
    STATUS_MOVING,
    STATUS_ROTATING,
    STATUS_STUCK,
    STATUS_ERROR
};

void resetDriver(void);
// zadavanje pozicije
void setPosition(int X, int Y, int orientation);

void sendStatusAndPosition(void);

//zadavanje brzine i ubrzanja
void setSpeedAccel(float v);

//funkcija za stizanje u tacku (Xd, Yd)
void gotoXY(int Xd, int Yd, unsigned char krajnja_brzina, char smer);

//funkcija za kretanje pravo s trapezoidnim profilom brzine
void kretanje_pravo(int duzina, unsigned char krajnja_brzina);

//funkcija za dovodjenje robota u zeljenu apsolutnu orjentaciju
void apsolutni_ugao(int ugao);

//funkcija za okretanje oko svoje ose s trapezoidnim profilom brzine
char okret(int ugao);//ne vraca indikaciju

//funkcija za kretanje po kruznoj putanji
void kurva(long Xc, long Yc, int Fi, char smer);

void stop(void);
void setSpeed(unsigned char tmp);

enum States getStatus(void);

void forceStatus(enum States);

#endif	/* REGULACIJA_H */

