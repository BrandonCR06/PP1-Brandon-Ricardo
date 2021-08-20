#include <stdio.h>
#include "libpq-fe.h"
#include <stdlib.h>
int main(){
PGconn *conn = PQconnectdb("dbname=pryLG host=localhost user=ricardosoto password=ricardo12345");

    if (PQstatus(conn) == CONNECTION_BAD) {
        
        fprintf(stderr, "Connection to database failed: %s\n",PQerrorMessage(conn));
        
    }

    int ver = PQserverVersion(conn);

    printf("Server version: %d\n", ver);
    
    PQfinish(conn);

    return 0;

}