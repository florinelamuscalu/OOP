#include <iostream>
#include <fstream>
#include "student.h"
#include "grupa.h"
#include "licenta.h"
#include "strategy.h"



/* Mi-am ales ca tema clasa student, unde o sa am numele studentului si grupa un nr intreg. Voi citi datele, si voi afisa
 * studentii in ordinea grupelor, in ordine alfabetica si in ordinea grupelor + alfabetic. Voi incerca sa aloc. Sper sa
 * si imi iasa ceva :))) P.S daca consideri ca as putea sa fac mai mult la ea mai adauga tu unele cerinte
 */

// Noi cerinte :
// Se adauga varsta sa ord cresc si dupa desc
// Imparte studentii licenta master doctorat
// Imaprte in frecventa sau distanta
// Vector cu grupe, ordonare dupa an


/// tema 2
/* in clasa licenta voi retine toti studenti la licenta si
 * ii  voi organiza dupa numele licentei, ex CTI, mate, info
 * dar si dupa taxa buget burse*/



/// tema 3
/*pentru designe pattern o sa folosec factory */


int main() {
    std::ifstream in("citire.txt");// working dir sau ../
    licenta li;
    in >> li;
    std::cout << li;
    li.ordonare_nume();
    li.ordonare_varsta();
    li.ordonare_an();

    // factory
    grupa g_m, g_c, g_i;
    g_m = strategy::mate();
    g_c = strategy::cti();
    g_i = strategy::info();
    std::cout << g_m << " " << g_c << " " << g_i << '\n';

    // factory
    int buget, bursa, taxa;
    bursa_s s;
    bursa = s.aplicare();
    buget_s s1;
    buget = s1.aplicare();
    taxa_s s2;
    taxa = s2.aplicare();
    std::cout << bursa << '\n';
    std::cout << buget << '\n';
    std::cout << taxa << '\n';

    return 0;
}

