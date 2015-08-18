package org.cocos2dx.cpp;
import android.os.Handler;
import android.os.Message;
public class JniHelper{
	
	private static Handler mHandler;
	public static void init(Handler handler)
	{
		
		JniHelper.mHandler = handler;
	}
	
	//java 调用C++的方法 在JniTest.h中实现的
	public static native void setPackgaeName(String packageName);
	public static native void exitApp();
	
	//C++调用Java的方法
	private static void showTipDialog(final String title, final String text)
	{
		Message msg = mHandler.obtainMessage();
		msg.what = AppActivity.SHOW_DIALOG;
		DialogMessage dm = new DialogMessage();
		dm.title = title;
		dm.msg = text;
		msg.obj = dm;
		msg.sendToTarget();
	}
}