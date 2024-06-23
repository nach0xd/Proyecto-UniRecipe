*Nota:* Para correr el programa en el shell: gcc tdas/*.c main.c -Wno-unused-result -o prueba, y luego ./prueba

## UniRecipe, recetario para estudiantes universitarios

Esta aplicación esta creada con el fin de apoyar a los estudiantes de educación superior a mantener una dieta sana, ofreciendoles diversas recetas que se destacan por su sencillez y rapidez en su preparación. El archivo "recetas.csv" que se sube a este programa contiene X recetas con su respectiva información, como nombre, ingredientes, complejidad, preparación paso a paso, etc.

## Funcionalidades de la aplicación
**1) Cargar recetas:** El programa carga los datos de cada recetas que contiene el archivo  

**2) Buscar recetas por ingredientes:** El programa permite al usuario buscar recetas dependiendo de el ingrediente que posea, buscando en la lista de ingredientes de cada receta dentro del mapa, si encuentra alguna receta o recetas que contengan el ingrediente que posea el usuario entonces el programa muestra el nombre de dicha receta o recetas

**3) Buscar recetas por nombre:** El programa permite al usuario buscar una receta por el nombre de esta misma, si la receta se encuentra dentro del mapa el programa muestra todo el contenido del struct de esa receta

**4) Buscar recetas por complejidad:** El programa permite al usuario buscar recetas dependiendo de la complejidad que tengan, permitiendole elegir entre tres opciones, 1 para "Fácil", 2 para "Media" y 3 para "Difícil". El usuario al elegir una opcion hace que el programa recorra el mapa para buscar todas las recetas con la complejidad deseada para luego mostrar los nombres de cada receta con la complejidad deseada

**5) Añadir receta a 'Recetas favoritas':** El programa permite al usuario añadir recetas a una lista de recetas favoritas mediante escribiendo el nombre de la receta, el programa logra esto cambiando el estado de favoritos de la receta buscada de 0 a 1, de esta manera considerando esa receta como una receta favorita 

**6) Mostrar 'Recetas favoritas':** El programa permite al usuario ver las recetas que marcó previamente como favoritas, mostrando una lista de todas las recetas favoritas, el programa realiza esto buscando en el mapa cada receta con el estado de favorito igual a 1 para luego añadirlas a la lista de favoritos que finalmente se mostrará 
