#include <stdio.h>			// PODSTAWOWA BIBLIOTEKA
#include <string.h>			// BIBLIOTEKA ABY BYLA FUNKCJA STRICMP
#include <unistd.h>			
#include <windows.h>		// BIBLIOTEKA ABY BYLA FUNKCJA SLEEP TYLKO DLA WINDOWS
#include <stdlib.h>			// BIBLIOTEKA FUNKCJI SRAND RAND SYSTEM CLS 
#include <time.h>			// BIBLIOTEKA FUNKCJI DO WYDARZEN LOSOWYCH W SRAND ZMIENNA BYL CZAS KTORY SIE ZMIENIA



int czas_2 = 2000;
int czas_4 = 3500;
char text[20];
char droga[20];
char dom[20];
int czas_1 = 1000;
int czas_3 = 3000;
int czas_5 = 5000;
int czas_6 = 200;
int wybor;
int handlarz_done = 0, wiedzma_done = 0;
int player_hp = 20;   // Punkty zdrowia gracza
    int monster_hp = 40;  // Punkty zdrowia potwora
    int akcja, damage, monster_damage, heal;


void rozwiaz_quiz() {
    int odpowiedz;
    printf("\nHandlarz: Jesli chcesz czerwona krede za darmo, musisz odpowiedziec na moje pytanie.\n");
    Sleep(czas_4);
    printf("Pytanie: Ile to 2+2*2?\n");
    Sleep(czas_4);
    printf("Jest to zadanie domowe mojego syna niestety nie jestem biegly z matematyki i nie umiem mu pomoc\n");
    Sleep(czas_4);
    printf("Wybierz odpowiedz:\n");
    printf("1. 6\n2. 8\n3. 10\nTwoja odpowiedz: ");
    scanf("%d", &odpowiedz);
	while (odpowiedz != 1) { // 1 to poprawna odpowiedŸ
        printf("\nHandlarz: Niestety to niepoprawna odpowiedz. Sprobuj jeszcze raz.\n");
        Sleep(czas_4);
        printf("Pytanie: Ile to 2+2*2?\n");
        Sleep(czas_4);
        printf("Wybierz odpowiedz:\n");
        printf("1. 6\n2. 8\n3. 10\nTwoja odpowiedz: ");
        scanf("%d", &odpowiedz);
    }
	  printf("\nHandlarz: Brawo! To poprawna odpowiedz. Oto Twoja kreda.\n");
}
void idz_do_handlarza() {
    printf("\nUdales sie do handlarza po krede.\n");
    rozwiaz_quiz(); // quiz
    printf("Wracasz do menu.\n");
}

void pokonaj_potwora() {
   
  //  generatora liczb losowych
    srand(time(NULL));
    Sleep(czas_2);
 printf("Masz 20 HP, a potwor ma 40 HP.\n");
while (player_hp > 0 && monster_hp > 0) {
        printf("\nTwoje HP: %d | HP potwora: %d\n", player_hp, monster_hp);
        printf("Co chcesz zrobic?\n");
        printf("1. Atakuj potwora (zadajesz losowe obrazenia).\n");
        printf("2. Wylecz sie (+(6-9) HP).\n");
        printf("Twoj wybor: \n");
        scanf("%d", &akcja);
        
if (akcja == 1) {
            // Gracz atakuje 
            damage = (rand() % 5) + 1; // Losowe obra¿enia 1-5
            monster_hp -= damage;
            printf("Zadajesz potworowi %d obrazen!\n", damage);
        } else if (akcja == 2) {
            // Gracz leczy siê
            heal = (rand() % 4) + 6; // Losowe leczenie 6-9
            player_hp += heal;
            if (player_hp > 20) player_hp = 20; // Maksymalne HP to 20
            printf("Leczysz sie o %d punktow. Twoje HP: %d.\n", heal, player_hp);
        } else {
            printf("Niepoprawny wybor! Tracisz swoja kolej.\n");
        }
if (monster_hp > 0) {
            // Potwor atakuje 
            monster_damage = (rand() % 5) + 3; // Losowe obra¿enia 3-7
            player_hp -= monster_damage;
            printf("Potwor atakuje i zadaje Ci %d obrazen!\n", monster_damage);
        }
if (player_hp <= 0) {
            printf("\nPotwor Cie pokonal i ucieka. Wiedzma patrzy na Ciebie z politowaniem i przywraca Ci ¿yciê\n");
            printf("\nJednak daje ci grzyba poniewaz uslyszala ze nie jestes z tego swiata\n");
            return ;
        }
if (monster_hp <= 0) {
            printf("\nBrawo! Pokonales potwora! Wracasz do wiedzmy z wiescia o zwyciestwie.\n");
            printf("Wiedzma: Dziekuje i wrecza Ci magicznego grzyba.\n");
            return;
        }
    }
}


