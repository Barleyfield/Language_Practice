package org.barley.immortalservicetest;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    public static boolean TFLAG = false;

    // 어디서나 MainActivity의 Context 사용하기
    public static Context ctx;
    public static Context getCtxApplication() {
        return ctx;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        NotificationManager notificationManager = (NotificationManager)getSystemService(Context.NOTIFICATION_SERVICE);
        NotificationChannel notificationChannel = new NotificationChannel("channel1", "1번채널", NotificationManager.IMPORTANCE_NONE);
        notificationChannel.setDescription("1번채널입니다");
        notificationChannel.enableLights(true);
        notificationChannel.setLightColor(Color.GREEN);
        notificationChannel.enableVibration(false);
        notificationChannel.setVibrationPattern(new long[]{100, 200, 100, 200});
        notificationChannel.setLockscreenVisibility(Notification.VISIBILITY_PRIVATE);
        notificationManager.createNotificationChannel(notificationChannel);

        TFLAG = true;
        Intent backStartIntent = new Intent(MainActivity.this, TestBackgroundService.class);
        backStartIntent.setAction("Action1");
        startForegroundService(backStartIntent);

    }
}

