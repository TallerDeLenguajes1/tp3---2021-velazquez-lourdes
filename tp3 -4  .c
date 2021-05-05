#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char *TiposProductos [] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct Productos
{
    int ProductoID; //numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10 
    char *TiposProductos; // Algun valor del arreglo TipoProducto
    float PrecioUnidad; // entre 10 - 100
}Productos;

typedef struct Cliente
{
    int ClienteID; // numerado en el ciclo iterativo
    char *NombreCliente; //Ingresado por usuario
    int CantidadProductosAPedir; // aleatorio entre 1 y 5 
    Productos *Produc; //El tamaño de este arreglo depende de la variable 
    int Cantidad_Producto; //Cantidad de productos a pedir 
}Cliente;

void Nuevo_produco (Productos *nuevo_prod, int cantidad)
{
 int i, j;
 for (i=0; j< cantidad; i++)
 {
     (nuevo_prod + i) -> ProductoID = i+1;
     (nuevo_prod + i) -> Cantidad = rand()% 10 +1 ;
     j = rand ()% 5;
     (nuevo_prod + i) -> TiposProductos = (char*)malloc(sizeof(char*)* strlen(TiposProductos[j]));
     strcpy((nuevo_prod + i) ->TiposProductos, TiposProductos[j] );
     (nuevo_prod +i) -> PrecioUnidad = (float) (rand()% 91 + 100);
     fflush(stdin);
     getchar();
 }
}

void Cargar_cliente ( Cliente *Clien, int cantidad  )
{
    char Nombre[100];
    int i;
    for (i=0 ; i < cantidad; i++)
    {
        (Clien + i) -> ClienteID = i +1;
        printf("Ingresar el nombre del cliente:  \n");
        scanf ("%s", Nombre); 
        fflush(stdin);
        getchar();
        (Clien +i) ->NombreCliente= (char*)malloc(sizeof(char)* strlen(Nombre));
        strcpy((Clien + i) -> NombreCliente, Nombre); 
        fflush(stdin);
        (Clien +i) -> CantidadProductosAPedir = rand ()% 5 ;
        (Clien +i) -> Produc = (Productos *) malloc(sizeof(Productos*) * (Clien +i) -> CantidadProductosAPedir);     
        Nuevo_produco((Clien + i) -> Produc, (Clien +i)-> CantidadProductosAPedir);
    }
}
 void mostrar_Cliente (Cliente * cliente, int cantidad)
{
    int i;
    for (i=0; i < cantidad; i++)
    {
        printf("Cliente Numero: %d \n", (cliente +i)-> ClienteID);
        printf("Nombre: %s \n", (cliente +i)-> NombreCliente);
        printf("Cantidad del producto: %d \n", (cliente +i)-> CantidadProductosAPedir);
        printf("productos: %d \n");
        mostrar_Producto((cliente +i)->Produc, (cliente +i)-> CantidadProductosAPedir);
    }
}
void mostrar_Producto (Productos * prod, int cantidad_productos)
{
    int i;
    float precio, total;
    for (i=0; i< cantidad_productos; i++)
    {
        printf("Producto numero: %d \n", (prod +i)->ProductoID );
        printf("Cantidad del producto: %d \n",(prod+i) -> Cantidad);
        printf("tipo de producto: %d \n", (prod +i)-> TiposProductos);
        printf("precio por unidad: %d \n", (prod +i) -> PrecioUnidad);
        precio = ((prod -> Cantidad)*(prod ->PrecioUnidad));
        total += precio;
         printf("\nPrecio total: $ %.2f", precio);
        printf("\n");
    }
    printf("TOTAL: $ %.2f \n", total);
}


void mostrar_recibo (Productos *prod, int cantidad)
{
    int i;
    float precio, total;
    for (i =0; i<cantidad; i++)
    {
        precio =((prod ->Cantidad)* (prod->PrecioUnidad)) ;
        total += precio;
        printf("Precio por cantidad de producto: $ %.2f \n", precio );
    }
    printf("total del cliente: $ %.2f \n", total);
}





int main ()
{
    srand (time(NULL));
    int Cantidad_cliente;
    Cliente *Clientes;
    printf("Ingrese la cantidad de clientes:\n ");
    scanf("%d", &Cantidad_cliente);
    fflush(stdin);
    Clientes = (Cliente*)(malloc(sizeof(Cliente)*Cantidad_cliente));
    Cargar_cliente(Clientes, Cantidad_cliente);
    mostrar_Cliente(Clientes, Cantidad_cliente);
    free(Clientes);

getchar();
return 0;
}