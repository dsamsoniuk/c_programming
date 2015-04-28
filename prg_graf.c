
#include <stdio.h>

int wybor_poprawny=0;
int wyb_graf, ilosc_polaczen,i,j;



int main(){

/****************************************************************************/
/* Dane do pobrania */
for(i=0;i<39;i++)printf("*"); printf("\n");
printf("* Program wyznaczajacy stopien grafu, *\n* stopien punktow oraz macierz        *\n");
for(i=0;i<39;i++)printf("*"); printf("\n");
printf("\nPODAJ DANE\n********************\n");
printf("Liczba wierzcholkow:");   int ilosc_pkt;  scanf("%d",&ilosc_pkt);

/****************************************************************************/




/* Podaj wybor 1 dla prostego, 2 dla skierowanego   */

printf("Typ grafu(1-prosty, 2-skierowany): ");
while(wybor_poprawny!=1){scanf("%d",&wyb_graf);  if(wyb_graf==1 || wyb_graf==2)break; else printf("Typ grafu(1-prosty, 2-skierowany): ");      }


int macierz[ilosc_pkt][ilosc_pkt];
int pkt_1, pkt_2, koniec=1,poprawny=0,blad_pkt=0,pelny_ciag=0;


/* ZEROWANIE tablicy  MACIERZA    */

for(i=0; i<ilosc_pkt; i++)for(j=0;j<ilosc_pkt;j++)macierz[i][j]=0;


/* Podaj dane polaczen miedzy wierzcholkami   -   1-PROSTY    2-SKIEROWANY GRAF */
if(wyb_graf==1){
	printf("Liczba krawedzi: ");  scanf("%d",&ilosc_polaczen);
	printf("***************************** \n Podaj pkt. polaczen (np. 2 3 2 5):\n ");

	while(ilosc_polaczen!=pelny_ciag){
		scanf("%d",&pkt_1); scanf("%d",&pkt_2);
		if(pkt_1>ilosc_pkt || pkt_2 > ilosc_pkt){ printf("%d -> %d, niepoprawny!\n",pkt_1,pkt_2);}
		else if(macierz[pkt_2-1][pkt_1-1]==1)printf("%d -> %d, juz istnieje!\n",pkt_1,pkt_2);
		else {  macierz[pkt_2-1][pkt_1-1]=1; macierz[pkt_1-1][pkt_2-1]=1;  pelny_ciag++; }
	}
}

else if(wyb_graf==2){
	printf("Liczba krawedzi: ");  scanf("%d",&ilosc_polaczen);
	printf("***************************** \n Podaj pkt. polaczen (np. 2 3 2 5):\n ");


/* Sprawdza czy podane 2 liczby sa poprawne oraz wypisze odwortosc liczby jezeli jest ta sama np. 1 2 1 2 napisze w tablicy 1 2 2 1  */

while(ilosc_polaczen!=pelny_ciag){

	scanf("%d",&pkt_1); scanf("%d",&pkt_2);

	if(pkt_1>ilosc_pkt || pkt_2 > ilosc_pkt){ printf("%d -> %d, niepoprawny!\n",pkt_1,pkt_2);}
	else {
		if(macierz[pkt_2-1][pkt_1-1]==1 && macierz[pkt_1-1][pkt_2-1]==1)printf("%d -> %d, juz istnieje!\n",pkt_1,pkt_2);
		else{

		if(macierz[pkt_2-1][pkt_1-1]==1)macierz[pkt_1-1][pkt_2-1]=1;
		else if(macierz[pkt_1-1][pkt_2-1]==1)macierz[pkt_2-1][pkt_1-1]=1;
		else macierz[pkt_2-1][pkt_1-1]=1;

		pelny_ciag++;
		}
	}

}

}


/* Zerowanie tablicy stopien_wierz   */

int stopien_wierz[ilosc_pkt];
for(i=0; i<ilosc_pkt; i++)stopien_wierz[i]=0;


/* Wyznaczyc stopien wierzcholkow, zliczanie punktow w wierszu */

for(i=0;i<ilosc_pkt;i++)
	for(j=0;j<ilosc_pkt;j++)
		if(macierz[j][i]==1)stopien_wierz[i]++;


/* Dodatkowy tytul nazwa grau */
printf("\n\n****************************");
if(wyb_graf==1){   printf("\nGRAF PROSTY"); }
if(wyb_graf==2){   printf("\nGRAF SKIEROWANY"); }
printf("\n****************************");

/* Wyswietl tablice wierzcholkow  */

printf("\n1. Stopnie podanych wierzcholkow\n");
for(i=0;i<ilosc_pkt;i++)printf(" [%d]=%dst. ",i+1,stopien_wierz[i]);
printf("\n");


/* Wyswietl najwiekrzy element z tablicy stopien_wierz  */

int najwiekszy_st_grafu=0;
for(i=0;i<ilosc_pkt;i++){

/***************** Lamie petle jak juz podaje ostatni element z tablicy stopien_wierz */ if(i==ilosc_pkt)break;

	if(stopien_wierz[i] > stopien_wierz[najwiekszy_st_grafu]) najwiekszy_st_grafu=i;
	else  najwiekszy_st_grafu = najwiekszy_st_grafu;
}

/*Wyswietl najwiekszy stopien grafu */

printf("2. Graf jest stopnia %d \n",stopien_wierz[najwiekszy_st_grafu]);


 /* Wyswietl macierz juz po podaniu danych i wczesniejszym zerowaniu */

printf("3. Macierz wyznaczonego grafu\n   ");
for(i=1;i<=ilosc_pkt;i++)printf("%d ",i); printf("\n  -");
for(i=1;i<=ilosc_pkt;i++)printf("--"); printf("\n");
for(i=0;i<ilosc_pkt;i++){
 	if(i<9)printf("%d |",i+1);else printf("%d|",i+1);
	for(j=0;j<ilosc_pkt;j++)
		if(j>=9)printf(" %d ",macierz[j][i]);
		else printf("%d ",macierz[j][i]);
	printf("\n");
}

return 0;
}
