#include <stdio.h>
#include <stdlib.h>
#include "libpq-fe.h"
#define TRUE 1
#define FALSE 0
#define endl printf("\n")
//Prototipos de las funciones
void menuPrincipal();
void menuOperativo();
void menuGeneral();

//Funciones generales
char * getString();

//Funciones del submenu operativo
void infoAulas();

struct cadena{
     char** lista;
     int tamanio;
};

int count(char car[] ){
      char* mem = car;
     int i =0;

     while((*mem++)){          
          i++;
     }
     return i;     
}
void imprime(char* car){
     char* mem = car;
     int i =0;
     while((*mem++)){
          printf("%c",car[i]);
          i++;
     }
     //printf("%i",i);
}

struct cadena split(char car[],char splitArg){
     int cont = 1;
     int i = 0;
     char** retorno = calloc(1,sizeof(char*));
          
     char* mem = car;
     char* tmp = calloc(1,sizeof(char));
     int  j = 0;     
     int c = count(car);

     while(i<c){
          if(car[i]!=splitArg) {
               tmp[cont-1] = car[i];
          }                         

          if(car[i]==splitArg){  
               while(car[i]==splitArg){
                    i++; 
               }                        
               j++;
               retorno = (char**)realloc(retorno,sizeof(char*)*j);                              
               retorno[j-1] = (char*)tmp;                  
               cont = 1;                        
               tmp = calloc(1,sizeof(char));
               
          }else{
               cont++;
               tmp = (char*)realloc(tmp,sizeof(char)*cont);                              
               i++;
          }                                    
     }     
     j++;
     
     retorno = (char**)realloc(retorno,sizeof(char*)*j);               
     retorno[j-1] = tmp;   
     struct cadena cad = {retorno,j};
     for(int i = 0 ; i < j; i++){
          imprime(retorno[i]);
          endl;
     }
     return cad;
     
     
}

int main(){
        menuPrincipal();
        return 0;
}


char * getString(){
     char letra = ' ';     
     int i = 1; 
     char * str = malloc(sizeof(char));
     getchar();     
     while(letra!=10){
          scanf("%c",&letra);           
          str[i-1] = letra;
          i++;   
          str = realloc(str,sizeof(char)*i);                    
                
     };
         
     str[i-1]= '\0';
     return str;
}


int compare(char* a, char* b ){
     char* cmp1 = a;
     char* cmp2 = b;
     int i = 0 ;
     while(cmp1[i]!='\0' && cmp2[i]!='\0'){
          if(cmp1[i]!=cmp2[i]){
               return 0;
          }
          i++;
     }
     return 1;
}




void incluirProfes(){
     printf("Ingrese la cedula del profesor: ");
     char cedula[255];
     getchar();     
     scanf("%s",&cedula[0]);
     printf("Ingrese el nombre del profesor: ");
     char nombre[255];
     getchar();     
     scanf("%s",&nombre[0]);
     PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
     const char *  paramValues[2];
     paramValues[0]= cedula;
     paramValues[1]= nombre;          
     //char * hola = PQgetvalue(res, 0, 1);
     char *stm = "Insert into profesores values ($1,$2)";     
     PGresult *res = PQexecParams(conn, stm, 2, NULL, paramValues, NULL, NULL, 0);    
     if (PQresultStatus(res) != PGRES_COMMAND_OK) {
               fprintf(stderr, " Error: %s\n",PQerrorMessage(conn));

     }
     PQfinish(conn);

               

}
     
void borrarProfes(){
     PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
     printf("Ingrese la cedula del profesor a borrar: ");
     char cedula[255];
     
     getchar();     
     scanf("%s",&cedula[0]);
     const char *  paramValues[1];
     paramValues[0]= cedula;
     char *stm = "delete from profesores where cedula = $1";
     PGresult *res = PQexecParams(conn, stm, 1, NULL, paramValues, NULL, NULL, 0);    
     if (PQresultStatus(res) != PGRES_COMMAND_OK) {
               fprintf(stderr, " Error: %s\n",PQerrorMessage(conn));

     }
     PQfinish(conn);

     
}

