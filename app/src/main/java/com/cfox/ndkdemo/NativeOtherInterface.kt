package com.cfox.ndkdemo

import android.util.Log

class NativeOtherInterface {

    companion object {
        private const val TAG = "NativeOtherInterface"
        @JvmStatic
        external fun getStaticRegisterMethodString() : String

        @JvmStatic
        fun jniCallStatic(code: Int) {
            Log.d(TAG, "jniCallStatic: code:>>> $code")
        }
    }

}