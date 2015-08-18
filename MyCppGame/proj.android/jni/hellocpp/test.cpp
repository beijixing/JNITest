#include "cocos2d.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include "test.h"
#include "JniTest.h"

#define CLASS_NAME "org/cocos2dx/cpp/JniHelper"

using namespace cocos2d;

extern "C"
{
//ȷ�������Java_org_cocos2dx_cpp_JniHelper_setPackgaeName�еĺ����� �� JniHelper.java �е�native������һ��
 void Java_org_cocos2dx_cpp_JniHelper_setPackgaeName(JNIEnv *env, jobject thisz, jstring packageName)
 {
	 const char* pkName = env->GetStringUTFChars(packageName, NULL);
	 setPackgaeName(pkName);   //java ���õ�C++������ʵ����Class2s/JniTest.h�У���Ҫд��������Ŷ
	 env->ReleaseStringUTFChars(packageName, pkName);
 }

 void Java_org_cocos2dx_cpp_JniHelper_exitApp(JNIEnv *env, jobject thisz, jstring packageName)
 {

	 exitApp();   //java ���õ�C++������ʵ����Classss/JniTest.h�У���Ҫд��������Ŷ

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
