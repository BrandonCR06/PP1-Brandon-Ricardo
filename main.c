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
void infoProfesores();
void infoCursos();
void infoCursosPorPeriodo();


int main(){
        menuPrincipal();
        return 0;
}


int menuPrincipal() {
        
        int opcion;
        char temp[10];
        
        do
        {
        printf( "\n  -==[ Gestion de aulas ]==-");
        printf( "\n1. Opciones Operativas");
        printf( "\n2. Opciones Generales");
        printf( "\n3. Salir");
        printf( "\n\nIntroduzca opciocn (1-3): ");

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
        printf( "\n  -==[ Menu Operativo ]==-");
        printf( "\n1. Información Aulas");
        printf( "\n2. Información de Profesores");
        printf( "\n3. Información de Cursos");
        printf( "\n4. Cursos por Período");
        printf( "\n5. Reservación de aula");
        printf( "\n6. Cancelar Reservación");
        printf( "\n7. Estadísticas");
        printf( "\n8. Salir");
        printf( "\n\nIntroduzca opcion (1-8): ");

        fgets(temp,10,stdin);
        opcion = atoi(temp);


        switch ( opcion )
        {
            case 1: 
                    infoAulas();
                    break;
                
            case 2: 
                    infoProfesores();
                    break;
            case 3: 
                    infoCursos();
                    break;
            case 4: 
                    infoCursosPorPeriodo();
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


void infoProfesores() {

    int opcion;
    char temp[10];

    do
    {
        printf( "\n  -==[ Profesores ]==-");
        printf( "\n1. Incluir profesor");
        printf( "\n2. Listar profesores");
        printf( "\n3. Borrar todo");
        printf( "\n4. Salir");
        printf( "\n\nIntroduzca opciocn (1-4): ");

        fgets(temp,10,stdin);
        opcion = atoi(temp);


        switch ( opcion )
        {
            case 1: 
                    printf("Ingrese la cedula del profesor: ");
                    char * cedula = getString();
                    printf("Ingrese el nombre del profesor: ");
                    char * nombre = getString();
                    //Guardar en la base de datos
                    break;
            case 2: 
                    //Select * from profesores;
                    break;
            case 3: 
                   //Delete From profesores;
                    break;
         }

    } while ( opcion != 4 );

}

void infoCursos() {

        //El sistema debe permitir listar los cursos; la información será código de carrera, código de curso y 
        //nombre. La unicidad la dará el código de curso. El sistema debe tener precargados los cursos en la 
        //base de datos.

        //Select * from cursos;

}



void infoCursosPorPeriodo() {

    int opcion;
    char temp[10];

    do
    {
        printf( "\n  -==[ Cursos por periodo ]==-");
        printf( "\n1. Incluir ");
        printf( "\n2. Listar");
        printf( "\n3. Eliminar");
        printf( "\n4. Salir");
        printf( "\n\nIntroduzca opciocn (1-4): ");

        fgets(temp,10,stdin);
        opcion = atoi(temp);

        char *codigoCurso;
        char *anno;
        char *p;
        char *grupo;
        char *c;
        int year;
        int periodo;

        switch ( opcion )
        {
            case 1: 
                    //la información será de código de curso, año, período (1 o 2), 
                        //grupo, profesor y cantidad de estudiantes.
                    printf("\nIngrese el codigo del curso: ");
                    codigoCurso = getString();
                    printf("\nIngrese el año: ");
                    anno = getString();
                    year = atoi(anno);
                    printf("\nIngrese el periodio ( 1 o 2): ");
                    p = getString();
                    periodo = atoi(p);
                    printf("\nIngrese el nombre del grupo:");
                    grupo = getString();
                    printf("\nIngrese la cantidad de estudiantes: ");
                    c = getString();
                    int cantEstudiantes = atoi(c);
                    //Guardar en la base de datos
                    break;
            case 2: 
                    //Select * from cursosPorPeriodo
                    break;
            case 3: 
                   //Borrar
                   printf("\nIngrese el codigo del curso que desea borrar: ");
                   codigoCurso = getString();
                   printf("\nIngrese el año: ");
                   anno = getString();
                   year = atoi(anno);
                   printf("\nIngrese el periodio ( 1 o 2): ");
                   p = getString();
                   periodo = atoi(p);
                   printf("\nIngrese el nombre del grupo:");
                   grupo = getString();
                   //delect from cursosPorPeriodo where bla bla bla
                   break;
         }

    } while ( opcion != 4 );

}




int menuGeneral() {
    
    int opcion;
    char temp[10];

    do
    {
        printf( "\n  -==[ Menu General ]==-");
        printf( "\n1. Consulta por dia");
        printf( "\n2. Consulta por aula");
        printf( "\n3. Consulta por curso");
        printf( "\n4. Salir");
        printf( "\n\nIntroduzca opciocn (1-4): ");

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