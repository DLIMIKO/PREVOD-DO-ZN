#include <stdio.h>
#include <assert.h>
#include <limits.h>

/**
 * @def skonvertuj_na_znak
 * @brief makro, ktoré nám prevádza desiatkové číslo na znak
 */
#define skonvertuj_na_znak(x) ( (x) > 9 ? (char)((x) - 10 + 'A') : (char)((x) + '0') )

/**
 * Funkcia prevádza číslo z desiatkovej sústavy do sústavy Zn, kde n je  < 2; 26 >
 * @param cislo_d  číslo v desiatkovej sústave
 * @param zaklad  základ sústavy
 * @param cislo_zn skonvertované číslo v sútave Zn
 * @return dĺžka výsledného reťazca (poprípade prvý voľný index v reťazci)
 */
int skonvertuj_do_Zn(unsigned cislo_d, unsigned zaklad, char *cislo_zn);


/**
 * @def MAX_RETAZEC
 * @brief maximálna dĺžka výstupného reťazca
 */
#define MAX_RETAZEC 200

int main()
{
  unsigned N;
  unsigned z;
  char vysledok[MAX_RETAZEC];


  /*  načítame číslo v desiatkovej sústave a základ sústavy */

  printf("\nZadajte číslo v desiatkovej sústave (0 - %u) a základ sústavy (Z2 - Z26):\n", UINT_MAX);
  scanf("%u %u", &N, &z);

  /* skontrolujeme, či dokážeme previesť číslo do danej sústavy */

  assert(z > 1 && z <= 26);


  /* skonvertujeme číslo a umiestnime ukončovací znak na koniec reťazca */

  vysledok[skonvertuj_do_Zn(N, z, vysledok)] = '\0';

  /* vypíšeme výsledok */

  printf("%u => %s (Z%u)", N, vysledok, z);

  return 0;
}


int skonvertuj_do_Zn(unsigned cislo_d, unsigned zaklad, char *cislo_zn)
{
    if (cislo_d == 0)
    {
        return 0;
    }
    else
    {
        //  rekurzívne del cislo_d základom sústavy a vráť prvý voľný index v reťazci
        int i = skonvertuj_do_Zn(cislo_d / zaklad, zaklad, cislo_zn);

        // zapíš na voľný index (ako alfanumerický znak) zvyšok po delení čísel cislo_d a zaklad)
        cislo_zn[i] = skonvertuj_na_znak(cislo_d % zaklad);

        // zväčši hodnotu prvého voľného indexu v reťazci
        return ++i;
    }
}