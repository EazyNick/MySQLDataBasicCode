#include "DataRead.h"

using namespace std;

int main() {
	const string server = "tcp://localhost:12333";
	const string username = "root";
	const string password = "Password12#";
	const string database = "example_db";

	readDataFromDB(server, username, password, database);

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

	con->setSchema("example_db");

	//select  
	pstmt = con->prepareStatement("SELECT * FROM inventory;");
	result = pstmt->executeQuery();

	while (result->next()) // ´ÙÀ½ ÇàÀ¸·Î ÀÌµ¿ °¡´ÉÇÑ µ¿¾È, ´õ ÀÌ»ó ÀÐÀ» ÇàÀÌ ¾øÀ» ¶§ false¸¦ ¹ÝÈ¯
		//ÀÎµ¦½º 1¹ø¤Š(2¹ø¤Š ¿­) °ªÀ» IntÇüÀ¸·Î ¹Þ¾Æ¿È, ÀÎµ¦½º 2¹ø¤Š °ªÀ» ¹®ÀÚ¿­ ÇüÅÂ·Î ¹Þ¾Æ¿È 
		printf("Reading from table=(%d, %s, %d)\n", result->getInt(1), result->getString(2).c_str(), result->getInt(3));

	delete result;
	delete pstmt;
	delete con;
	system("pause");

	return 0;
}
*/