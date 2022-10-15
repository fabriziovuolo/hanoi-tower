#define n 3
typedef int* righe;
#include <stdio.h>
#include <stdlib.h>
int scelta(righe [], int, int);
int valore(righe [], int, int);
void stampa(righe [], int, int);
void controllo(righe [], int, int,int);
void riempi_mat(righe [], int, int);
void resoconto(int);
int main() {
    int i,j,app;
    righe b[n];
    do {
        printf("inserisci livello maggiore o uguale a 3: ");
        scanf("%d", &app);
    } while (app<3);
    riempi_mat(b, n, app);
    stampa(b, app, n);
    printf("\npremi 0 per interrompere la partita\n");
    do {
        i=scelta(b, app, n);
        if (i==0) {
            b[2][0]=1;
        }else{
            j=valore(b, i, app);
            controllo(b, j, app, n);
            stampa(b, app, n);
        }
    } while (b[2][0]==0);
    resoconto(i);
    return 0;
}
void resoconto(int a){
    if (a==0) {
        printf("\nHAI PERSO, RIPROVA CON UNA DIFFICOLTA' PIU' BASSA\n");
    }else{
        printf("\nHAI VINTO\n");
    }
}
void riempi_mat(righe a[], int rig, int col){
    int i,j, k=1;
    for (i=0; i<rig; i++) {
        a[i]=malloc(sizeof(int)*col);
        if (i==0) {
            for (j=0; j<col; j++) {
                a[i][j]=k;
                k+=2;
            }
        }
        else{
            for (j=0; j<col; j++) {
                a[i][j]=0;
            }
        }
    }
}
void controllo(righe a[],int k, int col, int rig){
    int i, app=0, app1;
    do {
        printf("inserisci colonna in cui mettere l'oggetto: ");
        scanf("%d", &app1);
        for (i=col-1; i>=0&&!app; i--) {
            if (a[app1-1][i]==0&&i==col-1) {
                a[app1-1][i]=k;
                app++;
            }
            else{
                if ((k<a[app1-1][i+1])&&a[app1-1][i]==0) {
                    a[app1-1][i]=k;
                    app++;
                }
            }
        }
    } while (!app);
}
void stampa(righe a[], int col, int maxi){
    int i,j,app,k,max;
    max=col*2-1;
    for (i=0; i<col; i++) {
        for (j=0; j<n; j++) {
            printf(" ");
            if (a[j][i]==0) {
                for (k=0; k<max; k++) {
                    printf(" ");
                }
            }
            else{
                app=(max-a[j][i])/2;
                for (k=0; k<app; k++) {
                    printf(" ");
                }
                for (k=0; k<a[j][i]; k++) {
                    printf("*");
                }
                for (k=0; k<app; k++) {
                    printf(" ");
                }
            }
            printf(" |");
        }
        printf("xxxxx\n");
    }
}
int valore(righe a[], int sce, int col){
    int i,j=0;
    for (i=0; i<col&&!j; i++) {
        if (a[sce-1][i]!=0) {
            j=a[sce-1][i];
            a[sce-1][i]=0;
        }
    }
    return j;
}
int scelta(righe a[], int col, int righe){
    int i,j=0, sce;
    do {
        do {
            printf("inserisci scelta: ");
            scanf("%d", &sce);
        } while (sce<0&&sce>3);
        if (sce==0) {
            j++;
        }else{
            for (i=0; i<col&&!j; i++) {
                if (a[sce-1][i]!=0) {
                    j=1;
                }
            }
        }
    } while (!j);
    return sce;
}
