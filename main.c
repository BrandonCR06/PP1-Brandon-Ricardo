#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>

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

//Funciones del submenu general
void consultaXdia();
void consultaXaula();
void consultaXcurso();


// Compilar: gcc main.c -o main -I /usr/include/postgresql -lpq -std=c99



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
        printf( "\n\nIntroduzca una opcion (1-3): ");

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
        printf( "\n\nIntroduzca una opcion (1-4): ");

        fgets(temp,10,stdin);
        opcion = atoi(temp);


        switch ( opcion )
        {
            case 1: consultaXdia();
                    break;
            case 2: consultaXaula();
                    break;
            case 3: consultaXcurso();
                    break;
         }

    } while ( opcion != 4 );
    return 0;


}

void consultaXdia() {
        PGconn *conn =  PQconnectdb("dbname=prueba host=localhost user=me password=password");
        printf("Ingrese la fecha a consultar: ");
        char * fecha = getString();
        const char *  paramValues[1];
     
        paramValues[0] = fecha;
        
        char *stm = "SELECT a.nombre, r.reservacionid, cp.annio, cp.periodo, cp.codigoCurso, cp.grupo, r.horaInicio, r.horaFin FROM aulas a INNER JOIN reservacionesxaula ra on ra.aulaid = a.nombre  INNER JOIN reservacion r on r.reservacionid = ra.reservacionid INNER JOIN cursosxperiodo cp on cp.cursoxperiodoid = r.cursoxperiodo WHERE r.fecha = $1";
        PGresult *res = PQexecParams(conn, stm, 1, NULL, paramValues, NULL, NULL, 0);   
        int rows = PQntuples(res);
        if(rows< 1){
                printf("\n      No hay ninguna aula reservada para esa fecha\n");
                return;
        } 
        printf("\n       CONSULTAS POR DIA - %s\n",fecha);
        printf("Aula ID Año Periodo Codigo Grupo Inicio Fin\n");
        for (int i=0; i<rows; i++) {
                printf("%s  %s  %s  %s  %s  %s  %s  %s\n", PQgetvalue(res, i, 0), 
            PQgetvalue(res, i, 1), PQgetvalue(res, i, 2),
            PQgetvalue(res, i, 3), PQgetvalue(res, i, 4),
            PQgetvalue(res, i, 5), PQgetvalue(res, i, 6),
            PQgetvalue(res, i, 7));
        }

        PQfinish(conn);
}

void consultaXaula() {

        PGconn *conn =  PQconnectdb("dbname=prueba host=localhost user=me password=password");
        printf("Ingrese el nombre del aula a consultar: ");

        char nombreAula[255];
        scanf(" %s",&nombreAula[0]);
        while(getchar() != '\n');
        const char *  paramValues[1];
     
        paramValues[0] = nombreAula;

        char *stm = "SELECT r.Fecha, r.horaInicio, r.horaFin, r.reservacionid, cp.annio, cp.periodo, cp.codigoCurso, cp.grupo FROM aulas a INNER JOIN reservacionesxaula ra on ra.aulaid = a.nombre  INNER JOIN reservacion r on r.reservacionid = ra.reservacionid INNER JOIN cursosxperiodo cp on cp.cursoxperiodoid = r.cursoxperiodo WHERE a.nombre = $1 ORDER BY r.Fecha";
        PGresult *res = PQexecParams(conn, stm, 1, NULL, paramValues, NULL, NULL, 0);   
        int rows = PQntuples(res);
        if(rows< 1){
                printf("\n      No hay %s\n",nombreAula);
                return;
        } 

        printf("\n        -={ Consulta por Aula:%s }=-\n",nombreAula);
        for (int i=0; i<rows; i++) {
                printf("%s  %s  %s  %s  %s  %s  %s  %s\n", PQgetvalue(res, i, 0), 
            PQgetvalue(res, i, 1), PQgetvalue(res, i, 2),
            PQgetvalue(res, i, 3), PQgetvalue(res, i, 4),
            PQgetvalue(res, i, 5), PQgetvalue(res, i, 6),
            PQgetvalue(res, i, 7));
        }

        PQfinish(conn);
        return;
}

void consultaXcurso() {

        PGconn *conn =  PQconnectdb("dbname=prueba host=localhost user=me password=password");
        
        printf("Ingrese el año a consultar: ");
        char annio[255];
        scanf("%s",&annio[0]);

        printf("Ingrese el periodo a consultar: ");
        char periodo[255];
        scanf("%s",&periodo[0]);
        
        printf("Ingrese el codigo de curso a consultar: ");
        char cod[255];
        scanf("%s",&cod[0]);

        printf("Ingrese el grupo a consultar: ");
        char grupo[255];
        scanf("%s",&grupo[0]);
        while(getchar() != '\n');
        
        const char *  paramValues[4];
     
        paramValues[0] = annio;
        paramValues[1] = periodo;
        paramValues[2] = cod;
        paramValues[3] = grupo;
        
        char *stm = "SELECT cp.codigoCurso, r.Fecha, r.horaInicio, r.horaFin, a.Nombre FROM aulas a INNER JOIN reservacionesxaula ra on ra.aulaid = a.nombre  INNER JOIN reservacion r on r.reservacionid = ra.reservacionid INNER JOIN cursosxperiodo cp on cp.cursoxperiodoid = r.cursoxperiodo WHERE cp.annio = $1 and  cp.periodo = $2 and cp.codigoCurso = $3 and cp.grupo = $4 ORDER BY r.Fecha, r.horaInicio, a.Nombre";
        PGresult *res = PQexecParams(conn, stm, 4, NULL, paramValues, NULL, NULL, 0);   
        int rows = PQntuples(res);
        if(rows< 1){
                printf("\n      No hay ningun curso reservado con esos datos\n");
                return;
        } 
        printf("\n       -={ Consulta por Curso }=-\n");
        for (int i=0; i<rows; i++) {
                printf("%s  %s  %s  %s  %s\n", PQgetvalue(res, i, 0), 
            PQgetvalue(res, i, 1), PQgetvalue(res, i, 2),
            PQgetvalue(res, i, 3), PQgetvalue(res, i, 4));
        }

        PQfinish(conn);
}