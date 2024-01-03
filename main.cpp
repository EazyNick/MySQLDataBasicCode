#include "DataUpdate.h"

int main() {
	const string server = "tcp://localhost:12333";
	const string username = "root";
	const string password = "Password12#";
	const string database = "example_db";

	updateDataInDB(server, username, password, database);

	system("pause");

	return 0;
}

/*
#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
using namespace std;

//for demonstration only. never save your password in the code!
const string server = "tcp://localhost:12333";
const string username = "root";
const string password = "Password12#";

int main()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;

	try
	{
		driver = get_driver_instance();
		//for demonstration only. never save password in the code!
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	con->setSchema("example_db");

	//update
	pstmt = con->prepareStatement("UPDATE inventory SET quantity = ? WHERE name = ?");
	pstmt->setInt(1, 200);
	pstmt->setString(2, "banana");
	pstmt->executeQuery();
	printf("Row updated\n");

	delete con;
	delete pstmt;
	system("pause");
	return 0;
}
*/