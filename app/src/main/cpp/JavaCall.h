#ifndef NDKDEMO_JAVACALL_H
#define NDKDEMO_JAVACALL_H

#include <jni.h>

class JavaCall {


public:
    JavaCall();
    void getStringCall(JNIEnv *env, jobject thiz);

    void getStringStaticMethodCall(JNIEnv *env);

};


#endif //NDKDEMO_JAVACALL_H
