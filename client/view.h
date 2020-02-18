#pragma once
#include<stdlib.h>
#include<stddef.h>
#include<string>
#include<hiredis/hiredis.h>
#include<iostream>
#include"IM.User.Msg.pb.h"
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
#include<memory>
#include<map>
#include"pdu.h"
#include"log.h"
#include"cli_socket.h"

class View
{
public:
	View() {}
	virtual ~View() {};
	virtual bool Process() = 0;
};

class Register : public View
{
public:
	Register() {};
	bool Process();
};

class Login : public View
{
public:
	Login() {};
	bool Process();
};

class Exit : public View
{
public:
	Exit() {};
	bool Process();
};