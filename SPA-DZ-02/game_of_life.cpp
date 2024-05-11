#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
    return rand() % 2;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
    if (i < 0 || i >= REDAKA || j < 0 || j >= STUPACA) {
        return false;
    }

    return _generacija[i][j];
}

game_of_life::game_of_life()
{
    srand(time(nullptr));

    for (int redak = 0; redak < REDAKA; redak++) {
        for (int stupac = 0; stupac < STUPACA; stupac++) {
            _generacija[redak][stupac] = slucajna_vrijednost();
        }
    }
}

void game_of_life::sljedeca_generacija()
{
    for (int redak = 0; redak < REDAKA; redak++) {
        for (int stupac = 0; stupac < STUPACA; stupac++) {
            int susjeda = 0;

            susjeda += celija_zauzeta(redak - 1, stupac - 1);
            susjeda += celija_zauzeta(redak - 1, stupac);
            susjeda += celija_zauzeta(redak - 1, stupac + 1);
            susjeda += celija_zauzeta(redak, stupac - 1);
            susjeda += celija_zauzeta(redak, stupac + 1);
            susjeda += celija_zauzeta(redak + 1, stupac - 1);
            susjeda += celija_zauzeta(redak + 1, stupac);
            susjeda += celija_zauzeta(redak + 1, stupac + 1);

            bool celija = _generacija[redak][stupac];

            if ((celija && (susjeda == 2 || susjeda == 3)) || (!celija && susjeda == 3)) {
                _sljedeca_generacija[redak][stupac] = true;
            }
            else {
                _sljedeca_generacija[redak][stupac] = false;
            }
        }
    }

    for (int redak = 0; redak < REDAKA; redak++) {
        for (int stupac = 0; stupac < STUPACA; stupac++) {
            _generacija[redak][stupac] = _sljedeca_generacija[redak][stupac];
        }
    }
}

void game_of_life::iscrtaj()
{
    for (int redak = 0; redak < REDAKA; redak++) {
        for (int stupac = 0; stupac < STUPACA; stupac++) {
            cout << (_generacija[redak][stupac] ? '*' : '-');
        }

        cout << endl;
    }
}
