#include "DataWrite.h"

int main() {

	// 전역 변수
	const string server = "tcp://localhost:12333";
	const string username = "root";
	const string password = "Password12#";
	const string database = "example_db";

	initializeDatabase(server, username, password, database);
	createTable(server, username, password, database);
	insertData(server, username, password, database);

	return 0;
}


/*
#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

//for demonstration only. never save your password in the code!
const string server = "tcp://localhost:12333";
const string username = "root";
const string password = "Password12#";

int main()
{
	// MySQL 데이터베이스에 연결하기 위한 변수를 선언
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;

	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e) // sql::SQLException e 예외를 잡아냄.
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause"); // 일시 정지
		exit(1); // 종료
	}

	//please create database "example_db" ahead of time
	con->setSchema("example_db");

	{
		std::unique_ptr<sql::Statement> stmt(con->createStatement());
		stmt->execute("DROP TABLE IF EXISTS inventory");
		cout << "Finished dropping table (if existed)" << endl;

		//데이터베이스 테이블 내에서 각 행(row)을 고유하게 식별하기 위한 열(column)을 정의
		//id: 열의 이름, 행을 구분하는데 사용
		//serial은 자동 증가(auto-increment) 정수
		//id 열이 테이블의 기본 키(primary key)임을 나타냄, 고유하게 식별하는 역할
		//기본 키로 지정된 열에는 중복된 값이 들어갈 수 없으며, NULL 값도 허용되지 않습니다. 기본 키는 데이터의 무결성을 유지하고,
		//데이터베이스 내에서 행을 효율적으로 찾기 위한 인덱스로도 사용
		stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
		cout << "Finished creating table" << endl;
		// unique_ptr는 스코프를 벗어나면서 자동으로 stmt 객체를 삭제합니다.
	}

	// prepareStatement는 SQL 명령 대기, name - ?, quantity - ? 매칭
	pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
	//setString 함수는 첫 번째 플레이스홀더(?)에 문자열 값을 바인딩합니다.
	//여기서 1은 첫 번째 플레이스홀더(VALUES(?,?)의 인덱스를 나타내고, "banana"는 name 필드에 삽입될 값입니다.
	pstmt->setString(1, "banana");
	//setInt 함수는 두 번째 플레이스홀더(VALUES(?,?)에 정수 값을 바인딩
	pstmt->setInt(2, 150);
	pstmt->execute();
	cout << "banana One row inserted." << endl;

	pstmt->setString(1, "orange");
	pstmt->setInt(2, 154);
	pstmt->execute();
	cout << "orange One row inserted." << endl;

	pstmt->setString(1, "apple");
	pstmt->setInt(2, 100);
	pstmt->execute();
	cout << "apple One row inserted." << endl;

	delete pstmt;
	delete con;
	system("pause");
	return 0;
}
*/