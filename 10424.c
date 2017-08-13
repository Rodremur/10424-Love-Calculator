/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 10424 - Love Calculator
 * Fecha: 15-02-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char name[25];
	int size, i, sum, aux, digit1, digit2, namecounter;
	float ratio;
	namecounter = 0;

	while (fgets(name, 26, stdin)) {
		namecounter += 1;
		size = strlen(name);
		sum = 0;
		aux = 0;
		/*Obtencion de nombre*/
		for (i = 0; i < size; i++) {
			if (name[i] >= 'a' && name[i] <= 'z') {
				/*Caracter en int utiliza valor decimal de ASCII entonces se le resta para ajustar*/
				sum += name[i]-96;
			}
			if (name[i] >= 'A' && name[i] <= 'Z') {
				/*Caracter en int utiliza valor decimal de ASCII entonces se le resta para ajustar*/
				sum += name[i]-64;
			}
		}
		while (sum != 0) {
			aux += sum % 10;
			sum = sum/10;
		}
		/*Se checa que el digito no sobrepase 9 para evitar pasar el 100% de ratio*/
		if (aux > 9) {
			sum = aux;
			aux = 0;
			while (sum != 0) {
				aux += sum % 10;
				sum = sum/10;
			}
		}
		/*Se checa si se esta en el primer o segundo nombre del par, si se esta en el segundo, se hace la operacion*/
		if (namecounter % 2 == 0) {
			digit2 = aux;
			if (digit1 > digit2) {
				ratio = (float)digit2*100/(float)digit1;
			}
			if (digit2 > digit1) {
				ratio = (float)digit1*100/(float)digit2;
			}
			if (digit1 == digit2) {
                ratio = 100;
			}
			printf("%.2f %%\n", ratio);
		} else {
			digit1 = aux;
		}
	}
    return 0;
}
