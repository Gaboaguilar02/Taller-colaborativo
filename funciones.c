#include <stdio.h>
#include <string.h>
#include "funciones.h"
void editarFila(int* n, int M, char productos[*n][M][50], int filaAEditar, char nuevoValor[]) {
  if (filaAEditar > 0 && filaAEditar <= *n) {
      for (int j = 0; j < M; j++) {
          printf("Ingrese el nuevo valor para producto %d en la columna %d: ", filaAEditar, j+1);
          scanf("%s", nuevoValor);
          strcpy(productos[filaAEditar-1][j], nuevoValor); 
          printf("Fila %d columna %d editada exitosamente.\n", filaAEditar, j+1);
      }

  } else {
      printf("Fila inválida, ingrese un valor válido.\n");
  }
}
void imprimirMatriz(int n, int M, char productos[n][M][50]) {
  for (int i = 0; i < n; i++) {
      printf("Producto %d:\n", i + 1);//OPCIONAL
      for (int j = 0; j < M; j++) {
          printf("%s\t", productos[i][j]);
      }
      printf("\n");
  }
}
void eliminarFilaPorNombre(int* n, int M, char productos[*n][M][50], char nombreProducto[]) {
  int filaAEliminar = -1;

  for (int i = 0; i < *n; i++) {
      if (strcmp(productos[i][0], nombreProducto) == 0) {
          filaAEliminar = i;
          break;
      }
  }

  if (filaAEliminar != -1) {
      for (int i = filaAEliminar; i < *n - 1; i++) {
          for (int j = 0; j < M; j++) {
              strcpy(productos[i][j], productos[i + 1][j]);
          }
      }
      (*n)--;
      printf("La fila con el producto '%s' ha sido eliminada.\n", nombreProducto);
  } else {
      printf("No se encontró el producto '%s'.\n", nombreProducto);
  }
}
void buscarProductoPorNombre(int n, int M, char productos[n][M][50], char nombreProducto[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            if (strcmp(productos[i][j], nombreProducto) == 0) {
                printf("Producto encontrado en la fila %d:\n", i + 1);
                for (int k = 0; k < M; k++) {
                    printf("%s\t", productos[i][k]);
                }
                printf("\n");
            }
        }
    }
}
