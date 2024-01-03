#include "DataDelete.h"

int main() {
	const std::string server = "tcp://localhost:12333";
	const std::string username = "root";
	const std::string password = "Password12#";
	const std::string database = "example_db";

	deleteDataFromDB(server, username, password, database);

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
const string database = "example_db";

int main()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

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

	con->setSchema(database);

	//delete
	pstmt = con->prepareStatement("DELETE FROM inventory WHERE name = ?");
	pstmt->setString(1, "orange");
	result = pstmt->executeQuery();
	printf("Row deleted\n");

	delete pstmt;
	delete con;
	delete result;

	system("pause");

	return 0;
}
*/