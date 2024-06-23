#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tdas/list.h"
#include "tdas/map.h"
#include "tdas/extra.h"

//Estructura para recetas
typedef struct {
  char nombre_receta[50];
  List *ingredientes;
  char procedimiento[500];
  int complejidad;
  int estado_fav;
} cont_receta;

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Menú Principal");
  puts("========================================");

  puts("1) Buscar Recetas por Ingredientes");
  puts("2) Buscar Recetas por Nombre");
  puts("3) Buscar Recetas por Complejidad");
  puts("4) Añadir Recetas a 'Recetas favoritas'");
  puts("5) Mostrar 'Recetas favoritas'");
  puts("6) Salir");
}

//Menú inicial
void mostrarMenuInicial(){
  limpiarPantalla();
  puts("========================================");
  puts("      Bienvenido a UniRecipe");
  puts("========================================");

  puts("Bienvenido a esta app de recetario para universitarios, por favor\nseleccione la siguiente opción para continuar:");
  puts("1) Cargar Recetas");
  puts("2) Salir");
}

int is_equal_str(void *key1, void *key2) {
  return strcmp((char *)key1, (char *)key2) == 0;
}

int is_equal_int(void *key1, void *key2) {
  return *(int *)key1 == *(int *)key2; // Compara valores enteros directamente
}

void eliminar_Comillas(char *string){ //caso que haya comillas 
  int largo = strlen(string); 

  if (string[0] == '"'){ 
    memmove(string, string + 1, largo); 
    largo--; 
  }
  if (largo > 0 && string[largo - 1] == '"'){ 
    string[largo - 1] = '\0'; 
  }
}

char *espacio_inicial(char *string) {
  while (isspace((unsigned char)*string)) string++; 
  
  return string; 
}

//Carga recetas desde un archivo CSV y las almacena en un mapa por ID.
void cargar_recetas(Map *mapa_recetas){
  FILE *archivo = fopen("recetas.csv", "r");
  if (archivo == NULL) {
    perror("Error al abrir el archivo"); 
    return;
  }

  char **campos;
  campos = leer_linea_csv(archivo, ',');

  while ((campos = leer_linea_csv(archivo, ',')) != NULL){
    cont_receta *receta = (cont_receta *)malloc(sizeof(cont_receta));
    //Almacenar los datos de las recetas.....
    strcpy(receta->nombre_receta, campos[5]); // Asigna nombre de la receta
    eliminar_Comillas(receta->nombre_receta);
    receta->ingredientes = list_create();

    char *token_ingredientes = strtok(campos[20], ",");
    
    while (token_ingredientes != NULL){
      char *clean_token = espacio_inicial(token_ingredientes);
      
      list_pushBack(receta->ingredientes, clean_token);
      
      token_ingredientes = strtok(NULL, ",");
    }
    strcpy(receta->procedimiento, campos[500]);
    receta->complejidad = atoi(campos[3]); // Asigna la complejidad de la receta
    receta->estado_fav = 0; // Asigna el estado predeterminado de favoritos a la receta
  }
  fclose(archivo);

  printf("Recetas cargadas exitosamente.\n");
}

//Función para buscar un dato alfabetico en una lista
int buscar_con_char(List *lista, char *nombre){
  return 0;
}
//Función que busca un dato numerico en una lista
int buscar_con_int(List *lista, int num){
  return 0;
}
//Función para buscar recetas por sus ingredientes
void buscar_recetas_por_ingredientes(Map *mapa_recetas, char *ingrediente){
  
}
//Función para buscar recetas por nombre
void buscar_recetas_por_nombre(Map *mapa_recetas){
  /*char nombre[50]; //Variable para almacenar el nombre de la receta

  //Solicitar al usuario el nombre de la receta
  printf("Ingrese el nombre de la receta: ");
  scanf("%s", nombre);

  //Buscar la receta en el mapa de recetas
  MapPair *pair = map_search(mapa_recetas, nombre);

  //Si se encontro la receta, mostrar los datos de la misma
  if (pair != NULL){
    cont_receta *receta = pair->value; //Obtiene el puntero a la estructura de la receta
    printf("Receta: %s, ingredientes: %s, procedimiento: %s, complejidad: %d.\n", receta->nombre_receta, receta->ingredientes, receta->procedimiento, receta->complejidad);
  } else{
    //Si no se encontró la receta, informar al usuario
    printf("No se encontró la receta con el nombre ingresado.\n");
  }*/
}

void rellenar_mapa_recetas(Map *mapa_recetas){
  
}

//Función para buscar recetas por complejidad
void buscar_recetas_por_complejidad(Map *mapa, int num){
  
}

//Función para añadir receta a favoritos
void anadir_favoritos(Map *mapa, char *nombre){
  
}

//Función para mostrar lista de recetas favoritos
void mostrar_favoritos(Map *mapa){
  
}

int main(){
  char opcion;
  char opcion2;
  //Crear mapas
  Map *receta_byingredientes = map_create(is_equal_str);
  Map *receta_bynombre = map_create(is_equal_str);
  Map *receta_bycomplejidad = map_create(is_equal_int);
  Map *receta_favoritos = map_create(is_equal_str);
  
  do {
    mostrarMenuInicial();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion);
    switch (opcion){
      case '1':
      printf("Cargando recetas...\n");
      //cargar_recetas(receta_byingredientes);
      //rellenar mapas
      //rellenar_mapa_ingredientes(receta_byingredientes);
      do {
        mostrarMenuPrincipal();
        printf("Ingrese su opción: ");
        scanf(" %c", &opcion2);

        switch (opcion2) {
        case '1':
          printf("Aquí implementar función 'buscar_recetas_por_ingredientes()'\n");
          //buscar_recetas_por_ingredientes();
          break;
        case '2':
          printf("Aquí implementar función 'buscar_recetas_por_nombre()'\n");
          //buscar_recetas_por_nombre();
          break;
        case '3':
          printf("Aquí implementar función 'buscar_recetas_por_complejidad()'\n");
          //buscar_recetas_por_complejidad();
          break;
        case '4':
          printf("Aquí implementar función 'anadir_favoritos()'\n");
          //anadir_favoritos();
          break;
        case '5':
          printf("Aquí implementar función 'mostrar_favoritos()'\n");
          //mostrar_favoritos();
          break;
        case '6':
          printf("Salir a Menú de inicio\n");
          break;
        default:;
        }
        presioneTeclaParaContinuar();

      } while (opcion2 != '6');
      
    }
  } while (opcion != '2');
  return 0;
}
