#include "cocos2d.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include "test.h"
#include "JniTest.h"

#define CLASS_NAME "org/cocos2dx/cpp/JniHelper"

using namespace cocos2d;

extern "C"
{
//确保这里的Java_org_cocos2dx_cpp_JniHelper_setPackgaeName中的函数名 与 JniHelper.java 中的native函数名一致
 void Java_org_cocos2dx_cpp_JniHelper_setPackgaeName(JNIEnv *env, jobject thisz, jstring packageName)
 {
	 const char* pkName = env->GetStringUTFChars(packageName, NULL);
	 setPackgaeName(pkName);   //java 调用的C++函数，实现在Class2s/JniTest.h中，不要写错函数名字哦
	 env->ReleaseStringUTFChars(packageName, pkName);
 }

 void Java_org_cocos2dx_cpp_JniHelper_exitApp(JNIEnv *env, jobject thisz, jstring packageName)
 {

	 exitApp();   //java 调用的C++函数，实现在Classss/JniTest.h中，不要写错函数名字哦

 }


 void showTipDialog(const char* title, const char* msg)
 {
	 JniMethodInfo t;

	 if( JniHelper::getStaticMethodInfo(t, CLASS_NAME, "showTipDialog", "(Ljava/lang/String;Ljava/lang/String;)V") )
	 {
		 jstring jTitle = t.env->NewStringUTF(title);
		 jstring jMsg = t.env->NewStringUTF(msg);
		 t.env->CallStaticVoidMethod(t.classID, t.methodID, jTitle, jMsg);
		 t.env->DeleteLocalRef(jTitle);
		 t.env->DeleteLocalRef(jMsg);
	 }

 }

}
