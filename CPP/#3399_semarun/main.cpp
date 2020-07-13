#include <stdio.h>
#include <vector>

using namespace std;

struct race_data
{
    int length;
    int speed;
    int max_time;
    void read() {
        scanf("%d%d%d", &length, &speed, &max_time);
    }
};

struct trafic_lights_data
{
    int time;
    int red;
    int green;
    void read(int speed) {
        int distance;
        scanf("%d%d%d", &distance, &red, &green);
        time = distance/speed;
    }
};

const int SEMAFOARE_MAX = 70000 +5;

race_data traseu;
int numar_semafoare;
trafic_lights_data semafoare[SEMAFOARE_MAX];

int main() {
    traseu.read();
    scanf("%d", &numar_semafoare);
    for (int i = 0; i < numar_semafoare; ++i)
        semafoare[i].read(traseu.speed);

    int max_timp_pornire = traseu.max_time - traseu.length/traseu.speed;
    vector<int> solutii;
    for (int pornire = 0; pornire <= max_timp_pornire; ++pornire) {

        bool ok = true;
        int timp_curent{pornire};
        for (int sem = 0; sem < numar_semafoare; ++sem) {

            timp_curent += semafoare[sem].time;
            int ciclu_semafor = semafoare[sem].red + semafoare[sem].green;
            if (!(timp_curent%ciclu_semafor == 0 ||
                timp_curent%ciclu_semafor > semafoare[sem].red)) {
                    ok = false;
                    break;
            }   
        }

        if (ok) solutii.push_back(pornire);

    }
    printf("%d\n", solutii.size());
    for (vector<int>::iterator it = solutii.begin(); it != solutii.end(); ++it)
        printf("%d ", *it);

    return 0;
}