void imprimeQuery(char* stm ,int cantCol){
     PGconn *conn =PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
     PGresult *res = PQexec(conn, stm);    
     int rows = PQntuples(res);
     
     for(int i=0; i<rows; i++) {
          for(int j = 0 ; j < cantCol;j++){
               if(j!=cantCol-1){
                    
                    printf("%s: %s, ",PQfname(res,j),PQgetvalue(res, i, j));
               } else {
                    printf("%s: %s",PQfname(res,j),PQgetvalue(res, i, j));
               }                              
          }          
          endl;
          endl;          
     }    
     
}
void listarProfes(){
     PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
     PGresult *res = PQexec(conn, "SELECT cedula,nombre FROM profesores");    
     int rows = PQntuples(res);
    
     for(int i=0; i<rows; i++) {
        
          printf("  %s--%s\n", PQgetvalue(res, i, 0), 
          PQgetvalue(res, i, 1));
     }    
     PQfinish(conn);

}

void infoProfes(){
     int opcion;
        char repetir = TRUE;
      do
        {
        printf( "\n   -==[ Información de Profesores ]==-");
        printf( "\n   1. Listar");
        printf( "\n   2. Incluir");
        printf( "\n   3. Eliminar");
        printf( "\n   4. Volver");
        printf( "\n\n   Introduzca opcion (1-4): ");

        scanf( "%d", &opcion );


        switch ( opcion )
        {
            case 1: 
                listarProfes();

                break;

            case 2: 
               incluirProfes();
                
                break;
            case 3:
               borrarProfes();
                break;
            case 4: 
               repetir = FALSE;
               break;

         }

    } while (repetir);

}

void infoAulas() {
        
     printf("Ingrese la ruta del archivo: ");
     char archivo[255];
     getchar();
     
     scanf("%s",&archivo[0]);

     PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
     

     if (PQstatus(conn) == CONNECTION_BAD) {
          fprintf(stderr, "Connection to database failed: %s\n",PQerrorMessage(conn));
        
    }

    int ver = PQserverVersion(conn);
    printf("%s",archivo);


    
    endl;
    FILE * filepointer = fopen(archivo,"r");         
    
    endl;    
    char line[260];
    char c;
    char * tmp = calloc(1,sizeof(char));
    int i = 1;     
    int j = 0;
    while((c = getc(filepointer)) != EOF){         
         if(c==10){                  
               j++;
               tmp[i-1] = 10;   
               i++;
               tmp = realloc(tmp,sizeof(char)* i);                     
         }else{
              tmp[i-1] = c;   
               i++;
               tmp = realloc(tmp,sizeof(char)* i);       
         }

    }            
    fclose(filepointer);    
    //imprime(tmp);    
    struct cadena cad = split(tmp,10);
    
    char** splitedValue = cad.lista;
    for(int i = 0 ; i< j+1 ; i ++){
         struct cadena cad2 = split(splitedValue[i],',');

         char** aula= cad2.lista;
          const char * codigo1 = aula[0];
          const char * nombre = aula[1];    
          const char *  paramValues[2];
          paramValues[0]= codigo1;
          paramValues[1]= nombre;
          
          //char * hola = PQgetvalue(res, 0, 1);
          char *stm = "Insert into aulas values ($1,$2)";     
          PGresult *res = PQexecParams(conn, stm, 2, NULL, paramValues, NULL, NULL, 0);    
          if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                    fprintf(stderr, " Error: %s\n",PQerrorMessage(conn));

          }
          PQclear(res);
           
     }    
     
     PQfinish(conn);
               
          
        

    }

        






