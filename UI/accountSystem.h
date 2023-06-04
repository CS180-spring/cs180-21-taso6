#ifndef ACCOUNTSYSTEM_H
#define ACCOUNTSYSTEM_H
#include "Initialize.h"
#include <fstream>

void login(Database curData);
void forgot();
void registration(Database curData, string username, string password);
void delete_file(Database curData);
void create_file(Database curData);
bool canLogin(Database curData, string username, string password);

#endif