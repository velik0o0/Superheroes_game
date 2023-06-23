#pragma once
using namespace std;
#pragma warning (disable:4996)

class User
{
protected:
	char* name = nullptr;
	char* email = nullptr;
	char* username = nullptr;
	char* password = nullptr;

	void copyFrom(const User& other);
	void free();
	void moveFrom(User&& other);

public:

	User() = default;
	User(const char* name, const char* email, const char* username, const char* password);

	User(const User& other);
	User& operator=(const User& other);

	User(User&& other);
	User& operator=(User&& other);

	const char* getName() const;
	const char* getEmail() const;
	const char* getUsername() const;
	const char* getPassword() const;

	~User();
	void print() const;

protected:
	void setName(const char* name);
	void setEmail(const char* name);
	void setUsername(const char* name);
	void setPassword(const char* name);
};
