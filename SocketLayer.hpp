//
//  SocketLayer.hpp
//  TestCocos2dx
//
//  Created by student on 16/4/7.
//
//

#ifndef SocketLayer_hpp
#define SocketLayer_hpp

#include <stdio.h>

#include "cocos2d.h"
using namespace cocos2d;

#include "network/WebSocket.h"
using namespace network;

class SocketLayer:public Layer,public network::WebSocket::Delegate
{
public:
    
    void onOpen(cocos2d::network::WebSocket *ws);
    void onMessage(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::Data &data);
    virtual void onClose(WebSocket* ws);
    virtual void onError(WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);
    
    void keepAlive(float dt);
    long currentTime;
};

#endif /* SocketLayer_hpp */
