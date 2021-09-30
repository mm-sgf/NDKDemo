#include <jni.h>
#include <string>
#include "JavaCall.h"

#define CLASS_NAME "com/cfox/ndkdemo/NativeInterface"
#define CLASS_NAME_OTHER "com/cfox/ndkdemo/NativeOtherInterface"

JavaCall *p_java_call = new JavaCall();


//JavaCall * getCallHandler() {
//    if (p_java_call) {
//        return p_java_call;
//    } else {
//        p_java_call = new JavaCall();
//        return p_java_call;
//    }
//}

/**
 * 静态注册方式
 *
 * 对象中native 方法， 带有jobject 对象参数
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_cfox_ndkdemo_NativeInterface_stringFromJNI(JNIEnv *env, jobject thiz) {
    if (p_java_call) {
        p_java_call->getStringCall(env, thiz);
        p_java_call->getStringStaticMethodCall(env);
    }
    std::string hello = "get String from object";
    return env->NewStringUTF(hello.c_str());
}

/**
 * 静态注册方式
 *
 * class 中 native 方法(static 修饰的方法)，带有 jclass
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_cfox_ndkdemo_NativeInterface_getStaticMethodString(JNIEnv *env, jclass clazz) {
    std::string hello = "get String from class";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
registerMethodString(JNIEnv *env, jobject thiz) {
    std::string hello = "register method get string  from";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
staticRegisterMethodString(JNIEnv *env, jobject thiz) {
    std::string hello = "register method static get string  from";
    return env->NewStringUTF(hello.c_str());
}


/**
 * 添加java  和 native 方法映射
 */
static JNINativeMethod nativeMethods[] = {
        "getRegisterMethodString", "()Ljava/lang/String;", (void *) registerMethodString,
        "getStaticRegisterMethodString", "()Ljava/lang/String;", (void *) staticRegisterMethodString
};

static JNINativeMethod nativeOtherMethods[] = {
        "getStaticRegisterMethodString", "()Ljava/lang/String;", (void *) staticRegisterMethodString
};



static int registerNativeMethods(JNIEnv *env, const char *className , JNINativeMethod *nativeMethod, int numMethod) {

    jclass clazz;
    // 在 java 虚拟机中查找对应class
    clazz = env->FindClass(className);
    if (clazz == nullptr) {
        return JNI_FALSE;
    }

    // 加入映射
    if (env->RegisterNatives(clazz, nativeMethod, numMethod) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

static int registerNatives(JNIEnv *env) {
    if (!registerNativeMethods(env, CLASS_NAME, nativeMethods, sizeof(nativeMethods) / sizeof (nativeMethods[0]))) {
        return JNI_FALSE;
    }
    if (!registerNativeMethods(env, CLASS_NAME_OTHER, nativeOtherMethods, sizeof(nativeOtherMethods) / sizeof (nativeOtherMethods[0]))) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

JNIEXPORT int JNICALL JNI_OnLoad(JavaVM *vm,void *reserved) {
    jint jniRet = JNI_ERR;
    JNIEnv *env = nullptr;
    // 获取jni 上下文 JNIEnv
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return jniRet;
    }

    assert(env != nullptr);

    if (!registerNatives(env)) {
        return jniRet;
    }
    jniRet = JNI_VERSION_1_6;
    return jniRet;

}


