#include <iostream>
#include <libpq-fe.h>
#include <string>

void checkConnection(PGconn *conn) {
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        exit(1);
    }
}

PGconn* connectToDatabase() {
    // Hardcoded database credentials
    std::string dbName = "Pc_regestration";
    std::string dbUser = "postgres";
    std::string dbPassword = "YAB@340354y";
    std::string dbHost = "127.0.0.1";
    std::string dbPort = "5432";

    std::string conninfo = "host=" + dbHost +
                           " port=" + dbPort +
                           " dbname=" + dbName +
                           " user=" + dbUser +
                           " password=" + dbPassword;

    PGconn *conn = PQconnectdb(conninfo.c_str());
    checkConnection(conn);

    std::cout << "Connected to the database successfully." << std::endl;
    return conn;
}

void closeConnection(PGconn *conn) {
    PQfinish(conn);
    std::cout << "Database connection closed." << std::endl;
}
