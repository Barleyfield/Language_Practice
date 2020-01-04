package org.barley.installertest2;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.SystemClock;
import androidx.annotation.NonNull;
import android.util.Log;

import java.io.File;
import java.io.IOException;

public class TemporaryFileManager extends BroadcastReceiver {
    private static final String LOG_TAG = TemporaryFileManager.class.getSimpleName();

    /**
     * Create a new file to hold a staged file.
     *
     * @param context The context of the caller
     *
     * @return A new file
     */
    @NonNull
    public static File getStagedFile(@NonNull Context context) throws IOException {
        return File.createTempFile("package", ".apk", context.getNoBackupFilesDir());
    }

    /**
     * Get the file used to store the results of installs.
     *
     * @param context The context of the caller
     *
     * @return the file used to store the results of installs
     */
    @NonNull
    public static File getInstallStateFile(@NonNull Context context) {
        return new File(context.getNoBackupFilesDir(), "install_results.xml");
    }

    /**
     * Get the file used to store the results of uninstalls.
     *
     * @param context The context of the caller
     *
     * @return the file used to store the results of uninstalls
     */
    @NonNull
    public static File getUninstallStateFile(@NonNull Context context) {
        return new File(context.getNoBackupFilesDir(), "uninstall_results.xml");
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        long systemBootTime = System.currentTimeMillis() - SystemClock.elapsedRealtime();

        File[] filesOnBoot = context.getNoBackupFilesDir().listFiles();

        if (filesOnBoot == null) {
            return;
        }

        for (int i = 0; i < filesOnBoot.length; i++) {
            File fileOnBoot = filesOnBoot[i];

            if (systemBootTime > fileOnBoot.lastModified()) {
                boolean wasDeleted = fileOnBoot.delete();
                if (!wasDeleted) {
                    Log.w(LOG_TAG, "Could not delete " + fileOnBoot.getName() + " onBoot");
                }
            } else {
                Log.w(LOG_TAG, fileOnBoot.getName() + " was created before onBoot broadcast was "
                        + "received");
            }
        }
    }
}
