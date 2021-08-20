#include <stdio.h>

int menu_operativo();
int menu_general();

int main()
{
    int opcion;

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
            case 1: menu_operativo();
                    break;
            case 2: menu_general();
                    break;
         }

    } while ( opcion != 3 );

    return 0;
}




int menu_operativo() {
    
    int opcion;

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

        scanf( "%d", &opcion );


        switch ( opcion )
        {
            case 1: 
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


int menu_general() {
    
    int opcion;

    do
    {
        printf( "\n   -==[ Menu General ]==-");
        printf( "\n   1. Consulta por dia");
        printf( "\n   2. Consulta por aula");
        printf( "\n   3. Consulta por curso");
        printf( "\n   4. Salir");
        printf( "\n\n   Introduzca opciocn (1-4): ");

        scanf( "%d", &opcion );


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