package com.cfox.ndkdemo

import android.util.Log

class NativeInterface {

    companion object {
        private const val TAG = "NativeInterface"
        @JvmStatic
        external fun getStaticRegisterMethodString() : String
        @JvmStatic
        external fun getStaticMethodString() : String

        @JvmStatic
        fun jniCallStatic(code: Int) {
            Log.d(TAG, "jniCallStatic: code:>>> $code")
        }

    }

    external fun stringFromJNI(): String

    external fun getRegisterMethodString() : String

    fun jniCall(code : Int) {
        Log.d(TAG, "jniCall: code::>>> $code")
    }
}