#include "funciones.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n = 0;
  int M = 6;
  int FilaAEditar;

  printf("Ingrese el número de productos que va a ingresar:\n");
  scanf("%d", &n);

  if (n <= 0) {
    printf("El número de productos debe ser mayor que 0\n");
    return 0;
  }

  printf("NOMBRE DE PRODUCTO     PRECIO     CANTIDAD     CATEGORIA     TALLA   "
         "  GENERO\n");
  char productos[n][M][50];

  for (int i = 0; i < n; i++) {
    printf("Producto %d:\n", i + 1);
    for (int j = 0; j < M; j++) {
      scanf("%s", productos[i][j]);
    }
  }
  imprimirMatriz(n, M, productos);

  char nombreProducto[50];
  int deseaEditarUnaFila = 0;
  printf("¿Desea editar una producto?\n1 para editar, 0 para continuar\n");
  scanf("%d", &deseaEditarUnaFila);

  if (deseaEditarUnaFila == 1) {
    printf("Ingrese el número de producto que desea editar: ");
    scanf("%d", &FilaAEditar);
    char nuevoValor[50];
    editarFila(&n, M, productos, FilaAEditar, nuevoValor);
    imprimirMatriz(n, M, productos);
  }
  int deseaEliminarUnaFila = 0;
  printf("¿Desea eliminar una producto?\n1 para eliminar, 0 para salir\n");
  scanf("%d", &deseaEliminarUnaFila);
  if (deseaEliminarUnaFila == 1) {
    printf("Ingrese el nombre del producto que desea eliminar:\n");
    scanf("%s", nombreProducto);
    eliminarFilaPorNombre(&n, M, productos, nombreProducto);
  }
  int deseaBuscarUnProducto = 0;
  imprimirMatriz(n, M, productos);
  printf(
      "¿buscar una categoria, talla o genero?\n1 para buscar, 0 para salir\n");
  scanf("%d", &deseaBuscarUnProducto);

  if (deseaBuscarUnProducto == 1) {
    printf("Ingrese el nombre de la categoria, talla o genero:\n");
    scanf("%s", nombreProducto);
    buscarProductoPorNombre(n, M, productos, nombreProducto);
  }

  return 0;
}