package org.barley.samplenoti;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationChannelGroup;
import android.content.Context;
import android.graphics.Color;
import android.os.VibrationEffect;
import android.os.Vibrator;
import androidx.annotation.StringDef;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

public class NotificationManager {
    private static final String GROUP_NOTI = "group_noti";

    public static void createChannel(Context context) {
        NotificationChannelGroup group1 = new NotificationChannelGroup(GROUP_NOTI, GROUP_NOTI);
        getManager(context).createNotificationChannelGroup(group1);

        NotificationChannel channelNotice = new NotificationChannel(Channel.NOTICE,
                "Notice", android.app.NotificationManager.IMPORTANCE_HIGH);
        channelNotice.setGroup(GROUP_NOTI);
        channelNotice.setDescription("공지사항 형태의 알림 전송. 푸시 알림과 함께 팝업으로도 알림이 뜬다.");
        channelNotice.setLockscreenVisibility(Notification.VISIBILITY_PUBLIC);
        getManager(context).createNotificationChannel(channelNotice);
    }

    private static android.app.NotificationManager getManager(Context context) {
        return (android.app.NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
    }

    public static void deleteChannel(Context context, @Channel String channel) {
        getManager(context).deleteNotificationChannel(channel);

    }

    public static void sendNotification(Context context, int id, @Channel String channel, String title, String body) {
        Notification.Builder builder = new Notification.Builder(context, channel)
                .setContentTitle(title)
                .setContentText(body)
                .setSmallIcon(getSmallIcon())
                .setAutoCancel(true);
        getManager(context).notify(id, builder.build());

        Vibrator vibrator = (Vibrator)context.getSystemService(Context.VIBRATOR_SERVICE);
        vibrator.vibrate(VibrationEffect.createOneShot(2000, VibrationEffect.DEFAULT_AMPLITUDE));
    }

    private static int getSmallIcon() {
        return android.R.drawable.stat_notify_chat;
    }

    @Retention(RetentionPolicy.SOURCE)
    @StringDef({
            Channel.MESSAGE,
            Channel.COMMENT,
            Channel.NOTICE
    })
    public @interface Channel {
        String MESSAGE = "message";
        String COMMENT = "comment";
        String NOTICE = "notice";
    }

}
