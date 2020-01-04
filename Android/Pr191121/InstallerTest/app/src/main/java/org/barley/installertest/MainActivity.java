package org.barley.installertest;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.FileProvider;

import android.Manifest;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.widget.Toast;

import com.gun0912.tedpermission.PermissionListener;
import com.gun0912.tedpermission.TedPermission;

import java.io.File;
import java.util.List;

import static android.content.Intent.FLAG_GRANT_READ_URI_PERMISSION;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ted();
    }

    /**
     * TedPermission으로 권한 부여
     */
    public void ted() {
        PermissionListener permissionListener = new PermissionListener() {
            @Override
            public void onPermissionGranted() {
                Toast.makeText(MainActivity.this, "권한이 부여되었습니다", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onPermissionDenied(List<String> arrayList) {
                Toast.makeText(MainActivity.this, MainActivity.this.getResources().getString(R.string.permission_denied), Toast.LENGTH_LONG).show();
            }
        };


        TedPermission.with(this).setPermissionListener(permissionListener)
                .setDeniedMessage(getResources().getString(R.string.permission_denied))
                .setPermissions(Manifest.permission.REQUEST_INSTALL_PACKAGES)
                .check();

    }
}
