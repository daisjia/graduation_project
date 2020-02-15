#pragma once
#include<iostream>
#include<sys/socket.h>
#include <netinet/in.h>


#define REGISTER 1
#define LOGIN 2

typedef int result_t;
#define IM_OK 0
#define IM_ERROR -1



typedef struct PDUHEADtag
{
	unsigned _pack_len;	//���������ȵĵ�λ ����������==_pack_len + 65536 * _detail_info._pack_len_high;
	int _req_cmd;		//�����������
	int _rsp_code;	//������
	unsigned short _pack_len_high;	//������λ ����������==_pack_len + 65536 * _detail_info._pack_len_high;

	PDUHEADtag()
	{
		Clear();
	}

	void Clear()
	{
		_pack_len = 0;
		_req_cmd = 0;
		_rsp_code = 0;
		_pack_len_high = 0;
	}

	void SetPackLen(unsigned int pack_len)
	{
		_pack_len = htons(pack_len % 65536);
		_pack_len_high = htons(pack_len / 65536);
	}

	unsigned int GetPackLen()
	{
		return ntohs(_pack_len) + 65536 * ntohs(_pack_len_high);
	}

	int GetHeadLen()
	{
		return sizeof(PDUHEADtag);
	}

	char* GetBody()
	{
		return ((char*)this + GetHeadLen());
	}

	void SetCmd(short cmd)
	{
		_req_cmd = htons(cmd);
	}

	int GetCmd()
	{
		return ntohs(_req_cmd);
	}
}PDUHEAD;

int RecvN(int fd, void* buf, int count);

int SendN(int fd, const void* buf, int count);