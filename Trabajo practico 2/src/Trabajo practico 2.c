/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Santiago_Volunt�
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define QTY_EMPLOYEES 1000

int main(void) {
	setbuf(stdout, NULL);

	int option;
	Employee list[QTY_EMPLOYEES];
	int flag = 0;
	int r;
	int order;
	float acumulator = 0;
	float average = 0;
	int rich=0;
	int report;
	int ID=0;
	initEmployees(list, QTY_EMPLOYEES);

	do {

		if (utn_getNumero(&option,
				"\n1-ALTAS \n2-MODIFICAR\n3- BAJA\n4-INFORMAR",
				"Error ingrese un numero valido", 1, 4, 3) == 0) {
			switch (option) {
			case 1:
				flag = 1;
				getEmployee(list, QTY_EMPLOYEES,&ID);
				system("PAUSE");
				break;

			case 2:
				if (flag == 1) {

					system("PAUSE");
					system("CLS");
					printEmployees(list, QTY_EMPLOYEES);
					printf("Ingrese el id del empleado que desea modificar: ");
					scanf("%d", &ID);
					system("CLS");
					modifyEmployee(list, QTY_EMPLOYEES, ID);
				}

				else {
					printf("Error, antes debe ingresar un empleado");
				}
				break;

			case 3:
				if (flag == 1) {
					system("PAUSE");
					system("CLS");
					r = printEmployees(list, QTY_EMPLOYEES);
					if (r != -1) {
						printf("\nIngrese el id que desea dar de baja: ");
						scanf("%d", &ID);
						r = removeEmployee(list, QTY_EMPLOYEES, ID);
						if (r != -1) {
							system("CLS");
							printf("Baja exitosa\n");
						} else {
							system("CLS");
							printf("No se dio de baja\n");
						}
					}
				}

				else {
					printf("Error, antes debe ingresar un empleado");
				}
				break;
			case 4:
				if (flag == 1) {
					system("CLS");
					utn_getNumero(&report,
							"\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector. \n2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio. ",
							"ERROR, ingrese un numero valido", 1, 2, 2);
					switch (report) {
					case 1:
						printf(
								"\n-Si desea infomar de manera cresciente ingrese '1' \n-Si desea infomar de manera decresciente ingrese '0'");
						scanf("%d", &order);
						system("CLS");
						r = sortEmployees(list, QTY_EMPLOYEES, order);
						r = printEmployees(list, QTY_EMPLOYEES);
						break;
					case 2:
						rich = AverageSalary(list, QTY_EMPLOYEES, &average,
								&acumulator);
						printf(
								"\nSueldos totales: %.2f\nPromedio de sueldos: %.2f\n-Personas que ganan mas que el promedio: %d",
								acumulator, average, rich);
						break;
					}
				} else {
					printf("Error antes debe ingresar un empleado");
				}
				break;

			}
		}

	} while (option != 27);

	return 0;
}
