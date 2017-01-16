#include "Client.h"
#include "ImPduBase.h"
#include "IM.Login.pb.h"

using namespace IM::Login;

uint32_t CClient::login(const string& strName,const string& strPass){
	CImPdu cPdu;
	IM::Login::IMLoginReq msg;
	msg.set_user_name(strName);
	msg.set_password(strPass);
	msg.set_online_status(IM::BaseDefine::USER_STATUS_ONLINE);
	msg.set_client_type(IM::BaseDefine::CLIENT_TYPE_WINDOWS);
	msg.set_client_version("1.0");

	cPdu.SetPBMsg(&msg);

	return 0;
}
uint32_t CClient::connect(const string & strIp,uint16_t nPort){
	m_handle = netlib_connect(strIp.c_str(),nPort,imconn_callback,NULL);
	string name = "test_name";
	string pass = "test_pass";
	login(name,pass);
	return m_handle;		
}
