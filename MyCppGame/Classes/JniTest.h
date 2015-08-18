//
//  JniTest.h
//  MyCppGame
//
//  Created by zgl on 14-8-11.
//
//

#ifndef __MyCppGame__JniTest__
#define __MyCppGame__JniTest__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
void setPackgaeName(const char* packageName)
{
    CCLOG("packageName:%s", packageName);
}

void exitApp()
{
    Director::getInstance()->end();
}

#endif /* defined(__MyCppGame__JniTest__) */
