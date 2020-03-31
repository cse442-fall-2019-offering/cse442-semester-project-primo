// MySocket.h : header file
//
//�����ͨ�ã�ͨ����Ϣ����������ĺ�����û��ֱ�ӹ���
#include "afxsock.h"
#pragma once

//�ɵ����ߴ�����Զ�����Ϣ
#define WM_MYSOCKET	(WM_USER+10)
#define MS_ACCEPT	0
#define MS_CONNECT	1
#define MS_RECEIVE	2
#define MS_CLOSE	3

// CMySocket ����ͨ����

class CMySocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CMySocket();
	virtual ~CMySocket();

// Implementation
protected: //��д�ɿ�ܵ��õ���Ϣ��Ӧ����
	virtual void OnAccept( int nErrorCode );
	virtual void OnConnect( int nErrorCode );
	virtual void OnReceive( int nErrorCode );
	virtual void OnClose( int nErrorCode );
};