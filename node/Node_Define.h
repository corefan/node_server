/*
 * Node_Define.h
 *
 *  Created on: Sep 20, 2016
 *      Author: zhangyalei
 */

#ifndef Node_DEFINE_H_
#define Node_DEFINE_H_

#include <vector>
#include "Base_Define.h"
#include "Time_Value.h"

enum Msg_Type {
	C2S 		= 1,		//客户端发到服务器的消息
	S2C			= 2,		//服务器发到客户端的消息
	NODE_C2S	= 3,	//客户端经过gate中转发到后端服务器的消息
	NODE_S2C	= 4,	//后端服务器经过gate中转发到gate的消息
	NODE_MSG	= 5,	//服务器进程节点间通信的消息
};

enum Node_Type {
	DB_SERVER = 1,
	LOG_SERVER = 2,
	CENTER_SERVER = 3,
	PUBLIC_SERVER = 4,
	GAME_SERVER = 5,
	GATE_SERVER = 6,
};

struct Session {
	int gate_endpoint;			//client连接的gate endpoint_id
	int game_endpoint;			//与game_server连接的endpoint_id
	int public_endpoint;		//与public_server连接的endpoint_id
	int cid;								//client与gate连接的cid
	int sid;								//gate生成的全局唯一session_id
};

struct Drop_Info {
	int endpoint_id;
	int cid;
	Time_Value drop_time;

	Drop_Info(void) : endpoint_id(0), cid(-1), drop_time(Time_Value::gettimeofday()) {}
};

typedef std::vector<Endpoint_Info> Endpoint_List;
struct Node_Info {
	int node_type;							//节点类型
	int node_id;								//节点id
	std::string node_name;			//节点名称
	std::string script_path;	//启动的js脚本路径
	std::vector<std::string> plugin_list; 	//插件列表
	Endpoint_List server_list;							//服务器线程列表
	Endpoint_List connector_list;						//链接器线程列表
};

typedef std::vector<Node_Info> Node_List;
struct Node_Conf {
	Node_List node_list;

	void init(void);
};

#endif /* Node_DEFINE_H_ */
