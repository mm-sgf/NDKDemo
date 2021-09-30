package com.cfox.ndkdemo

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.cfox.ndkdemo.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private val nativeInterface = NativeInterface()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val stringBuffer = StringBuffer()
        stringBuffer.append(nativeInterface.stringFromJNI()).append("\n")
        stringBuffer.append(nativeInterface.getRegisterMethodString()).append("\n")
        stringBuffer.append(NativeInterface.getStaticMethodString()).append("\n")
        stringBuffer.append(NativeInterface.getStaticRegisterMethodString()).append("\n")
        stringBuffer.append(NativeOtherInterface.getStaticRegisterMethodString()).append("\n")

        binding.sampleText.text = stringBuffer.toString()
    }

    companion object {
        init {
            System.loadLibrary("ndkdemo")
        }
    }
}