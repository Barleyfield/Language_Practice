package org.barley.sampletab2_book_ver;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.MenuItem;
import android.widget.Toast;

import com.google.android.material.bottomnavigation.BottomNavigationView;

public class MainActivity extends AppCompatActivity {

    Fragment1 fragment1;
    Fragment2 fragment2;
    Fragment3 fragment3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fragment1 = new Fragment1();
        fragment2 = new Fragment2();
        fragment3 = new Fragment3();

        getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment1).commit();

        BottomNavigationView bottomNavigation = findViewById(R.id.bottom_navigation);
        bottomNavigation.setOnNavigationItemSelectedListener(
                new BottomNavigationView.OnNavigationItemSelectedListener() {

                    @Override
                    public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                        switch(item.getItemId()) {
                            case R.id.tab1:
                                Toast.makeText(getApplicationContext(), "First tab selected", Toast.LENGTH_LONG).show();
                                getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment1).commit();
                                return true;
                            case R.id.tab2:
                                Toast.makeText(getApplicationContext(), "Second tab selected", Toast.LENGTH_LONG).show();
                                getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment2).commit();
                                return true;
                            case R.id.tab3:
                                Toast.makeText(getApplicationContext(), "Third tab selected", Toast.LENGTH_LONG).show();
                                getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment3).commit();
                                return true;
                        }
                        return false;
                    }
                }
        );
    }
}
