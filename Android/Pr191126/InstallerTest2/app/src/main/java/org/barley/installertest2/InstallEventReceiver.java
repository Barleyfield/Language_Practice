package org.barley.installertest2;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

import androidx.annotation.NonNull;

public class InstallEventReceiver extends BroadcastReceiver {

    public String TAG = getClass().getSimpleName();
    private static final Object sLock = new Object();
    private static EventResultPersister sReceiver;
    /**
     * Get the event receiver persisting the results
     *
     * @return The event receiver.
     */
    @NonNull private static EventResultPersister getReceiver(@NonNull Context context) {
        synchronized (sLock) {
            if (sReceiver == null) {
                sReceiver = new EventResultPersister(
                        TemporaryFileManager.getInstallStateFile(context));
            }
        }
        Log.d("InstallEventReceiver: ", "sReceiver : " + sReceiver);
        return sReceiver;
    }
    @Override
    public void onReceive(Context context, Intent intent) {
        getReceiver(context).onEventReceived(context, intent);
        Log.d(TAG, "intent : " + intent);
        Log.d(TAG, "action : " + intent.getAction());
        Log.d(TAG, "data : " + intent.getData());

    }
    /**
     * Add an observer. If there is already an event for this id, call back inside of this call.
     *
     * @param context  A context of the current app
     * @param id       The id the observer is for or {@code GENERATE_NEW_ID} to generate a new one.
     * @param observer The observer to call back.
     *
     * @return The id for this event
     */
    static int addObserver(@NonNull Context context, int id,
                           @NonNull EventResultPersister.EventResultObserver observer)
            throws EventResultPersister.OutOfIdsException {
        return getReceiver(context).addObserver(id, observer);
    }
    /**
     * Remove a observer.
     *
     * @param context  A context of the current app
     * @param id The id the observer was added for
     */
    static void removeObserver(@NonNull Context context, int id) {
        getReceiver(context).removeObserver(id);
    }
}
