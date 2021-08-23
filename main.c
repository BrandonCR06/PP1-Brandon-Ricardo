#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//Prototipos de las funciones
int menuPrincipal();
int menuOperativo();
int menuGeneral();

//Funciones generales
char * getString();

//Funciones del submenu operativo
void infoAulas();



int main(){
        menuPrincipal();
        return 0;
}


int menuPrincipal() {
        
        int opcion;
        char temp[10];
        
        do
        {
        printf( "\n   -==[ Gestion de aulas ]==-");
        printf( "\n   1. Opciones Operativas");
        printf( "\n   2. Opciones Generales");
        printf( "\n   3. Salir");
        printf( "\n\n   Introduzca opciocn (1-3): ");

        fgets(temp,10,stdin);
        opcion = atoi(temp);

        switch ( opcion )
        {
            case 1: 
                menuOperativo();
                break;

            case 2: 
                menuGeneral();
                break;

         }

    } while (opcion != 3);
    return 0;
}



char * getString(){
     char letra = ' ';     
     int i = 0; 
     char * str = malloc(sizeof(char));
     while(letra!=10){
          scanf("%c",&letra);
          str[i] = letra;
          i++;
          str = realloc(str,sizeof(char)*i);          
     };
     return str;
}







int menuOperativo() {
    
    int opcion;
    char temp[10];

    do
    {
        printf( "\n   -==[ Menu Operativo ]==-");
        printf( "\n   1. Información Aulas");
        printf( "\n   2. Información de Profesores");
        printf( "\n   3. Información de Cursos");
        printf( "\n   4. Cursos por Período");
        printf( "\n   5. Reservación de aula");
        printf( "\n   6. Cancelar Reservación");
        printf( "\n   7. Estadísticas");
        printf( "\n   8. Salir");
        printf( "\n\n   Introduzca opcion (1-8): ");

        fgets(temp,10,stdin);
        opcion = atoi(temp);


        switch ( opcion )
        {
            case 1: 
                    infoAulas();
                    break;
                
            case 2: 
                    break;
            case 3: 
                    break;
            case 4: 
                    break;
            case 5: 
                    break;
            case 6: 
                    break;
            case 7: 
                    break;
         }

    } while ( opcion != 8 );
    return 0;
    
}



void infoAulas() {

        FILE *archivo; 	
 	char caracteres[100];
        char ruta[50];

        printf("Ingrese la ruta del archivo: ");
        scanf("%s",ruta);

 	archivo = fopen(ruta,"r");
 	
 	if (archivo == NULL)
 		exit(1);
 	else
        {
 	    printf("\nEl contenido del archivo de prueba es \n\n");
 	    while (feof(archivo) == 0) {
                     
                     int t = 0;
                     //Se obtiene un renglon
                     fgets(caracteres,100,archivo);
                    
                     //Se separa
                     char *token = strtok(caracteres, ",");
                     while(token != NULL){
                             if (t = 0) {
                                printf("Aula: %s ", token);
                                token = strtok(NULL, "");
                                t+=1;
                             }
                             printf("Cupos: %s ", token);
                             token = strtok(NULL, "");
                        }

 		    //printf("%s",caracteres);
 	    }
    }       
    fclose(archivo);

}



int menuGeneral() {
    
    int opcion;
    char temp[10];

    do
    {
        printf( "\n   -==[ Menu General ]==-");
        printf( "\n   1. Consulta por dia");
        printf( "\n   2. Consulta por aula");
        printf( "\n   3. Consulta por curso");
        printf( "\n   4. Salir");
        printf( "\n\n   Introduzca opciocn (1-4): ");

        fgets(temp,10,stdin);
        opcion = atoi(temp);


        switch ( opcion )
        {
            case 1: 
                    break;
            case 2: 
                    break;
            case 3: 
                    break;
         }

    } while ( opcion != 4 );
    return 0;


}