void incluirCursosxPeriodo(){
     PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
     printf("Ingrese el codigo de curso: ");
     char codigo[255];
     getchar();     
     scanf("%s",&codigo[0]);

     PGresult *res1 = PQexec(conn, "SELECT codigoCurso FROM cursos");    
     int rows1 = PQntuples(res1);
     int found1 = FALSE;
     for(int i=0; i<rows1; i++) {
          if(compare(PQgetvalue(res1, i, 0),codigo)){
               found1 = TRUE;
               break;
          }
     }    
     if(!found1){
          printf("Ese código de curso no existe en el sistema");
          return;
     }

     printf("Ingrese el periodo: ");
     char periodo[255];
     getchar();     
     scanf("%s",&periodo[0]);
     printf("Ingrese el año: ");
     char anio[255];
     getchar();     
     scanf("%s",&anio[0]);
     printf("Ingrese el grupo: ");
     char grupo[255];
     getchar();     
     scanf("%s",&grupo[0]);
     printf("Ingrese la cedula del profesor: ");
     char cedula[255];
     getchar();     
     scanf("%s",&cedula[0]);
     PGresult *res2 = PQexec(conn, "SELECT cedula FROM profesores");    
     int rows = PQntuples(res2);
     int found = FALSE;
     for(int i=0; i<rows; i++) {
          if(compare(PQgetvalue(res2, i, 0),cedula)){
               found = TRUE;
               break;
          }
     }    
     if(!found){
          printf("Cedula del profesor no encontrada");
          return;
     }
     

     printf("Ingrese la cantidad de estudiantes: ");
     char cant[255];
     getchar();     
     scanf("%s",&cant[0]);
     
     const char *  paramValues[6];
          

     paramValues[0]= codigo;
     paramValues[1]= periodo;          
     paramValues[2]= anio;          
     paramValues[3]= grupo;          
     paramValues[4]= cedula;          
     paramValues[5]= cant;          
     //char * hola = PQgetvalue(res, 0, 1);
     char *stm = "Insert into cursosxperiodo values (default,$1,$2,$3,$4,$5,$6)";     
     PGresult *res = PQexecParams(conn, stm, 6, NULL, paramValues, NULL, NULL, 0);       
     if (PQresultStatus(res) != PGRES_COMMAND_OK) {
               fprintf(stderr, " Error: %s\n",PQerrorMessage(conn));

     }
     PQfinish(conn);

}
// Permite realizar la reservación de aulas en el sistema 
void infoReservas(){
     PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
     printf( "\n   -==[Reservacion de aulas]==-");     
     printf( "\n Ingrese el codigo de curso: ");  
     char codigo[255];
     getchar();     
     scanf("%s",&codigo[0]);     
     printf( "\n Ingrese el periodo: ");     
     char periodo[255];
     getchar();     
     scanf("%s",&periodo[0]);     
     printf( "\n Ingrese el annio: ");     
     char annio[255];
     getchar();     
     scanf("%s",&annio[0]);     
     printf( "\n Ingrese el grupo: ");     
     char grupo[255];
     getchar();     
     scanf("%s",&grupo[0]);     
     //validando que exista el cursoxperiodo
     const char *  paramValues[4];
     
     paramValues[0] = codigo;
     paramValues[1] = periodo;
     paramValues[2] =annio;
     paramValues[3] = grupo;
     
     char *stmCursoxperiodo = "select cursoxperiodoid, codigoCurso,periodo,annio,grupo,cantEstudiantes from cursosxperiodo where codigoCurso = $1 and periodo = $2 and annio = $3 and grupo = $4";               
     PGresult *resCursoxPeriodo = PQexecParams(conn, stmCursoxperiodo, 4, NULL, paramValues, NULL, NULL, 0);   
     int rowsCursoxPriodo = PQntuples(resCursoxPeriodo);

     

     if(rowsCursoxPriodo< 1){
          printf("La informacion brindada no coincide con ningun curso por periodo en el sistema");
          return;
     } 
     
     char*  idCursoPeriodo = PQgetvalue(resCursoxPeriodo, 0, 0);
     char* cantEst = PQgetvalue(resCursoxPeriodo, 0, 5);
     int cantEstudiantes = atoi(cantEst);
     int idCursoXPeriodo = atoi(idCursoPeriodo );




     printf( "\n Ingrese la hora de inicio ");    
      char finicio[255];
     getchar();     
     scanf("%s",&finicio[0]);      
     printf( "\n Ingrese la hora de fin ");     
      char ffin[255];
     getchar();     
     scanf("%s",&ffin[0]) ;
     printf( "\n Ingrese la fecha (dd/mm/aaaa) ");     
      char fecha[255];
     getchar();     
     scanf("%s",&fecha[0]) ;
     printf( "\n Ingrese las aulas a reservar separadas por coma.");     
     printf( "\n Ejemplo: A1,A2,A3: ");    
     endl; 
     char aulas[500];
     //getchar();     
     scanf("%s",&aulas[0]);
     struct cadena au =split(aulas,',');    
     int rows = au.tamanio;
     char** totalAulas = au.lista;
     int sumatoriaCapacidad = 0; 
     for(int i = 0 ; i < rows; i ++){
          const char * paramValues2[1];
          paramValues2[0] =  totalAulas[i];

          char *stm = "select nombre, capacidad from aulas where nombre = $1";               
          PGresult *resAulas = PQexecParams(conn, stm, 1, NULL, paramValues2, NULL, NULL, 0);   
          int rows1 = PQntuples(resAulas);
          if(rows1<1){
               printf("Aula %s no existe",totalAulas[i]);
               return;
               break;
          }
          sumatoriaCapacidad+=atoi(PQgetvalue(resAulas, 0, 1));

           if (PQresultStatus(resAulas) != PGRES_COMMAND_OK) {
               fprintf(stderr, " Error: %s\n",PQerrorMessage(conn));
               //return;
               //break;

           } 
          char *  queryHorarios = "select aulaid from  reservacionxaula where reservacion.horainicio between $1"
          "and $2 or reservacion.horafin between $1 and $2 and $1 between reservacion.horaInicio and" 
          "reservacion.horaFin or $2 between horaInicio and horaFin and aulaid = $3"
          "inner join reservacion on reservacionxaula.reservacionid = reservacion.reservacionid";
          const char * paramValuesHorarios[3];
          paramValuesHorarios[0] = finicio;
          paramValuesHorarios[1] = ffin;
          paramValuesHorarios[2] = totalAulas[i];
          PGresult *resHorar = PQexecParams(conn, queryHorarios, 3, NULL, paramValuesHorarios, NULL, NULL, 0);   
          int rowsHor = PQntuples(resHorar);
          if(rowsHor>0 ){
              printf("El aula: %s presenta un choque de horario",totalAulas[i]);
              return;
             break;
           }
     }
     
     //Si la sumatoria de las aulas excede 10 estudiantes entonces no se puede
     if(sumatoriaCapacidad<cantEstudiantes ||sumatoriaCapacidad>cantEstudiantes+10){
               printf("La capacidad de las aulas no es válida a la capacidad de estudiantes");
               return ;
     }
     const char * paramValuesReserv[4];
     paramValuesReserv[0] = finicio;
     paramValuesReserv[1] = ffin;
     paramValuesReserv[2] = fecha;
     paramValuesReserv[3] = idCursoPeriodo;     
     char *stmRes = "Insert into reservacion values(default, $1,$2,$3,$4) RETURNING reservacionid";               
     PGresult *reserva = PQexecParams(conn, stmRes, 4, NULL, paramValuesReserv, NULL, NULL, 0);   
 
     char * idreserva = PQgetvalue(reserva, 0, 0);
     

     
     
     for(int i = 0 ; i < rows; i ++){
          const char * paramAulas2[2];
          paramAulas2[0] = idreserva;
          paramAulas2[1] = totalAulas[i];
          char *insertAulasxreserva = "Insert into reservacionxaula values(default,$1,$2)";
          PGresult* InsertResxAulas =PQexecParams(conn, insertAulasxreserva, 2, NULL, paramAulas2, NULL, NULL, 0);   
     }
     printf("Reservacion relizada con exito, identificador de la reservacion: %s",idreserva);
     
     
}
void cancelacionReserva(){

     PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
     printf( "\n Ingrese el identificador de la reserva ");    
     
      char idReserva1[255];
      getchar();     
     scanf("%s",&idReserva1[0]) ;
     
     const char * paramDelRes[1];
     paramDelRes[0] = idReserva1;
     const char * paramDelRes2[1];
     paramDelRes2[0] = idReserva1;
     
     
     char* delRes = "delete from reservacion where reservacionid = $1";
     char* delResAula =  "delete from reservacionxaula where reservacionid = $1";
     PGresult* deleteres =PQexecParams(conn, delResAula, 1, NULL, paramDelRes, NULL, NULL, 0); 
     
     if (PQresultStatus(deleteres) != PGRES_COMMAND_OK) {
               fprintf(stderr, " Error: %s\n","El identificador no pertenece a ninguna reservacion");
               return;

     }
     PQclear(deleteres);
     PGresult* deleteResAulas =PQexecParams(conn, delRes, 1, NULL, paramDelRes2, NULL, NULL, 0);   
     if (PQresultStatus(deleteResAulas) != PGRES_COMMAND_OK) {
               fprintf(stderr, " Error: %s\n","El identificador no pertenece a ninguna reservacion");
               return;

     }
     
     printf("La reserva con identificador %s ha sido eliminada", idReserva1);
     




}

