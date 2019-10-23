package org.barley.servicecomponentpractice;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class PhoneCallActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_phone_call);

        Button btnStart = findViewById(R.id.btn_service_start);
        Button btnEnd = findViewById(R.id.btn_service_end);
        btnStart.setOnClickListener(new View.OnClickListener() {
           public void onClick(View v) {
               // 서비스 시작하기
               // 매개 변수 : Activity content, 이동할 서비스 객체
               Intent intent = new Intent(
                       getApplicationContext(),
                       PhoneCallService.class);
               startService(intent);
           }
        });

        btnEnd.setOnClickListener(new View.OnClickListener() {
           public void onClick(View v) {
               // 서비스 종료하기
               Intent intent = new Intent(
                       getApplicationContext(),
                       PhoneCallService.class );
               stopService(intent);
           }
        });
    }
}
