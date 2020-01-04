package org.barley.installertest;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.util.Log;
import android.widget.Toast;

import androidx.core.content.FileProvider;

import java.io.File;

import static android.content.Intent.FLAG_GRANT_READ_URI_PERMISSION;

public class PackageEventReceiver extends BroadcastReceiver {
    public String TAG = getClass().getSimpleName();

    @Override
    public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();

        Log.d(TAG, "intent : " + intent);
        Log.d(TAG, "action : " + action);
        Log.d(TAG, "data : " + intent.getData());

    }
}