void listarCursosxPeriodo(){
     char * stm = "Select codigocurso as \"Codigo de Curso\",periodo Periodo,annio \"Annio\",grupo \"Grupo\",profesores.nombre \"Nombre de profesor\",profesores.cedula \"Cedula del profesor\",cantestudiantes \"Cantidad de estudiantes\" from cursosxperiodo inner join profesores on profesores.cedula = cursosxperiodo.profesorid";    
     imprimeQuery(stm,7);     

}
void infoCursosxPeriodo(){
     int opcion;
     char repetir = TRUE;
      do
        {
        printf( "\n   -==[ Cursos por periodo ]==-");
        printf( "\n   1. Listar");
        printf( "\n   2. Incluir");
        printf( "\n   3. Eliminar");
        printf( "\n   4. Volver");
        printf( "\n\n   Introduzca opcion (1-4): ");

        scanf( "%d", &opcion );


        switch ( opcion )
        {
            case 1: 
                listarCursosxPeriodo();

                break;

            case 2: 
               incluirCursosxPeriodo();
                
                break;
            case 3:
               borrarProfes();
                break;
            case 4: 
               repetir = FALSE;
               break;

         }

    } while (repetir);

}

void stats(){
     PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
     printf("Top 3 aulas más reservadas: ");
     endl;
     char * stm1 = 
     "SELECT a.nombre \"Nombre de aula\", count(ra.reservacionid) \"Cantidad de reservaciones\" "
     " FROM aulas a"
     " INNER JOIN reservacionxaula ra ON ra.aulaid = a.nombre"
     " GROUP BY a.nombre"
     " ORDER BY count(ra.reservacionid) DESC";    
     imprimeQuery(stm1,2);
     endl;
     endl;
     printf("Top 3 profesores con más reservas:");
     endl;
     char * stm2 = 
     "SELECT p.nombre \"Nombre del profesor\",count(r.reservacionid) \"Cantidad de reservaciones\""
     " FROM profesores p"
     " INNER JOIN cursosxperiodo cp ON cp.profesorId = p.cedula"
     " INNER JOIN reservacion r ON r.cursoxperiodo = cp.cursoxperiodoid"
     " GROUP BY p.nombre"
     " ORDER BY count(r.reservacionid) DESC;";
     imprimeQuery(stm2,2);
     endl;
     endl;
     printf("Cantidad de reservacion por mes");
     endl;
     char * stm3 = "SELECT EXTRACT(MONTH FROM r.fecha) AS MES, EXTRACT(YEAR FROM r.fecha) AS Annio, count(r.reservacionid) \"Cantidad\""
     " FROM reservacion r"
     " INNER JOIN reservacionxaula ra ON ra.reservacionid = r.reservacionid"
     " GROUP BY EXTRACT(MONTH FROM r.fecha), EXTRACT(YEAR FROM r.fecha);";
     imprimeQuery(stm3,3);
     endl;
     endl;

}
void infoCursos(){
     char * stm = "Select codigocarrera \"Codigo de Carrera\", codigocurso \"Codigo de Curso\", nombre \"Nombre del curso\""
     " from Cursos";
     imprimeQuery(stm,3);
}
int menu_operativo() {
    
    int opcion2;

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

        scanf( "%d", &opcion2 );


        switch ( opcion2 )
        {
            case 1: 
                    infoAulas();
                    break;
                
            case 2: 
                    infoProfes();
                    break;
            case 3: 
                    infoCursos();
                    break;
            case 4: 
                    infoCursosxPeriodo();
                    break;
            case 5: 
                    infoReservas();
                    break;
            case 6: 
                    cancelacionReserva();
                    break;
            case 7: 
                    stats();
                    break;
         }

    } while ( opcion2 != 8 );
    return 0;
    
}