void idz_do_wiedzmy() {
	Sleep(czas_2);
    printf("\nUdales sie do wiedzmy po pomoc.\n");
    Sleep(czas_2);
    printf("Wiedzma: Witaj podrozniku. Czego szukasz?\n");
    Sleep(czas_2);
    printf("%s: Wiedzmo, potrzebuje magicznego grzyba.\n", text);
    Sleep(czas_2);
    printf("%s: Uslyszalem od soltysa Lamberta, ze bedziesz moglo mi pomoc ze znalezieniem tego grzyba.\n", text);
    Sleep(czas_2);
    printf("Wiedzma: Moge Ci go dac, ale w zamian musisz pokonac potwora, ktory grasuje na mojej farmie grzybow.\n");
    Sleep(czas_2);
    printf("Wiedzma: Trzymaj miecz ktory pomoze ci go zabic jest on ze srebra wiec dziala na potwory efektywniej niz stalowy.\n");
    Sleep(czas_2);
     pokonaj_potwora();
}




int main()
{
	
	printf("Podaj swoja nazwe postaci:\n");
	scanf("%s",text);
	Sleep (czas_1);
	printf("Witaj w mojej grze %s znajdujesz sie w innym swiecie twoim zadaniem jest dotarcie do domu,by to zrobic musisz wykonac kilka questow i zabic pare potworow.\n",text);
	Sleep(czas_3);
	start:
	printf("Musisz wybrac ktora scieszka chesz isc, masz do wyboru (lewa lub prawa).\n");
	scanf("%s", droga);
	
if (stricmp(droga, "lewa") == 0)// PIERWSZY WYBÓR 	
	{
		Sleep(czas_1);
        printf("Po 30 minutach podrozy lesna sciezka docierasz do malej wioski.\n");
        Sleep(czas_2);
        printf("Masz pare pomyslow gdzie sie udac (mysliwy/soltys).\n");
        scanf("%s", dom);
        if(stricmp(dom, "soltys") == 0) // DRUGI WYBÓR
        {
        	printf("W chacie spotykasz soltysa.\n");
        	Sleep(czas_4);
        	printf("Postanawiasz zapytac soltysa, gdzie sie znajdujesz.\n");
        	Sleep(czas_4);
        	printf("Soltys: Witaj towarzyszu widze, ze nie jestes stad jak sie nazywasz.\n");
        	Sleep(czas_4);
        	printf("%s: Nazywam sie %s.\n",text,text);
        	Sleep(czas_4);
        	printf("Soltys: %s, jestem soltysem tej wioski i mam na imie Lambert.\n");
        	Sleep(czas_4);
        	printf("Lambert: Jak juz wczesniej wspomnialem nie jestes stad, wiec zapewne poszukujesz jakis informacji. \n");
        	Sleep(czas_4);
        	printf("%s: Obudzilem sie dzis tutaj nie wiem nawet gdzie jestem.\n", text);
        	Sleep(czas_4);
        	printf("Lambert: Znajdujesz sie w Wyzimie.\n");
        	Sleep(czas_4);
        	printf("%s: Musze wrocic do Gdanska.\n", text);
        	Sleep(czas_4);
        	printf("Lambert: Niestety musze cie zmartwic %s, bedziesz musial wrocic do domu portalem.\n",text);
        	Sleep(czas_4);
        	printf("Lambert: Bedziesz musial zdobyc skladniki, zeby otworzyc portal.\n");
        	Sleep(czas_4);
        	printf("%s: Jakie skladniki musze zdobyc, by udalo sie otworzyc portal.\n", text);
        	Sleep(czas_4);
        	printf("Lambert: Bedziesz potrzebowal 1.magicznego grzyba, 2.zloty pierscien, 3.czerwona kredke .\n");
        	Sleep(czas_4);
        	printf("Lambert: Kredke zdobedziesz napewno od handlarza, a zloty pierscien dostaniesz o demnie jezeli pomozesz jakiemus wiesniakowi naszej wioski.\n");
       		Sleep(czas_4);
        	printf("Lambert: Niestety o magicznym grzybie nic nie wiem, musisz pojsc do wiedzmy z naszej wioski moze ona ci pomoze.\n");
       		Sleep(czas_4);
       		printf("Masz dwie mozliwosci:\n");
       		
         while (1) {
        printf("\nMenu:\n");
        if (!handlarz_done)
            printf("1. Udac sie do handlarza po krede\n");
        if (!wiedzma_done)
            printf("2. Udac sie do wiedzmy po pomoc\n");
        printf("3. Zakoncz\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                if (!handlarz_done) {
                    idz_do_handlarza();
                    handlarz_done = 1;
                } else {
                    printf("Juz odwiedzi³es handlarza.\n");
                }
                break;
            case 2:
                if (!wiedzma_done) {
                    idz_do_wiedzmy();
                    wiedzma_done = 1;
                } else {
                    printf("Juz odwiedzi³es wiedzme.\n");
                }
                break;
            case 3:
                printf("Zakonczyles gre! Do widzenia.\n");
                return 0;
            default:
                printf("Niepoprawny wybór. Sprobuj ponownie.\n");
        }

        if (handlarz_done && wiedzma_done) {
            printf("Ukonczyles oba etapy.\n");
            Sleep(czas_3);
            break;
        }
    }
    
	printf("\nUdajesz sie do soltysa Lamberta.\n"); // KONIEC STAN 09.01.2025
	Sleep(czas_2);
	printf("%s: Lambercie zdobylem juz 2 skladniki, magicznego grzyba, czerwona krede.\n",text);
	Sleep(czas_4);
	printf("%s: Jak zdobywalem owe skladniki pomoglem rowniez twoim rowiesnikom z wioski.\n",text);
	Sleep(czas_4);
	printf("%s: Synowi handlarza rozwiazalem zadanie domowe, a u wiedzmy wypedzilem potwora ktory mial leze na jej farmie grzybow.\n ",text);
	Sleep(czas_4);
	printf("Lambert: Super ciesze sie ze pomogles moim ludziom a w szczegolnosci wiedzmie bedziemy miec teraz wiekszy dostep do lekow, kiedy uwarzy eliksiry\n");
	Sleep(czas_4);												
	printf("Lambert: Prosze w zamian dostajesz moj zloty pierscien\n");
	Sleep(czas_4);
	printf("Lambert: Teraz musisz udac sie do opuszczonego domu w naszej wiosce i odpalic portal\n");
	Sleep(czas_4);
	printf("Udajesz siê do opuszczonego domu\n");
	Sleep(czas_5);
	printf("Otwiersz drzwi do domu i widzisz portal szybko umieszczasz sk³adniki i wracasz do domu\n");
	Sleep(czas_2);
	printf("GRATULACJE WYGRALES GRE I POWROCILES DO DOMU MOZE ZDAZYSZ NAWET JUTRO NA WYKLAD ;D\n");
	getchar();
	
	}
			
				
		 else if (stricmp(dom,"mysliwy")==0){
        	printf("Postanawiasz udac sie do mysliwego.\n");
        	Sleep(czas_2);
        	printf("Kiedy otwierasz drzwi, aktywujesz pulapke.\n");
        	Sleep(czas_2);
        	printf("YOU KILLED BY TRAP\n");
        	Sleep(czas_2);
        	printf("Nastepnym razem dzwon dzwonkiem ;D\n");
        	Sleep(czas_1);
			printf("GAME OVER :C\n");
        	}
        else {
        	printf("Zostajesz na dworze, dostajesz hipotermii.\n");
        	Sleep(czas_1);
        	printf("YOU KILLED BY TEMPERATURE\n");
        	Sleep(czas_1);
        	printf("GAME OVER :C\n");
        }
	}
    else if (stricmp(droga, "prawa") == 0) {
    	printf("Idziesz lesna sciezka w prawo\n");
	    Sleep(czas_2);
    	Sleep(czas_2);
        printf("Zauwazasz wejscie do jaskini postanawiasz do niej wejsc\n");
        Sleep(czas_2);
        printf("Widzisz na stole 6 roznych kosci i notatke na ktorej jest napisane\n ABY OTWORZYC WEJSCIE MUSISZ WYRZUCIC NA WSZYSTKICH KOSCIACH LICZBY PARZYSTE\n");
        Sleep(czas_4);
        srand(time(NULL));
        int D2,D4,D6,D20,D100,D1000;
        int szukana_liczba;
        int temperatura;
        int rzuc_koscia(int scianka){
        	return rand() % scianka +1;
        }
        int czy_parzysta(int liczba){
        	return liczba % 2 ==0;
        }
        ponowny:
        printf("Aby rzucic koscmi kliknij ENTER\n");
        Sleep(czas_6);
        fflush(stdin);
        getchar();
        printf("%s: Rzuca koscmi\n", text);
        D2= rzuc_koscia(2);
        D4= rzuc_koscia(4);
        D6= rzuc_koscia(6);
        D20= rzuc_koscia(20);
        D100= rzuc_koscia(100);
        D1000= rzuc_koscia(1000);
        printf("Wyniki rzutow:\n");
        Sleep(czas_1);
        printf("D2:%d\n",D2);
        Sleep(czas_1);
        printf("D4:%d\n",D4);
        Sleep(czas_1);
        printf("D6:%d\n",D6);
        Sleep(czas_1);
        printf("D20:%d\n",D20);
        Sleep(czas_1);
        printf("D100:%d\n",D100);
        Sleep(czas_1);
        printf("D1000:%d\n",D1000);
        Sleep(czas_3);
      if(czy_parzysta(D2) && czy_parzysta(D4) && czy_parzysta(D6) && czy_parzysta(D20) && czy_parzysta(D100) && czy_parzysta(D100) ){
      	printf("Wszystkie kosci wyrzucily liczby parzyste! Przechodzisz do nastepnego pokoju.\n");
      	Sleep(czas_3);
      	printf("Zauwazasz, ze to pokoj alchemika\n");
      	Sleep(czas_2);
      	printf("Podchodzisz do stolika i  zauwazasz skladniki do magicznej mikstury i notatke na ktorej pisze: \nZeby uwarzyc miksture musisz ustawic odpowiednia temperature \n");
      	Sleep(czas_3);
      	printf("Zeby ustawic temperature musisz zgadnac cyfre ktora odpowiada stopniom Espektu jest ona z przedzialu (0-100000)\n");
      	Sleep(czas_3);
      	szukana_liczba= rand() % 100001;
      	do {
            printf("\nPodaj liczbe Espektu: \n");
            scanf("%d", &temperatura);
            
            if (temperatura < szukana_liczba) {
                printf("Szukana liczba jest wieksza\n");
            } else if (temperatura > szukana_liczba) {
                printf("Szukana liczba jest mniejsza\n");
            }
        } while (temperatura != szukana_liczba);
        printf("Brawo, Zgadles stopnie Espektu! Mikstura sie gotuje.\n");
        Sleep(czas_2);
        printf("Wypijasz miksture i budzisz sie na tym samym rozdrozu co wczesniej ale nic nie pamietasz\n");
        Sleep(czas_3);
        printf("Okazuje sie, ze byl to Eliksir Wedrowki w czasie\n\n\n");
        Sleep(czas_4);

	 
	  //KONIEC NAWIASU IF KOSCI
	  }
	  else {
        	system("cls");
        	printf("Nie wszystkie kosci wyrzucily liczby parzyste. Sprobuj ponownie.\n");
        	Sleep(czas_1);
        	goto ponowny; //KONIEC ELSE KOSCI PARZYSTOSC
	  }
	  goto start;
	  
 																			}
    //////// KONIEC ELSE IF PRAWO
	else {
        printf("Postanawiasz odpoczac, w nocy napadl cie wilkolak.\n");
        Sleep(czas_2);
        printf("YOU KILLED BY WILKOLAK\n");
        Sleep(czas_1);
		printf("GAME OVER :C\n");
	}
	
	return 0;
}
	


