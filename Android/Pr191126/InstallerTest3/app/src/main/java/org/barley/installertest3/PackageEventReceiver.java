package org.barley.installertest3;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.net.Uri;
import android.util.Log;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.List;

public class PackageEventReceiver extends BroadcastReceiver {
    public String TAG = getClass().getSimpleName();
    public String sha256HashResult = null;
    // public Context packageEventReceiverCtx = MainActivity.getCtxApplication();
    public String appHash = "";


    @Override
    public void onReceive(Context context, Intent intent) {
        // String fileName = data.getData().getLastPathSegment();
        Uri fileUri = intent.getData();
        String packageName = intent.getData().getSchemeSpecificPart();
        String action = intent.getAction();

        if(action.equals(Intent.ACTION_PACKAGE_ADDED)) {
            Log.d(TAG, "Package ADDED : " + packageName);
            Log.d(TAG, "Package URI(?) : " + fileUri);
            // Intent intentOfPackageName = new Intent(context, MainActivity.class);
            // intentOfPackageName.putExtra("packageName", packageName);
            appHash = getSha256FromApk(context, packageName);
            Log.d(TAG, "App Hash Result (SHA-256) : " + appHash);
        } else if(action.equals(Intent.ACTION_PACKAGE_REMOVED)) {
            Log.d(TAG, "Package REMOVED : " + packageName);
        }
    }

    /*
        getSha256FromApk
        설치된 앱의 apk 파일 경로 (PackageInfo.applicationInfo.sourceDir)에 있는 apk 파일의
        SHA-256 해시를 구해 반환한다.
    */
    public String getSha256FromApk (Context context, String pkg) {
        try {
            PackageInfo packageInfo = context.getPackageManager().getPackageInfo(pkg, PackageManager.GET_SIGNATURES);
            String sha256HashResult = fileToSHA256(packageInfo.applicationInfo.sourceDir);
            // Log.d(TAG, "App's SHA-256 : " + fileToSHA256(packageInfo.applicationInfo.sourceDir));
            return sha256HashResult;
        } catch (Exception e) {
            e.printStackTrace();
            Log.e("PackageEventReceiver", "Error in getSingInfo", e);
        }
        return "";
    }


    /*
        fileToSHA256
        파일 경로를 매개 변수로 받아서 경로 내에 있는 파일의 SHA-256 해시를
        구해 반환한다.
    */
    public static String fileToSHA256(String filePath) {
        InputStream inputStream = null;
        try {
            inputStream = new FileInputStream(filePath);
            byte[] buffer = new byte[1024];
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            int numRead = 0;
            while (numRead != -1) {
                numRead = inputStream.read(buffer);
                if (numRead > 0)
                    digest.update(buffer, 0, numRead);
            }
            byte[] sha256Bytes = digest.digest();
            return convertHashToString(sha256Bytes);
        } catch (Exception e) {
            return null;
        } finally {
            if (inputStream != null) {
                try {
                    inputStream.close();
                } catch (Exception e) { }
            }
        }
    }

    private static String convertHashToString(byte[] md5Bytes) {
        String returnVal = "";
        for (int i = 0; i < md5Bytes.length; i++) {
            returnVal += Integer.toString(( md5Bytes[i] & 0xff ) + 0x100, 16).substring(1);
        }
        return returnVal.toUpperCase();
    }
}
