package org.barley.immortalservicetest_retry;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.util.Log;

public class PackageInstallReceiver extends BroadcastReceiver {
    public String TAG = getClass().getSimpleName();

    @Override
    public void onReceive(Context context, Intent intent) {

        Uri fileUri = intent.getData();
        String packageName = intent.getData().getSchemeSpecificPart();
        String action = intent.getAction();

        if(action.equalsIgnoreCase(Intent.ACTION_PACKAGE_ADDED)) {
            Log.d(TAG, "Package ADDED : " + packageName);
            Log.d(TAG, "Package URI(?) : " + fileUri);
        } else if (action.equalsIgnoreCase(Intent.ACTION_PACKAGE_REPLACED)) {
            Log.d(TAG, "Package REPLACED : " + packageName);
            Log.d(TAG, "Package URI(?) : " + fileUri);
        }

        /*
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            Intent intentBackgroundService = new Intent(context, TestBackgroundService.class);
            context.startForegroundService(intentBackgroundService);
        } else {
            Intent intentBackgroundService = new Intent(context, TestBackgroundService.class);
            context.startService(intentBackgroundService);
        }

         */
    }
}
