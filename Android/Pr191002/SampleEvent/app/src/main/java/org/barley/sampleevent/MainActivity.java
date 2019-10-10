package org.barley.sampleevent;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.TextView;
import android.view.GestureDetector;
import android.view.KeyEvent;
import android.widget.Toast;


/**
 * @mainpage SampleEvent Project
 * Introduction to SampleEvent Project and studying doxygen
 */


///@brief MainActivity
public class MainActivity extends AppCompatActivity {
    TextView textView;
    GestureDetector detector;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView);


        /* 화면 위쪽에 배치한 View를 findViewById() 메서드로 찾아 참조한 후
         * setOnTouchListener() 메서드를 호출하여 리스너를 등록
         */
        View view = findViewById(R.id.view);


        /* setOnTouchListener 호출 시 OnTouchListener 객체를 생성하면서 전달
         * (파라미터로 리스너 객체를 전달)
         * onTouch() 메서드 : MotionEvent 객체가 파라미터로 전달.
         */
        view.setOnTouchListener(new View.OnTouchListener() {
            /* onTouch() 메서드는 MotionEvent 객체가 파라미터로 전달
             * (MotionEvent : 액션 정보, 터치한 곳의 좌표 들어 있음)
             * getAction() : 손가락이 눌렸거나, 눌린 상태로 움직이거나, 떼졌을 때의 상태 알 수 있음
             * (정수 자료형 값 반환)
             */
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                int action = motionEvent.getAction();

                float curX = motionEvent.getX();
                float curY = motionEvent.getY();

                if(action == MotionEvent.ACTION_DOWN) { // 손가락이 눌렸을 때
                    println("손가락 눌림 : " + curX + ", " + curY);
                } else if (action == MotionEvent.ACTION_MOVE) { // 손가락이 눌린 상태로 움직일 때
                    println("손가락 움직임 : " + curX + ", " + curY);
                } else if (action == MotionEvent.ACTION_UP) { // 손가락이 떼졌을 때
                    println("손가락 뗌 : " + curX + ", " + curY);
                }
                return true;
            }
        });

        detector = new GestureDetector(this, new GestureDetector.OnGestureListener() {

            @Override
            public boolean onDown(MotionEvent motionEvent) {
                println("onDown() 호출됨.");
                return true;
            }

            @Override
            public void onShowPress(MotionEvent motionEvent) {
                println("onShowPress() 호출됨.");
            }

            @Override
            public boolean onSingleTapUp(MotionEvent motionEvent) {
                println("onSingleTapUp() 호출됨.");
                return true;
            }

            @Override
            public boolean onScroll(MotionEvent motionEvent, MotionEvent motionEvent1, float v, float v1) {
                println("onScroll() 호출됨 : " + v + ", " + v1);
                return true;
            }

            @Override
            public void onLongPress(MotionEvent motionEvent) {
                println("onLongPress() 호출됨.");
            }

            @Override
            public boolean onFling(MotionEvent motionEvent, MotionEvent motionEvent1, float v, float v1) {
                println("onFling() 호출됨 : " + v + ", " + v1);
                return true;
            }

        });

        View view2 = findViewById(R.id.view2);
        view2.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                detector.onTouchEvent(motionEvent);
                return true;
            }
        });

    }

    // 텍스트뷰에 글자 추가하면서 보여주는 메서드
    public void println(String data) {
        textView.append(data + "\n");
    }

    /* onKeyDown() 메서드로 KEYCODE_BACK 이벤트를 확인하면
     * 토스트 메시지 표시
     */
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if(keyCode == KeyEvent.KEYCODE_BACK) {
            Toast.makeText(this, "시스템 Back 버튼이 눌렸습니다", Toast.LENGTH_LONG).show();
            return true;
        }
        return false;
    }
}
