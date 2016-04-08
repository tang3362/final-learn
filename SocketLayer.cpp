//
//  SocketLayer.cpp
//  TestCocos2dx
//
//  Created by student on 16/4/7.
//
//

#include "SocketLayer.hpp"
using namespace network;

using namespace std;

#define TIMEOUT 11000

long getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec*1000+tv.tv_usec/1000;
}

void SocketLayer::keepAlive(float dt)
{
    long time = getCurrentTime();
    log("time = %ld",time);
    if (time-currentTime>TIMEOUT) {
        log("请求超时");
    }
    else
    {
        log("连接正常");
//        _wsiSendText->send("timer");
    }
}

void SocketLayer::onOpen(cocos2d::network::WebSocket *ws)
{
    
}

void SocketLayer::onMessage(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::Data &data)
{
    if (!data.isBinary) {
        string textStr = string(data.bytes);
        sendTextStatus->setS
    }
}

void SocketLayer::onClose(WebSocket* ws)
{
    this->unscheduleAllCallbacks();
    if (ws == _wsiSendText) {
        _wsiSendText = NULL;
    }
    CC_SAFE_DELETE(ws);
}

void SocketLayer::onError(WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)
{
    log("error was friend , error code: %d",error);
    if (ws == _wsiSendText) {
        char buf[100] = {0};
        sprintf(buf, "an error was fired,code: %d",error);
        
    }
}