void consultaXdia() {
       PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");

        printf("Ingrese la fecha a consultar: ");
         char fecha[255];
        scanf(" %s",&fecha[0]);
        const char *  paramValues[1];
        paramValues[0] = fecha;
        
        char *stm = "SELECT a.nombre, r.reservacionid, cp.annio, cp.periodo, cp.codigoCurso, cp.grupo, r.horaInicio, r.horaFin FROM aulas a INNER JOIN reservacionxaula ra on ra.aulaid = a.nombre  INNER JOIN reservacion r on r.reservacionid = ra.reservacionid INNER JOIN cursosxperiodo cp on cp.cursoxperiodoid = r.cursoxperiodo WHERE r.fecha = $1";
        PGresult *res = PQexecParams(conn, stm, 1, NULL, paramValues, NULL, NULL, 0);   
        int rows = PQntuples(res);
        if(rows< 1){
                printf("\n   No hay ninguna aula reservada para esa fecha\n");
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

        PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
        printf("Ingrese el nombre del aula a consultar: ");

        char nombreAula[255];
        scanf(" %s",&nombreAula[0]);
        while(getchar() != '\n');
        const char *  paramValues[1];
     
        paramValues[0] = nombreAula;

        char *stm = "SELECT r.Fecha, r.horaInicio, r.horaFin, r.reservacionid, cp.annio, cp.periodo, cp.codigoCurso, cp.grupo FROM aulas a INNER JOIN reservacionxaula ra on ra.aulaid = a.nombre  INNER JOIN reservacion r on r.reservacionid = ra.reservacionid INNER JOIN cursosxperiodo cp on cp.cursoxperiodoid = r.cursoxperiodo WHERE a.nombre = $1 ORDER BY r.Fecha";
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

        PGconn *conn = PQconnectdb("dbname=prylg host=localhost user=postgres password=ricardo12345");
        
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
        
        char *stm = "SELECT cp.codigoCurso, r.Fecha, r.horaInicio, r.horaFin, a.Nombre FROM aulas a INNER JOIN reservacionxaula ra on ra.aulaid = a.nombre  INNER JOIN reservacion r on r.reservacionid = ra.reservacionid INNER JOIN cursosxperiodo cp on cp.cursoxperiodoid = r.cursoxperiodo WHERE cp.annio = $1 and  cp.periodo = $2 and cp.codigoCurso = $3 and cp.grupo = $4 ORDER BY r.Fecha, r.horaInicio, a.Nombre";
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

void menuGeneral() {
    
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
            case 1: 
                    consultaXdia();
                    break;
            case 2: 
                    consultaXaula();
                    break;
            case 3: 
                    consultaXcurso();
                    break;
         }

    } while ( opcion != 4 );

    


}



void menuPrincipal() {
        
        int opcion;
        char repetir = TRUE;
        
        do
        {
        printf( "\n   -==[ Gestion de aulas ]==-");
        printf( "\n   1. Opciones Operativas");
        printf( "\n   2. Opciones Generales");
        printf( "\n   3. Salir");
        printf( "\n\n   Introduzca opciocn (1-3): ");

        scanf( "%d", &opcion );


        switch ( opcion )
        {
            case 1: 
                menu_operativo();
                break;

            case 2: 
                menuGeneral();
                break;
            case 3:
                repetir = FALSE;

         }

    } while (repetir);
}

