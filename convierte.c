#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fpa_in = fopen("a.txt", "r");
    FILE *fpb_in = fopen("b.txt", "r");
    FILE *fp_out = fopen("entrada.bin", "wb");
    int n, i;

    if (fpa_in == NULL || fpb_in == NULL || fp_out == NULL) {
        perror("Error al abrir uno de los archivos");
        if (fpa_in) fclose(fpa_in);
        if (fpb_in) fclose(fpb_in);
        if (fp_out) fclose(fp_out);
        return 1; // Salida con error
    }

    // Escribir los primeros 9 desde a.txt
    for (i = 0; i < 9 && fscanf(fpa_in, "%d", &n) != EOF; i++) {
        fwrite(&n, sizeof(int), 1, fp_out);
    }

    // Escribir los siguientes 9 desde b.txt
    for (i = 0; i < 9 && fscanf(fpb_in, "%d", &n) != EOF; i++) {
        fwrite(&n, sizeof(int), 1, fp_out);
    }

    printf("Archivo entrada.bin generado con éxito.\n");

    fclose(fpa_in);
    fclose(fpb_in);
    fclose(fp_out);

    return 0;
}