/*
    GradeGUI.java

    실행하기 위해서는 Grade.java 파일도 필요합니다.

    142694 윤이삭
    학생들의 석차를 구하여 보여주는 GUI 프로그램
    점수가 같으면 순위도 같게 설정.
    예 : 80,95,95,87,70 → 석차 4,1,1,3,5

 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class GradeGUI extends JPanel {
    public static final int STUDENT_MAX = 5;                          // 최대 학생 수 (C언어로 치면 매크로 변수)
    private JLabel InputGuide, OutputGuide;                           // '성적 입력', '순위 출력' 텍스트 넣기
    private JLabel Create;                                            // 만든 사람 표시
    private JLabel HowTo;                                             // 설명 표시
    private JTextField InputScore[] = new JTextField[STUDENT_MAX];    // 성적 입력하는 칸
    private JTextField OutputGrade[] = new JTextField[STUDENT_MAX];   // 등수 출력하는 칸

    public GradeGUI()
    {
        InputGuide = new JLabel("학생들의 성적 입력 : ");
        OutputGuide = new JLabel("순위 : ");
        HowTo = new JLabel("점수 5개를 모두 입력 후 Enter를 눌러주세요");
        Create = new JLabel("만든이 : 142694 윤이삭");
        for(int i=0;i<STUDENT_MAX;i++)
        {
            InputScore[i] = new JTextField(7);
            OutputGrade[i] = new JTextField(7);
        }

        /* InputScore 텍스트필드에 리스너 추가 */
        for(int i=0; i<STUDENT_MAX; i++) {
            InputScore[i].addActionListener(new ScoreListener());
        }

        /* 구성 요소를 창에 넣기 */
        add(InputGuide);
        for(int i=0; i<STUDENT_MAX; i++) {
            add(InputScore[i]);
        }
        add(OutputGuide);
        for(int i=0; i<STUDENT_MAX; i++) {
            add(OutputGrade[i]);
        }
        add(HowTo);
        add(Create);

        /* 창 크기 설정 */
        setPreferredSize(new Dimension(550,100));

    }

    private class ScoreListener implements ActionListener {
        public void actionPerformed(ActionEvent event) {
            int[] score = new int[STUDENT_MAX];         // 학생 점수 저장
            int[] grade = new int[STUDENT_MAX];         // 학생 등수 저장
            String text[] = new String[5];

            for(int i=0; i<STUDENT_MAX; i++) {
                score[i] = 0;                           // 점수는 0점, 순위는 1로 초기화
                grade[i] = 1;
            }
            for(int i=0; i<STUDENT_MAX; i++) {
                text[i] = InputScore[i].getText();      // 입력한 학생 점수를 텍스트로 받기
                score[i] = Integer.parseInt(text[i]);   // String 타입의 점수를 Int로 변환하여 score 배열에 저장
            }

            /* 순위 매기는 반복문 */
            for(int i=0; i<STUDENT_MAX; i++) {
                for (int k = 0; k < STUDENT_MAX; k++) {
                    if (score[i] < score[k])
                        grade[i] += 1;
                }
            }

            for(int i=0; i<STUDENT_MAX; i++) {
                OutputGrade[i].setText(Integer.toString(grade[i]));     // 순위를 OutputGrade에 넣어 GUI에서 텍스트로 출력할 준비하기
            }



        }

    }


}
