package org.cocos2dx.cpp;
import android.os.Handler;
import android.os.Message;
public class JniHelper{
	
	private static Handler mHandler;
	public static void init(Handler handler)
	{
		
		JniHelper.mHandler = handler;
	}
	
	//java ����C++�ķ��� ��JniTest.h��ʵ�ֵ�
	public static native void setPackgaeName(String packageName);
	public static native void exitApp();
	
	//C++����Java�ķ���
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