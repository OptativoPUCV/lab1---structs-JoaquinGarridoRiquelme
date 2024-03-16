#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) 
{
  /*Creamos valor auxiliar para ir guardando el mayor valor encontrado y 
  posteriormente retornarlo(partimos guardando el primer valor del arreglo)*/
  int numero_mayor = arr[0];
  for(int i = 0; i < size; i++)
    {
      if(arr[i] > numero_mayor)
          numero_mayor = arr[i];
    }
  return numero_mayor; 
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) 
{
  //Creamos un arreglo auxiliar el cual es el original invertido
  int arr_aux[size];
  for(size_t i = 0; i < size; i++)
    {
      arr_aux[i] = arr[size - i - 1];
    }
  //Copiamos nuestro arreglo invertido en el original para su modificacion
  for(size_t i = 0; i < size; i++)
    {
      arr[i] = arr_aux[i];
    }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
newsize apunta a una dirección válida que no ha sido inicializada con nigún valor específico. 
*newsize debe almacenar el tamaño del nuevo arreglo que se retorna.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) 
{
  //Iniciamos el valor de nuestra nueva talla en 0
  *newSize = 0;
  /*Reservamos memoria para el nuevo arreglo, teniendo en cuenta la talla del arreglo     
  original*/
  int *nuevo_arreglo = (int*) malloc (sizeof(int) * size);
  for(int i = 0; i < size; i++)
    {
      //Buscamos los numeros pares
      if(arr[i] % 2 == 0)
      {
        //Agregamos el numero y aumentamos la talla del nuevo arreglo
        nuevo_arreglo[*newSize] = arr[i];
        (*newSize) += 1; 
      }
    }
  return nuevo_arreglo; 
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados de menor a mayor y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado de menor a mayor.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,int result[]) 
{
  int i = 0, j = 0, pos = 0;
  //Iniciamos un bucle hasta que uno o ambos arreglos se hayan recorrido
  while(i < size1 && j < size2)
    {
      /*Comparamos cada elemento de cada arreglo para asi poder ordenar*/
      if(arr1[i] < arr2[j])
      {
        result[pos] = arr1[i];
        i++;
        pos++;
      }
      else if(arr1[i] > arr2[j])
      {
        result[pos] = arr2[j];
        j++;
        pos++;
      }
      //En caso de ser iguales, ambos se agregan
      else
      {
        result[pos] = arr1[i];
        result[pos + 1] = arr2[j];
        pos += 2;
        i++;
        j++;
      } 
    }
  //Verificamos si quedan elementos pendientes por agregar
  while(i < size1)
    {
      result[pos] = arr1[i];
      pos++;
      i++;
    }
  while(j < size2)
    {
      result[pos] = arr2[j];
      pos++;
      j++;
    }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) 
{
  //Usaremos banderas para condicionar el retorno de la funcion
  bool ascendente = true, descendente = true;
  for(int i = 0; i < size - 1; i++)
    {
      //Vemos las condiciones de cada caso y vamos descartando posibilidades
      if(arr[i] > arr[i + 1])
      {
        ascendente = false;
      }
      else if(arr[i] < arr[i + 1])
      {
        descendente = false;
      }
    }
  //Retornamos los valores requeridos segun las condiciones del caso
  if(ascendente) return 1;
  if(descendente) return -1;
  return 0;
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) 
{
  /*Simplemente pegamos los elementos en las casillas de la estructura, la cual
  manejamos a traves del puntero a libro*/
  strcpy(libro -> titulo, titulo);
  (libro -> anioPublicacion)  = anioPublicacion;
  strcpy(libro ->autor.nombre, nombreAutor);
  (libro ->autor.anioNacimiento)  = anioNacimiento;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
Puedes guiarte con lo que vimos en las clases (diapos).
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) 
{ 
  Nodo *head = NULL;
  Nodo *nodo_aux_1;
  Nodo *nodo_aux_2;

  for(int i = 0; i < size; i++)
    {
      //En caso de ser la primera iteracion, configuramos el primer nodo
      if(head == NULL)
      {
        
      }
    }
    
  return NULL;
}
