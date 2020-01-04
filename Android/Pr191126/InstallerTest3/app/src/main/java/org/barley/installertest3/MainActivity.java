package org.barley.installertest3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.os.Bundle;
import android.util.Log;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MainActivity extends AppCompatActivity {

    private PackageEventReceiver mPackageEventReceiver = new PackageEventReceiver();

    public static Context ctx;
    public static Context getCtxApplication() {
        return ctx;
    }
    public String TAG = getClass().getSimpleName();
    public String packageName_received = "";
    public String appHash = "";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        registerPackageEventReceiver();
        // Intent intentFromPackageEventReceiver = getIntent();
        // packageName_received = intentFromPackageEventReceiver.getStringExtra("packageName");

    }

    private void registerPackageEventReceiver() {
        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction(Intent.ACTION_PACKAGE_ADDED);
        intentFilter.addAction(Intent.ACTION_PACKAGE_INSTALL);
        intentFilter.addDataScheme("package");
        registerReceiver(mPackageEventReceiver, intentFilter);
    }

}
