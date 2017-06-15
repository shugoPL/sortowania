#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAB_BASE 10000
#define TAB_BUFF_LEN 90000

void wylosuj( int *tab, int tabLen);
void tabCopy(int *tableDestination, int *tableSource, int tabLen);
void tabCopyTest(int *tableDestination1,int *tableDestination2, int *tableDestination3, int *tableDestination4, int *tableSource, int tabLen);
double bubbleSort( int *tab, int tabLen);
double bubbleSortFlag( int *tab, int tabLen);
double selectionSort(int *tab, int tabLen );
double insertionSort2(int *tab, int tabLen );
void feelTab(int *tab, int tabLen, char mode);

int main(){
    srand( time( NULL ) );
    double timeTmpB, timeTmpS;
    double timeTmpI, timeTmpBF;
    int *tablicaBufor;
    FILE *f = fopen("result.csv", "w");
    tablicaBufor = (int*)malloc(sizeof(int) * TAB_BUFF_LEN);
    wylosuj(tablicaBufor, TAB_BUFF_LEN);
    printf("%%%%%%%%%%%%%%%%%%%%%% Sortowanie tablic losowych %%%%%%%%%%%%%%%%%%%%%%\n");
    printf("ilosc  : bąbelkowe\t wybór\t\t wstawianie\t  *\n");
    fprintf(f,"ilosc;bąbelkowe;wybór;wstawianie;wstawianiePopra\n");
    int i;
    for( i = 1; i <= 9; i++){
        int *tablica10 = (int*)malloc(sizeof(int) * (i * TAB_BASE));
        int *tablica10s = (int*) malloc(sizeof(int) * (i * TAB_BASE));
        int *tablica10i = (int*) malloc(sizeof(int) * (i * TAB_BASE));
        int *tablica10bf = (int*)malloc(sizeof(int) * (i * TAB_BASE));
        
        tabCopy(tablica10, tablicaBufor, (i * TAB_BASE));
        tabCopy(tablica10s, tablicaBufor, (i * TAB_BASE));
        tabCopy(tablica10i, tablicaBufor, (i * TAB_BASE));
        tabCopy(tablica10bf, tablicaBufor, (i * TAB_BASE));
        
        timeTmpB = bubbleSort(tablica10, (i * TAB_BASE));   //tablice losowe
        timeTmpS = selectionSort(tablica10s, (i * TAB_BASE)); 
        timeTmpI = insertionSort2(tablica10i, (i * TAB_BASE));
        timeTmpBF = bubbleSortFlag(tablica10bf, (i * TAB_BASE));
        
        printf("%d.000 : %f\t %f \t %f\t %f\t  * \n", (i * 10), timeTmpB, timeTmpS, timeTmpI, timeTmpBF);
        fprintf(f, "%d.000;%f;%f;%f;%f\n", (i * 10), timeTmpB, timeTmpS, timeTmpI, timeTmpBF);
        free(tablica10);
        free(tablica10s);
        free(tablica10i);
        free(tablica10bf);
    }
    free(tablicaBufor);
    tablicaBufor = (int*)malloc(sizeof(int) * TAB_BUFF_LEN);
    feelTab(tablicaBufor, TAB_BUFF_LEN, 'i');
    
    printf("%%%%%%%%%%%%%%%%%%%%%% Sortowanie tablic optymistycznych %%%%%%%%%%%%%%%%%%%%%%\n");
    printf("ilosc  : bąbelkowe\t wybór\t\t wstawianie\t  *\n");
    fprintf(f,"ilosc;bąbelkowe;wybór;wstawianie;wstawianiePopra\n");
    for( i = 1; i <= 9; i++){
        int *tablica10 = (int*)malloc(sizeof(int) * (i * TAB_BASE));
        int *tablica10s = (int*) malloc(sizeof(int) * (i * TAB_BASE));
        int *tablica10i = (int*) malloc(sizeof(int) * (i * TAB_BASE));
        int *tablica10bf = (int*)malloc(sizeof(int) * (i * TAB_BASE));
        
//        tabCopy(tablica10, tablicaBufor, (i * TAB_BASE));
//        tabCopy(tablica10s, tablicaBufor, (i * TAB_BASE));
//        tabCopy(tablica10i, tablicaBufor, (i * TAB_BASE));
//        tabCopy(tablica10bf, tablicaBufor, (i * TAB_BASE));
        
        tabCopyTest(tablica10, tablica10s, tablica10i, tablica10bf, tablicaBufor, (i * TAB_BASE));

        timeTmpB = bubbleSort(tablica10, (i * TAB_BASE));   //tablice losowe
        timeTmpS = selectionSort(tablica10s, (i * TAB_BASE)); 
        timeTmpI = insertionSort2(tablica10i, (i * TAB_BASE));
        timeTmpBF = bubbleSortFlag(tablica10bf, (i * TAB_BASE));
        
        printf("%d.000 : %f\t %f \t %f\t %f\t  * \n", (i * 10), timeTmpB, timeTmpS, timeTmpI, timeTmpBF);
        fprintf(f, "%d.000,%f,%f,%f,%f\n", (i * 10), timeTmpB, timeTmpS, timeTmpI, timeTmpBF);
        free(tablica10);
        free(tablica10s);
        free(tablica10i);
        free(tablica10bf);
    }
    free(tablicaBufor);
    tablicaBufor = (int*)malloc(sizeof(int) * TAB_BUFF_LEN);
    feelTab(tablicaBufor, TAB_BUFF_LEN, 'd');
    
    printf("%%%%%%%%%%%%%%%%%%%%%% Sortowanie tablic pesymistycznych %%%%%%%%%%%%%%%%%%%%%%\n");
    printf("ilosc  : bąbelkowe\t wybór\t\t wstawianie\t  *\n");
    fprintf(f,"ilosc;bąbelkowe;wybór;wstawianie;wstawianiePopra\n");
    for( i = 1; i <= 9; i++){
        int *tablica10 = (int*)malloc(sizeof(int) * (i * TAB_BASE));
        int *tablica10s = (int*) malloc(sizeof(int) * (i * TAB_BASE));
        int *tablica10i = (int*) malloc(sizeof(int) * (i * TAB_BASE));
        int *tablica10bf = (int*)malloc(sizeof(int) * (i * TAB_BASE));
        
        tabCopy(tablica10, tablicaBufor, (i * TAB_BASE));
        tabCopy(tablica10s, tablicaBufor, (i * TAB_BASE));
        tabCopy(tablica10i, tablicaBufor, (i * TAB_BASE));
        tabCopy(tablica10bf, tablicaBufor, (i * TAB_BASE));
        
        timeTmpB = bubbleSort(tablica10, (i * TAB_BASE));   //tablice losowe
        timeTmpS = selectionSort(tablica10s, (i * TAB_BASE)); 
        timeTmpI = insertionSort2(tablica10i, (i * TAB_BASE));
        timeTmpBF = bubbleSortFlag(tablica10bf, (i * TAB_BASE));
        
        printf("%d.000 : %f\t %f \t %f\t %f\t  * \n", (i * 10), timeTmpB, timeTmpS, timeTmpI, timeTmpBF);
        fprintf(f, "%d.000,%f,%f,%f,%f\n", (i * 10), timeTmpB, timeTmpS, timeTmpI, timeTmpBF);
        free(tablica10);
        free(tablica10s);
        free(tablica10i);
        free(tablica10bf);
    }

    free(tablicaBufor);
    fclose(f);
    return 0;
}

