#include <stdio.h>
#include <stdlib.h>
#include <math.h>


char znak,liczba[100];
int liczba_u2[32],i,j,wartosc_znaku=0;

int potega(int a,int b){
int wynik=1;
for(i=0;i<b;i++) wynik=wynik*a;

return wynik;
}

void system_szesnastkowy(){

  printf("\n * Wybrales --> System szesnastkowy\n");
  printf(" * Podaj liczbe: ");
  i=0;int liczba_u[100];
  while((znak=getchar())!=EOF){
    if(znak == '-')wartosc_znaku=1;
    else if(znak == 'A'){liczba_u[i]=10;i++;}
    else if(znak == 'B'){liczba_u[i]=11;i++;}
    else if(znak == 'C'){liczba_u[i]=12;i++;}
    else if(znak == 'D'){liczba_u[i]=13;i++;}
    else if(znak == 'E'){liczba_u[i]=14;i++;}
    else if(znak == 'F'){liczba_u[i]=15;i++;}
    else {
    liczba_u[i]=znak-'0';
    i++;

  }
    if(znak == '\n')break;
  }

  //zamiana z 16 na 10 system
  i=i-2;

  int wynik=0,gorna_granica=i,calkowita,liczba_calkowita=0;
  for(j=0;j<=i;j++) { wynik=(liczba_u[j]*potega(16,gorna_granica))+wynik; gorna_granica--; }
  liczba_calkowita=wynik;

  /// zamiana z 10 na u2
  j=32;
  while(liczba_calkowita != 0){
    j--;
    calkowita = liczba_calkowita/2;
    liczba_u2[j]=liczba_calkowita%2;

    liczba_calkowita=liczba_calkowita/2;

  }
  /*
  * negacja liczby w u2
  */

  if(wartosc_znaku == 1){
  //  printf("\npodales liczbe ujemna\n");
    for(j=0;j<32;j++){
      if(liczba_u2[j] == 1)liczba_u2[j]=0;
      else liczba_u2[j]=1;
    }

    /*
    * dodanie 1 do liczby_u2
    */
    for(j=31;j!=0;j--){
      if(liczba_u2[j]==1)liczba_u2[j] =0;
      else if(liczba_u2[j]==0){liczba_u2[j] = 1; break;}
    }

  printf(" * System U2: ");
  for(j=0;j<32;j++){if(j%8==0)printf(" ");printf("%d",liczba_u2[j]);}

  }
  /// DODATNIA LICZBA
  else {
  //  printf("\nPodales liczbe dodatnia\n");
    printf(" * System U2: ");
    for(j=0;j<32;j++){ if(j%8==0)printf(" ");printf("%d",liczba_u2[j]);}

  }

printf("\n");
}

int system_osemkowy(){
  i=0;
  int liczba_u[100],liczba_calkowita=0;
  printf("\n * Wybrales --> System osemkowy\n");
  printf(" * Podaj liczbe: ");
  while((znak=getchar())!=EOF){
    if(znak == '-')wartosc_znaku=1;
    else {
    liczba_u[i]=znak-'0';

    i++;
  }
    if(znak == '\n')break;
  }

  //zamiana z 8 na 10 system
  i=i-2;
  int wynik=0,gorna_granica=i,calkowita;
  for(j=0;j<=i;j++)  wynik=(liczba_u[j]*potega(8,gorna_granica))+wynik;
  liczba_calkowita=wynik;
  /// zamiana z 10 na u2
  j=32;
  while(liczba_calkowita != 0){
    j--;
    calkowita = liczba_calkowita/2;
    liczba_u2[j]=liczba_calkowita%2;

    liczba_calkowita=liczba_calkowita/2;

  }

  /*
  * negacja liczby w u2
  */

  if(wartosc_znaku == 1){
  //  printf("\npodales liczbe ujemna\n");
    for(j=0;j<32;j++){
      if(liczba_u2[j] == 1)liczba_u2[j]=0;
      else liczba_u2[j]=1;
    }

    /*
    * dodanie 1 do liczby_u2
    */
    for(j=31;j!=0;j--){
      if(liczba_u2[j]==1)liczba_u2[j] =0;
      else if(liczba_u2[j]==0){liczba_u2[j] = 1; break;}
    }

  printf(" * System U2: ");
  for(j=0;j<32;j++){if(j%8==0)printf(" ");printf("%d",liczba_u2[j]);}

  }
  /// DODATNIA LICZBA
  else {
  //  printf("\nPodales liczbe dodatnia\n");
    printf(" * System U2: ");
    for(j=0;j<32;j++){ if(j%8==0)printf(" ");printf("%d",liczba_u2[j]);}

  }



printf("\n");
return 0;
}


