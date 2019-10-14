package org.barley.simplelayoutinflater;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.text.Layout;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.LinearLayout;

public class MenuActivity extends AppCompatActivity {

    // 전체 레이아웃(activity_main.xml의 안쪽 LinearLayout의 id
    LinearLayout container;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        /*
         안쪽 LinearLayout을 참조하기 위해서 findViewById 사용
         container 변수에 할당
         이렇게 하면 버튼 클릭 시 호출되는 onClick() 안에서
         container 변수 참조 가능
         */
        container = findViewById(R.id.container);

        Button button = findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
           @Override
           public void onClick(View view) {
               // getSystemService 메서드를 사용해 LayoutInflater 객체 참조
               LayoutInflater inflater = (LayoutInflater)getSystemService(Context.LAYOUT_INFLATER_SERVICE);

               /*
                 참조한 inflater의 inflate() 메서드로 R.layout.sub1, container 객체 전달
                 container를 id로 갖는 LinearLay
                */
               inflater.inflate(R.layout.sub1, container, true);
               CheckBox checkBox = container.findViewById(R.id.checkBox);
               checkBox.setText("로딩되었어요");
           }
        });
    }
}