double bubbleSort( int *tab, int tabLen){
    clock_t start, stop;
    int i, j, tmp;
    start = clock();
    for(i = 0; i < tabLen; i++){
        for( j = 1; j < tabLen; j++ ){
            if(tab[j] < tab[j - 1]){
                tmp = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = tmp;
            }
        }
    }
    stop = clock();
    return (double)(stop - start)/ CLOCKS_PER_SEC;
}
double bubbleSortFlag( int *tab, int tabLen){
    clock_t start, stop;
    char flag = 0;
    int i, j, tmp;
    start = clock();
    for(i = 0; i < tabLen; i++){
        flag = 0;
        for( j = 1; j < tabLen; j++ ){
            if(tab[j] < tab[j - 1]){
                tmp = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = tmp;
                flag = 1;
            }
        }
        if( flag == 0 )
            break;
    }
    stop = clock();
    return (double)(stop - start)/ CLOCKS_PER_SEC;
}

double selectionSort(int *tab, int tabLen ){
    clock_t start, stop;
    int i, j, min, tmp;
    start = clock();
    for( i = 0; i < tabLen; i++ ){
        min = i;
        for( j = i + 1; j < tabLen; j++ ){
            if( tab[j] < tab[min] )
                min = j;
        }
        tmp = tab[min];
        tab[min] = tab[i];
        tab[i] = tmp;
    }
    stop = clock();
    return (double) (stop - start)/CLOCKS_PER_SEC;
}

double insertionSort2(int *tab, int tabLen ){
    clock_t start, stop;
    int i,j,tmp;
    start = clock();
    for( i = 0; i < tabLen; i++ ){
        tmp = tab[i];
        for( j = i; j > 0 && tab[j - 1] > tmp; j--){
            tab[j] = tab[j - 1];
            tab[ j -1] = tmp;
        }
    }
    stop = clock();
    return (double)(stop - start)/CLOCKS_PER_SEC;
}

void wylosuj( int *tab, int tabLen){
    int i;
    for( i = 0; i < tabLen; i++){
        tab[i] = rand();
    }
}
void tabCopy(int *tableDestination, int *tableSource, int tabLen){
    int i;
    for( i = 0; i < tabLen; i++)
        tableDestination[i] = tableSource[i];
}

void tabCopyTest(int *tableDestination1, int *tableDestination2, int *tableDestination3, int *tableDestination4, int *tableSource, int tabLen){
    int i;
    for( i = 0; i < tabLen; i++)
        tableDestination1[i] = tableDestination2[i] = tableDestination3[i] = tableDestination4[i] = tableSource[i];
}


void feelTab(int *tab, int tabLen, char mode){
    int i;
    switch(mode){
        case 'i':
            for( i = 0; i < tabLen; i++)
            tab[i] = i+1;
            break;
        case 'd':
        default:
            for( i = 0; i < tabLen; i++)
                tab[i] = tabLen - i ;
    }
}









//void b(int *tab, int tabLen){    
//    int i, j, min, tmp;
//    for( i = 0; i < tabLen; i++ ){
//        min = i;
//        for( j = i + 1; j < tabLen; j++ ){
//            if( tab[j] < tab[min] )
//                min = j;
//        }
//        tmp = tab[min];
//        tab[min] = tab[i];
//        tab[i] = tmp;
//    }
//}
//void wypisz(int *tab, int l){
//    int i;
//    for(i = 0; i < l; i++)
//        printf("%d", tab[i]);
//}