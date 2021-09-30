#include "JavaCall.h"
#include <jni.h>
#define CLASS_NAME "com/cfox/ndkdemo/NativeInterface"
#define CLASS_NAME_OTHER "com/cfox/ndkdemo/NativeOtherInterface"

JavaCall::JavaCall() {

}

/**
 * 回调 java 对象中的方法
 * @param env ： jni 上下文
 * @param thiz ： java 对象
 */
void JavaCall::getStringCall(JNIEnv *env, jobject thiz) {

    jclass clazz = env->GetObjectClass(thiz);

    jmethodID callId = env->GetMethodID(clazz, "jniCall", "(I)V");
    env->CallVoidMethod(thiz, callId, 10);


}

/**
 * 调用Java中的静态方法
 * @param env
 */
void JavaCall::getStringStaticMethodCall(JNIEnv *env) {



    jclass clazz1 = env->FindClass(CLASS_NAME);
    jmethodID callId1 = env->GetStaticMethodID(clazz1, "jniCallStatic", "(I)V");
    env->CallStaticVoidMethod(clazz1, callId1, 20);


    jclass clazz2 = env->FindClass(CLASS_NAME);
    jmethodID callId2 = env->GetStaticMethodID(clazz1, "jniCallStatic", "(I)V");
    env->CallStaticVoidMethod(clazz2, callId2, 30);
}
