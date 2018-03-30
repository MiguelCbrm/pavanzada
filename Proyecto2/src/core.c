#include <stdio.h>
int tests;
int cores;
int minCores;
float points;
float probCores[50];
float oneToOne();
float oneToMany();

int main(){

    scanf("%d\n", &tests);

    for(int i = 0; i < tests; i++){
        scanf("%d %d\n", &cores, &minCores);
        scanf("%f\n", &points);

        for(int j = 0; j < cores; j++){
            scanf("%f\n", &probCores[j]);
        }

        if(cores == minCores){
            printf("Final Porbability: %f\n", oneToOne());
        }
        else{
            printf("Final Porbability: %f\n", oneToMany());
        }
    }
    return 0;
}

float oneToOne(){
    float temp = 0;
    float each = 0;
    float tempPoints = points;
    float finalProb= 0;
    float value;
    int index;

    while(tempPoints > .0001){
        index = 0;
        value = probCores[0];
        for(int i = 0; i < cores; i++){
            if(probCores[i] <= value && probCores[i] < 1){
                index = i;
                value = probCores[i];
            }
        }
        tempPoints -= .1;
        probCores[index] += .1;
    }

    float total = 1;

    for(int i = 0; i < cores; i++){
        total *= (probCores[i]);
    }

    return total;
}

float oneToMany(){
    float temp = 0;
    float each = 0;
    float tempPoints = points;
    float finalProb= 0;
    float value;
    int index;

    while(tempPoints > .0001){
        index = 0;
        value = probCores[0];
        for(int i = 0; i < cores; i++){
            if(probCores[i] > value && probCores[i] < 1){
                index = i;
                value = probCores[i];
            }
        }
        tempPoints -= .1;
        probCores[index] += .1;
    }

    float total = 1;

    for(int i = 0; i < cores; i++){
        total *= (1 - probCores[i]);
    }

    total = 1 - total;

    return total;
}