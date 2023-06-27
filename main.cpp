#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <fcntl.h>
#include "User.h"
#include "Message.h"


namespace fs = std::filesystem;


int main() {
	
	fstream user_file = fstream("Users.txt", ios::in | ios::out);
	fstream mes_file = fstream("Messages.txt", ios::in | ios::out);

	std::cout << "Choose an action: \n\t 1. See messages, 2. Add messages, 3. See Users, 4. Add Users, 0. Exet" << std::endl;
	int choice;
	choice = 5;

	do {
		std::cin >> choice;
		switch (choice) {
		case 1:
			if (!mes_file) {
				std::cout << "There are no others messages yet" << std::endl;
			}
			else {
				if (mes_file.is_open()) {
					std::string line;
					mes_file.seekg(0, ios_base::beg);
					while (getline(mes_file, line)) {
						std::cout << line << std::endl;
					}
					mes_file.close();
				}
			}
			break;

		case 2:
			if (!mes_file) {
				mes_file = fstream("Messages.txt", ios::in | ios::out | ios::trunc);

				uid_t ID = getuid(void);
				gid_t DID = getgid(void);
				const char* path = "/home/loy/Prog/HW18/Messages.txt";
				int chown(const char* path, uid_t ID, gid_t GID);

				fs::permissions("Messages.txt",
					fs::perms::owner_all,
					fs::perm_options::add);
				fs::permissions("Messages.txt",
					fs::perms::group_all | fs::perms::others_all,
					fs::perm_options::remove);
			}
			if (mes_file.is_open()) {
				Message M1("I'm struggling, bro", "Alex", "Evgeny");
				mes_file << M1 << std::endl;
				mes_file.close();
			}
			else {
				std::cout << "Could not open file 'Messages.txt'!" << std::endl;
				return -1;
			}
			break;

		case 3:
			if (!user_file) {
				std::cout << "There are no others users yet" << std::endl;
			}
			else {
				if (user_file.is_open()) {
					std::string line;
					user_file.seekg(0, ios_base::beg);
					while (getline(user_file, line)) {
						std::cout << line << std::endl;
					}
					user_file.close();
				}
			}
			break;

		case 4:
			if (!user_file) {
				user_file = fstream("Users.txt", ios::in | ios::out | ios::trunc);

				uid_t ID = getuid(void);
				gid_t DID = getgid(void);
				const char* path = "/home/loy/Prog/HW18/Users.txt";
				int chown(const char* path, uid_t ID, gid_t GID);

				fs::permissions("Users.txt",
					fs::perms::owner_all,
					fs::perm_options::add);
				fs::permissions("Users.txt",
					fs::perms::group_all | fs::perms::others_all,
					fs::perm_options::remove);
			}
			if (user_file.is_open()) {
				User U1("Alex", "qwerty", "12345");
				user_file << U1 << std::endl;
				user_file.close();
			}
			else {
				std::cout << "Could not open file 'Users.txt'!" << std::endl;
				return -1;
			}
			break;

		default:
			std::cout << "Something is wrong" << std::endl;
			break;
		}
	} while (choice != 0);

    
    return 0;
}