package org.barley.broadcastreceiverforbackgroundservicetest;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

public class BackgroundService extends Service {
    public boolean isRunning;
    public Context context;
    public Thread backgroundThread;
    public String TAG = getClass().getSimpleName();

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {
        this.context = this;
        this.isRunning = false;
        this.backgroundThread = new Thread(myTask);
        Log.d(TAG, "onCreate");
    }

    @Override
    public void onDestroy() {
        this.isRunning = false;
        Log.d(TAG, "onDestroy");
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        if(!this.isRunning) {
            this.isRunning = true;
            this.backgroundThread.start();
        }
        Log.d(TAG, "onStartCommand");
        return START_STICKY;
    }

    private Runnable myTask = new Runnable() {
        public void run() {
            // Do Something here
            Log.d(TAG, "myTask executing");
            stopSelf();
        }
    };

}