void system_binarny(){
  i=0;
  printf("\n * Wybrales --> System binarny\n");
  printf(" * Podaj liczbe: ");
  while((znak=getchar())!=EOF){
    if(znak == '-')wartosc_znaku=1;
    else {
    liczba[i]=znak;
    i++;
  }
    if(znak == '\n')break;
  }

  j=33-i;
  i=0;

  for(j;j<32;j++){
    if(liczba[i]=='1')liczba_u2[j]=1;
    else liczba_u2[j]=0;
    i++;
  }

// zamiana z ujemnej binarnej na u2
  if(wartosc_znaku == 1){

    for(j=0;j<32;j++){
      if(liczba_u2[j] == 1)liczba_u2[j]=0;
      else liczba_u2[j]=1;
    }

    /*
    * dodanie 1 do liczby_u2
    */
    for(j=31;j!=0;j--){
      if(liczba_u2[j]==1)liczba_u2[j] =0;
      else if(liczba_u2[j]==0){liczba_u2[j] = 1; break;}
    }

  printf(" * System U2: ");
  for(j=0;j<32;j++){if(j%8==0)printf(" ");printf("%d",liczba_u2[j]);}

  }
  /// DODATNIA LICZBA
  else {

    printf(" * System U2: ");
    for(j=0;j<32;j++){ if(j%8==0)printf(" ");printf("%d",liczba_u2[j]);}

  }

printf("\n");
}


////////////////////////////////////////////////////////////////////////////////
void system_dziesietny(){

  i=0;
  printf("\n * Wybrales --> System dziesietny\n");
  printf(" * Podaj liczbe: ");
  int liczba_calkowita=0;
  //   wartosc znaku : dla 1 - liczba ujemna , 0 - dodatnia
  while((znak=getchar())!=EOF){
      if(znak == '-')wartosc_znaku=1;
      else {
        liczba[i]=znak;
        i++;}
      if(znak == '\n')break;
  }
  liczba_calkowita = atoi(liczba);
  /// Zamiana z 10 na 2
  int calkowita; j=32;
  while(liczba_calkowita != 0){
    j--;
    calkowita = liczba_calkowita/2;
    liczba_u2[j]=liczba_calkowita%2;

    liczba_calkowita=liczba_calkowita/2;

  }


  /*
  * negacja liczby w u2
  */

  if(wartosc_znaku == 1){
  //  printf("\npodales liczbe ujemna\n");
    for(j=0;j<32;j++){
      if(liczba_u2[j] == 1)liczba_u2[j]=0;
      else liczba_u2[j]=1;
    }

    /*
    * dodanie 1 do liczby_u2
    */
    for(j=31;j!=0;j--){
      if(liczba_u2[j]==1)liczba_u2[j] =0;
      else if(liczba_u2[j]==0){liczba_u2[j] = 1; break;}
    }

  printf(" * System U2: ");
  for(j=0;j<32;j++){if(j%8==0)printf(" ");printf("%d",liczba_u2[j]);}

  }
  /// DODATNIA LICZBA
  else {

    printf(" * System U2\n");
    for(j=0;j<32;j++){ if(j%8==0)printf(" ");printf("%d",liczba_u2[j]);}

  }

  printf("\n");
}





void main(){

printf("\n **********************************************************************\n");
printf(" * Dostepne systemy: 1-binarny,2-osemkowy,3-dziesietny,4-szesnastkowy * \n");
printf(" **********************************************************************\n");
char wybrany_system[]="";
printf(" * Podaj numer wybranego systemu: ");

fgets(wybrany_system, 2, stdin)[0];
while(getchar() != '\n');

if(atoi(wybrany_system) == 3)system_dziesietny();
else if(atoi(wybrany_system) == 2)system_osemkowy();
else if(atoi(wybrany_system) == 1)system_binarny();
else if(atoi(wybrany_system) == 4)system_szesnastkowy();
else printf("blad");
}
