package org.barley.immortalservicetest;

import android.app.Notification;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.IBinder;
import androidx.annotation.Nullable;
import androidx.core.app.NotificationCompat;
import android.util.Log;
import android.widget.Toast;

public class TestBackgroundService extends Service {
    private int a = 0;
    public Context testBackgroundServiceCtx = MainActivity.getCtxApplication();
    public String TAG = getClass().getSimpleName();

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {
        super.onCreate();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        if (intent.getAction().equals("Action1")) {
            Log.i("onStartCommand-Action1", "---서비스 스타트--- ");

            Intent notificationIntent = new Intent(this, MainActivity.class);
            notificationIntent.setAction("Action2");

            PendingIntent pendingIntent = PendingIntent.getActivity(this, 0,
                    notificationIntent, 0);

            Bitmap icon = BitmapFactory.decodeResource(getResources(),
                    R.mipmap.ic_launcher_round);

            Notification notification = new NotificationCompat.Builder(this, "channel1")
                    .setContentTitle("background machine")
                    .setTicker("측정중... ")
                    .setContentText("백그라운드 동작중")
                    .setSmallIcon(R.mipmap.ic_launcher_round)
                    .setContentIntent(pendingIntent)
                    .setOngoing(true).build();

            startForeground(111, notification);

            // -- Task --
            //Toast.makeText(testBackgroundServiceCtx, "백그라운드 서비스가 실행되었습니다.", Toast.LENGTH_LONG).show();

            // ----------

            // Thread로 처리
            Thread bt = new Thread(new Runnable() {
                @Override
                public void run() {
                    while(true){
                        try {
                            Thread.sleep(2000);
                        } catch(InterruptedException e) {
                            e.printStackTrace();
                        }
                        if(!MainActivity.TFLAG){
                            Log.i(TAG, "TestBackgroundService.java Thread test");
                            Log.i("background-counter","---백스레드 중지---");
                            break;
                        }

                        Log.i("background-counter",String.valueOf(++a));
                    }
                }
            });
            bt.setName("백그라운드스레드");
            bt.start();

        } else if(intent.getAction().equals("Action2")) {

        }



        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        super.onDestroy();

        MainActivity.TFLAG = false;
        Log.i("SERVICE TAG ", "==== 서비스 destroyed ===");

    }
}


