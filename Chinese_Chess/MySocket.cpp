// MySocket.cpp : 实现文件
//


#include "Chinese_Chess.h"
#include "MySocket.h"




CMySocket::CMySocket()
{
}

CMySocket::~CMySocket()
{
}



void CMySocket::OnAccept( int nErrorCode )
{	
	::PostMessage(AfxGetMainWnd()->m_hWnd,WM_MYSOCKET,MS_ACCEPT,nErrorCode);
}

void CMySocket::OnConnect( int nErrorCode )
{	
	::PostMessage(AfxGetMainWnd()->m_hWnd,WM_MYSOCKET,MS_CONNECT,nErrorCode);
}

void CMySocket::OnReceive( int nErrorCode )
{	
	::PostMessage(AfxGetMainWnd()->m_hWnd,WM_MYSOCKET,MS_RECEIVE,nErrorCode);
}

void CMySocket::OnClose( int nErrorCode )
{	
	::PostMessage(AfxGetMainWnd()->m_hWnd,WM_MYSOCKET,MS_CLOSE,nErrorCode);
}
