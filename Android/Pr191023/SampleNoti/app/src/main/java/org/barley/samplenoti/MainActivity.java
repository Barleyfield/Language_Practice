package org.barley.samplenoti;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.Context;
import android.os.Build;
import android.os.Bundle;
import android.os.Vibrator;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    NotificationManager manager;
    private static String CHANNEL_ID = "channel1";
    private static String CHANNEL_NAME = "Channel1";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
           @Override
           public void onClick(View v) {
               showNoti1();
           }
        });
    }
    public void showNoti1() {
        manager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);

        NotificationCompat.Builder builder = null;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            org.barley.samplenoti.NotificationManager.createChannel(this);
            org.barley.samplenoti.NotificationManager.sendNotification(this, 1,
                    org.barley.samplenoti.NotificationManager.Channel.NOTICE,
                    "간단 알림", "알림 메시지입니다.");

        /*
            if (manager.getNotificationChannel(CHANNEL_ID) != null) {
                manager.createNotificationChannel(new NotificationChannel(
                        CHANNEL_ID, CHANNEL_NAME, NotificationManager.IMPORTANCE_DEFAULT
                ));

                builder = new NotificationCompat.Builder(this, CHANNEL_ID);
            }

        */
        } else {
            builder = new NotificationCompat.Builder(this);
            builder.setContentTitle("간단 알림");
            builder.setContentText("알림 메시지입니다.");
            builder.setSmallIcon(android.R.drawable.ic_menu_view);
            Notification noti = builder.build();

            manager.notify(1, noti);
            Vibrator vibrator = (Vibrator)getSystemService(Context.VIBRATOR_SERVICE);
            vibrator.vibrate(1000);
        }


    }

}
