#include "DataWrite.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <memory>

using namespace std;

// ���� ����
const string server = "tcp://localhost:12333";
const string username = "root";
const string password = "Password12#";

void initializeDatabase() {
    try {
        sql::Driver* driver = get_driver_instance();
        unique_ptr<sql::Connection> con(driver->connect(server, username, password));
        con->setSchema("example_db");
    }
    catch (sql::SQLException& e) {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        exit(1);
    }
}

void createTable() {
    try {
        unique_ptr<sql::Connection> con(get_driver_instance()->connect(server, username, password));
        con->setSchema("example_db");
        unique_ptr<sql::Statement> stmt(con->createStatement());
        stmt->execute("DROP TABLE IF EXISTS inventory");
        stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
        cout << "Finished creating table" << endl;
    }
    catch (sql::SQLException& e) {
        cout << "Error in createTable: " << e.what() << endl;
    }
}

void insertData() {
    try {
        unique_ptr<sql::Connection> con(get_driver_instance()->connect(server, username, password));
        con->setSchema("example_db");
        unique_ptr<sql::PreparedStatement> pstmt;
        pstmt.reset(con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)"));
        pstmt->setString(1, "banana");
        pstmt->setInt(2, 150);
        pstmt->execute();
        // ... �߰����� ������ ���� ...
        cout << "Data insertion complete" << endl;
    }
    catch (sql::SQLException& e) {
        cout << "Error in insertData: " << e.what() << endl;
    }
}
