/*                                                                   ********** CONSEGNA **********
                UTILIZZANDO IL LINGUAGGIO C REALIZZARE UN PROGRAMMA CHE DATA IN INPUT UNA MATRICE 3X3, NE RESTITUISCA L'INVERSA IN OUTPUT CON ANNESSA VERIFICA TRAMITE MATRICE IDENTICA

                Autore: Elian Alderuccio
*/

#include <stdio.h>
#include<math.h>
#include<windows.h>

void Inserimento(float M[3][3], int i, int j);
void Calcolo(float M[3][3], float MA[3][3], float MID[3][3], int i, int j);
void Stampa(float M[3][3], float MA[3][3], float MID[3][3], int i, int j);

int main(void) {
    //DICHIARAZIONE VARIABILI
    float M[3][3], MA[3][3], MID[3][3];
    int i = 0, j = 0;

	//RICHIAMO FUNZIONI DEL PROGRAMMA
    Inserimento(M,i,j);
    Calcolo(M,MA,MID,i,j);
    getch();
}


void Inserimento(float M[3][3], int i, int j){
	//INSERIMENTO DELLA MATRICE DA PARTE DELL'UTENTE
	printf("Inserire i valori della matrice\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("\nInserisci elemento di riga %d e colonna %d: ", i, j);
            scanf("%f", &M[i][j]);
        }
    }                
}


void Calcolo(float M[3][3], float MA[3][3], float MID[3][3], int i, int j){
	//DICHIARAZIONE VARIABILI
	int k = 0;
	float determinante, A00, A01, A02, A10, A11, A12, A20, A21, A22;
	
    determinante = (M[0][0] * M[1][1] * M[2][2]) + (M[0][1] * M[1][2] * M[2][0]) + (M[0][2] * M[1][0] * M[2][1]) - (M[0][1] * M[1][0] * M[2][2]) - (M[0][0] * M[1][2] * M[2][1]) - (M[0][2] * M[1][1] * M[2][0]);

    //CONDIZIONE NECESSARIA PER TROVARE LA MATRICE INVERSA
    if (determinante == 0){
        printf("\n\nIl determinante e'uguale a zero quindi la matrice inversa non e' calcolabile\n");
        printf("Grazie e arrivederci!");
        return;
	}else {
        //CALCOLO COMPLEMENTI ALGEBRICI DELLA MATRICE
        A00 = ((pow(-1,0)) * ((M[1][1] * M[2][2]) - (M[1][2] * M[2][1])));
        A01 = ((pow(-1,1)) * ((M[1][0] * M[2][2]) - (M[1][2] * M[2][0])));
        A02 = ((pow(-1,2)) * ((M[1][0] * M[2][1]) - (M[1][1] * M[2][0])));
        A10 = ((pow(-1,1)) * ((M[0][1] * M[2][2]) - (M[0][2] * M[2][1])));
        A11 = ((pow(-1,2)) * ((M[0][0] * M[2][2]) - (M[0][2] * M[2][0])));
        A12 = ((pow(-1,3)) * ((M[0][0] * M[2][1]) - (M[0][1] * M[2][0])));
        A20 = ((pow(-1,2)) * ((M[0][1] * M[1][2]) - (M[0][2] * M[1][1])));
        A21 = ((pow(-1,3)) * ((M[0][0] * M[1][2]) - (M[0][2] * M[1][0])));
        A22 = ((pow(-1,4)) * ((M[0][0] * M[1][1]) - (M[0][1] * M[1][0])));

        //COSTRUZIONE DELLA MATRICE INVERSA DIVIDENDO OGNI COMPLEMENTO ALGEBRICO PER IL DETERMINANTE DELLA MATRICE DI PARTENZA
        MA[0][0] = (A00 / determinante);
        MA[0][1] = (A10 / determinante);
        MA[0][2] = (A20 / determinante);
        MA[1][0] = (A01 / determinante);
        MA[1][1] = (A11 / determinante);
        MA[1][2] = (A21 / determinante);
        MA[2][0] = (A02 / determinante);
        MA[2][1] = (A12 / determinante);
        MA[2][2] = (A22 / determinante);

        //PRODOTTO TRA MATRICI PER COSTRUIRE LA MATRICE IDENTICA CHE AVRA' FUNZIONE DI VERIFICA
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                MID[i][j] = 0;
                for (k = 0; k < 3; k++) {
                    MID[i][j] = MID[i][j] + M[i][k] * MA[k][j];
                }
            }
        }
        //RICHIAMO ALLA FUNZIONE CHE STAMPA LE MATRICI
        Stampa(M,MA,MID,i,j);   
    }
}

void Stampa(float M[3][3], float MA[3][3], float MID[3][3], int i, int j){
	//COMANDO CHE PULISCE LO SCHERMO
    system("cls");
    printf("Resoconto matrici:\n\n");

	//STAMPA MATRICE INSERITA IN INPUT
    printf("\n\nLa matrice inserita e':\n");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            printf("%5f     ", M[i][j]);
        }
	}
    printf("\n\n\n\n");
    
    
    //STAMPA MATRICE INVERSA
    printf("\n\nLa matrice inversa e':\n");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            printf("%5f     ", MA[i][j]);
        }
    }
    printf("\n\n\n\n");
    
    
    //STAMPA MATRICE IDENTICA
    printf("\n\nLa matrice identica e':\n");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            printf("%5f     ", MID[i][j]);
        }
	}
    printf("\n\n\n\n");
}

